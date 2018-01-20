#include "grimly.h"
#define ASSIGN g_be_int_y=g_tokens.lines;g_be_int_x=g_tokens.columns;
#define ASSIGN2 g_be_int_i=0; g_be_list=0;
#define CHECK if (g_map[g_be_int_i][g_be_int_j] == g_tokens.path CHECK2
#define CHECK2 && !node_is_in_list(g_be_list, g_be_exit_node)) CHECK3
#define CHECK3 add_link(&g_be_list, create_link(g_be_exit_node));
#define BREAK if (get_size(g_be_list) > 1) break ;

static void	slice_map_and_get_best_exit3(void)
{
	ASSIGN;
	while (g_be_int_x && g_be_int_y)
	{
		ASSIGN2;
		while (g_be_int_i < g_be_int_y)
		{
			g_be_int_j = 0;
			while (g_be_int_j < g_be_int_x)
			{
				g_be_exit_node = (g_nodes[g_be_int_i][g_be_int_j])->exit_node;
				CHECK;
				BREAK;
				g_be_int_j++;
			}
			if (get_size(g_be_list) > 1 && !(g_be_list = 0))
				break ;
			g_be_int_i++;
		}
		if (get_size(g_be_list) == 1)
			break ;
		g_be_int_x--;
		g_be_int_y--;
	}
	g_best_exit = g_be_list->data;
}

static void	slice_map_and_get_best_exit2(void)
{
	ASSIGN;
	while (g_be_int_x)
	{
		ASSIGN2;
		while (g_be_int_i < g_be_int_y)
		{
			g_be_int_j = 0;
			while (g_be_int_j < g_be_int_x)
			{
				g_be_exit_node = (g_nodes[g_be_int_i][g_be_int_j])->exit_node;
				CHECK;
				BREAK;
				g_be_int_j++;
			}
			if (get_size(g_be_list) > 1 && !(g_be_list = 0))
				break ;
			g_be_int_i++;
		}
		if (get_size(g_be_list) == 1)
			break ;
		g_be_int_x--;
	}
	if (g_be_list && (g_best_exit = g_be_list->data))
		return ;
	slice_map_and_get_best_exit3();
}

void		slice_map_and_get_best_exit(void)
{
	ASSIGN;
	while (g_be_int_y)
	{
		ASSIGN2;
		while (g_be_int_i < g_be_int_y)
		{
			g_be_int_j = 0;
			while (g_be_int_j < g_be_int_x)
			{
				g_be_exit_node = (g_nodes[g_be_int_i][g_be_int_j])->exit_node;
				CHECK;
				BREAK;
				g_be_int_j++;
			}
			if (get_size(g_be_list) > 1 && !(g_be_list = 0))
				break ;
			g_be_int_i++;
		}
		if (get_size(g_be_list) == 1)
			break ;
		g_be_int_y--;
	}
	if (g_be_list && (g_best_exit = g_be_list->data))
		return ;
	slice_map_and_get_best_exit2();
}
