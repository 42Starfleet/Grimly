#include "grimly.h"


static void		print_attributes(t_node *g_node)
{
	printf("\n");
	printf("***NODE:***\n");
	printf("Y: %d\n", g_node->y);
	printf("X: %d\n", g_node->x);
	printf("G: %d\n", g_node->G);
	printf("H: %d\n", g_node->H);
	printf("F: %d\n", g_node->F);
	printf("OPEN: %d\n", g_node->open);
	printf("PARENT: %d\n", (int)g_node->parent);
}

static void		initialize_nodes(int *exit)
{
	int i;
	int j;

	i = 0;
	j = 0;
	g_nodes = malloc(sizeof(t_node *) * (g_tokens.lines + 1));
	g_nodes[g_tokens.lines] = 0;
	while (i < g_tokens.lines)
	{
		j = 0;
		g_nodes[i] = malloc(sizeof(t_node *) * (g_tokens.columns + 1));
		g_nodes[g_tokens.columns] = 0;
		while (j < g_tokens.columns)
		{
			g_nodes[i][j] = (t_node *)malloc(sizeof(t_node));
			(g_nodes[i][j])->y = i;
			(g_nodes[i][j])->x = j;
			(g_nodes[i][j])->G = -1;
			(g_nodes[i][j])->H = calculate_distance_cost(i, j, exit[0], exit[1]);
			(g_nodes[i][j])->F = -1;
			(g_nodes[i][j])->open = 1;
			(g_nodes[i][j])->parent = 0;
			print_attributes(g_nodes[i][j]);
			j++;
		}
		i++;
	}
}

void solve_map(void)
{
	initialize_nodes(g_tokens.exits->data);
}
