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
	t_linked_list			*entry_info;
	t_linked_list			*exits;
}							t_legend;

void						tokenize_legend(char *legend);
int							valid_legend(char *legend);
int							valid_map(int i, int j);
void						initialize_map(void);
int							linked_list_size(t_linked_list *list);
void						add_link(t_linked_list **list, void *data);
t_linked_list				*create_link(void *data);
void						prepend_link(t_linked_list **list, void *data);
void						print_linked_list(t_linked_list *list);
int							linked_list_size(t_linked_list *list);
void						*value(t_linked_list *list, int n);
int							*int_pair(int y, int x);

char *g_legend;
char **g_map;
int g_fd;
t_legend g_tokens;
#endif
