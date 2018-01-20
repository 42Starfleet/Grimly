#include "grimly.h"

static void		initialize_nodes(int *exit)
{
	int i;
	int j;

	i = 0;
	j = 0;
	g_nodes = malloc(sizeof(t_node ***) * (g_tokens.lines + 1));
	g_nodes[g_tokens.lines] = 0;
	while (i < g_tokens.lines)
	{
		j = 0;
		g_nodes[i] = malloc(sizeof(t_node **) * (g_tokens.columns + 1));
		while (j < g_tokens.columns)
		{
			g_nodes[i][j] = (t_node *)malloc(sizeof(t_node));
			(g_nodes[i][j])->y = i;
			(g_nodes[i][j])->x = j;
			(g_nodes[i][j])->G = -1;
			(g_nodes[i][j])->H = get_distance_cost(i, j, exit[0], exit[1]);
			(g_nodes[i][j])->F = -1;
			(g_nodes[i][j])->open = !is_full_character(i, j);
			(g_nodes[i][j])->exit_node = 0;
			(g_nodes[i][j])->parent = 0;
			j++;
		}
		i++;
	}
	g_nodes[((int *)g_tokens.entries->data)[0]]
		[((int *)g_tokens.entries->data)[1]]->G = 0;
}


void print_map(void)
{
	int i;

	i = 0;
	while (i < g_tokens.lines)
	{
		ft_putstr(g_map[i]);
		ft_putstr("\n");
		i++;
	}
}

void insert_solution(t_node *node)
{
	int iter_steps;
	t_linked_list *iter;

	iter = solutions;
	g_steps = trace_path(node, 0, 1);
	iter_steps = g_steps;
	if (get_size(solutions) == 0)
	{
		add_link(&solutions, create_link(node));
		return ;
	}
	while (iter)
	{
		iter_steps = trace_path(iter->data, 0, 1);
		if (iter_steps < g_steps)
			g_steps = iter_steps;
		iter = iter->next;
	}
	add_link(&solutions, create_link(node));
}

void prune_for_equal_solutions(void)
{
	t_linked_list *iter;

	iter = solutions;
	while (iter)
	{
		if (trace_path(iter->data, 0, 1) == g_steps)
			add_link(&equal_solutions, create_link(iter->data));
		iter = iter->next;
	}
}


void print_node(t_node *node)
{
	printf("Y: %d\n", node->y);
	printf("X: %d\n", node->x);
	printf("PARENT: %d\n", node->parent);
	printf("EXIT NODE: %d\n", node->exit_node);
}


void prune_for_upmost_leftmost_solution(void)
{
	t_linked_list *iter;
	t_linked_list *iter2;
	t_node *node_iter;

	if (get_size(equal_solutions) == 1)
	{
		trace_path(equal_solutions->data, 1, 1);
		return ;
	}
	iter = equal_solutions;
	iter2 = equal_solutions;
	while (iter)
	{
		copy_trail(iter->data);
		node_iter = ((t_node *)iter->data)->parent;
		while (node_iter->parent)
		{
			g_map[node_iter->y][node_iter->x] = g_tokens.path;
			node_iter = node_iter->parent;
		}
		iter = iter->next;
	}
	print_map();
	iter = equal_solutions;
	t_node *node_iter2;
	while (iter)
	{
		iter2 = equal_solutions;
		while (iter2)
		{
			node_iter = iter->data;
			node_iter2 = iter2->data;
			if (iter != iter2)
			{
				while (node_iter->parent)
				{
					if (node_iter->y == node_iter2->y && node_iter->x == node_iter2->x)
						g_map[node_iter->y][node_iter->x] = g_tokens.empty;
					node_iter = node_iter->parent;
					node_iter2 = node_iter2->parent;
				}
			}
			iter2 = iter2->next;
		}
		iter = iter->next;
	}
	slice_map_and_get_best_exit();
	int y = 0;
	int x;
	while (y < g_tokens.lines)
	{
		x = 0;
		while (x < g_tokens.columns)
		{
			if (g_map[y][x] == g_tokens.path)
				g_map[y][x] = g_tokens.empty;
			x++;
		}
		y++;
	}
	trace_path(g_best_exit, 1, 1);
}

void solve_map(void)
{
	t_node *entry;
	t_node *exit;
	void *entry_info;
	void *exit_info;

	while (g_tokens.exits && (exit_info = g_tokens.exits->data))
	{
		initialize_nodes(exit_info);
		entry_info = g_tokens.entries->data;
		entry = g_nodes[((int *)entry_info)[0]][((int *)entry_info)[1]];
		g_bounded_min_y = entry->y;
		g_bounded_min_x = entry->x;
		g_bounded_max_y = entry->y;
		g_bounded_max_x = entry->x;
		exit = g_nodes[((int *)exit_info)[0]][((int *)exit_info)[1]];
		solved = 0;
		A_star(entry->y, entry->x, 0, exit);
		if (solved)
		{
			insert_solution(exit);
			set_exit_node_trail(exit, exit);
		}
		g_tokens.exits = g_tokens.exits->next;
	}
	prune_for_equal_solutions();
	prune_for_upmost_leftmost_solution();
}
