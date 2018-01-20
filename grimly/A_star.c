#include "grimly.h"

void	recalculate_node_and_set_parent(int y, int x, int G, t_node *parent)
{
	t_node *node;

	node = g_nodes[y][x];
	if (node->y < g_bounded_min_y)
		g_bounded_min_y = node->y;
	if (node->y > g_bounded_max_y)
		g_bounded_max_y = node->y;
	if (node->x < g_bounded_min_x)
		g_bounded_min_x = node->x;
	if (node->x > g_bounded_max_x)
		g_bounded_max_x = node->x;
	node->G = G;
	node->F = G + node->H;
	node->parent = parent;
}

void	run_through_open_adjacent_nodes(int y, int x)
{
	t_node *current;
	t_node *possible;

	current = g_nodes[y][x];
	if (y - 1 >= 0 && (possible = g_nodes[y - 1][x]) &&
			possible->open && possible->F >= 0 && current->G + 1 < possible->G)
		recalculate_node_and_set_parent(y - 1, x, current->G + 1, current);
	if (x - 1 >= 0 && (possible = g_nodes[y][x - 1]) &&
			possible->open && possible->F >= 0 && current->G + 1 < possible->G)
		recalculate_node_and_set_parent(y, x - 1, current->G + 1, current);
	if (x + 1 < g_tokens.columns && (possible = g_nodes[y][x + 1]) &&
			possible->open && possible->F >= 0 && current->G + 1 < possible->G)
		recalculate_node_and_set_parent(y, x + 1, current->G + 1, current);
	if (y + 1 < g_tokens.lines && (possible = g_nodes[y + 1][x]) &&
			possible->open && possible->F >= 0 && current->G + 1 < possible->G)
		recalculate_node_and_set_parent(y + 1, x, current->G + 1, current);
}

void	run_through_open_untouched_nodes(int y, int x)
{
	t_node *current;
	t_node *possible;

	current = g_nodes[y][x];
	if (y - 1 >= 0 && (possible = g_nodes[y - 1][x]) &&
			possible->open && possible->F == -1)
		recalculate_node_and_set_parent(y - 1, x, current->G + 1, current);
	if (x - 1 >= 0 && (possible = g_nodes[y][x - 1]) &&
			possible->open && possible->F == -1)
		recalculate_node_and_set_parent(y, x - 1, current->G + 1, current);
	if (x + 1 < g_tokens.columns && (possible = g_nodes[y][x + 1]) &&
			possible->open && possible->F == -1)
		recalculate_node_and_set_parent(y, x + 1, current->G + 1, current);
	if (y + 1 < g_tokens.lines && (possible = g_nodes[y + 1][x]) &&
			possible->open && possible->F == -1)
		recalculate_node_and_set_parent(y + 1, x, current->G + 1, current);
}

t_node	*scan_map_and_get_smallest_F_node(void)
{
	int i;
	int j;
	int first_run;
	t_node *node;

	first_run = 1;
	smallest_F_node = 0;
	i = g_bounded_min_y;
	while (i <= g_bounded_max_y)
	{
		j = g_bounded_min_x;
		while (j <= g_bounded_max_x)
		{
			node = g_nodes[i][j];
			if (first_run && node->open && node->F >= 0 && !(first_run = 0))
				smallest_F_node = node;
			else if (node->open && node->F >= 0 && node->F < smallest_F_node->F)
				smallest_F_node = node;
			j++;
		}
		i++;
	}
	return (smallest_F_node);
}

void	A_star(int y, int x, int G, t_node *exit)
{
	t_node *node;
	t_node *next;

	node = g_nodes[y][x];
	if (node->y == exit->y && node->x == exit->x)
	{
		solved = 1;
		return ;
	}
	node->open = 0;
	node->G = G;
	node->F = node->G + node->H;
	run_through_open_adjacent_nodes(y, x);
	run_through_open_untouched_nodes(y, x);
	next = scan_map_and_get_smallest_F_node();
	if (next)
		A_star(next->y, next->x, next->G, exit);
}
