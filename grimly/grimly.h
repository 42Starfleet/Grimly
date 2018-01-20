#ifndef GRIMLY_H
# define GRIMLY_H

# include "get_next_line.h"
# include <fcntl.h>
# include <stdio.h>

typedef struct				s_linked_list
{
	void					*data;
	struct s_linked_list	*next;
}							t_linked_list;

typedef struct				s_legend
{
	int						lines;
	int						columns;
	char					full;
	char					empty;
	char					path;
	char					entry;
	char					exit;
	t_linked_list			*entries;
	t_linked_list			*exits;
}							t_legend;

typedef struct				s_node
{
	int						y;
	int						x;
	int						G;
	int						H;
	int						F;
	int						open;
	struct s_node			*parent;
	struct s_node			*exit_node;
}							t_node;

int							tokenize_legend(char *legend);
int							valid_legend(char *legend);
int							valid_map(int i, int j);
int							initialize_map(void);
int							get_size(t_linked_list *list);
void						add_link(t_linked_list **list, void *data);
t_linked_list				*create_link(void *data);
void						prepend_link(t_linked_list **list, void *data);
void						print_linked_list(t_linked_list *list);
int							linked_list_size(t_linked_list *list);
void						*value(t_linked_list *list, int n);
int							*int_pair(int y, int x);
void						solve_map(void);
int							get_distance_cost(int y1, int x1, int y2, int x2);
int							is_full_character(int y, int x);
void						A_star();
void						print_map(void);
int							trace_path(t_node *node, int do_trace, int first_run);
void						print_result(void);
void						set_exit_node_trail(t_node *node, t_node *exit_node);
void						copy_trail(t_node *node);
void						slice_map_and_get_best_exit(void);
int							node_is_in_list(t_linked_list *list, t_node *node);


char *g_legend;
char **g_map;

int g_fd;
int g_steps;
int g_bounded_min_y;
int g_bounded_min_x;
int g_bounded_max_y;
int g_bounded_max_x;
t_legend g_tokens;
t_node	***g_nodes;
t_node	*smallest_F_node;
t_linked_list *solutions;
t_linked_list *equal_solutions;
int solved;
int z;

int g_be_int_y;
int g_be_int_x;
int g_be_int_i;
int g_be_int_j;
t_linked_list *g_be_list;
t_node *g_be_exit_node;
t_node *g_best_exit;
#endif
