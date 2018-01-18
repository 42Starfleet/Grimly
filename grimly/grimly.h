#ifndef GRIMLY_H
# define GRIMLY_H

# include "get_next_line.h"
# include <fcntl.h>
# include <stdio.h>

typedef struct	s_legend
{
	int			lines;
	int			columns;
	char		full;
	char		empty;
	char		path;
	char		entry;
	char		exit;
}				t_legend;

void tokenize_legend(char *legend);
int valid_legend(char *legend);
int valid_map(void);
void	initialize_map(void);

char *g_legend;
char **g_map;
int g_fd;
t_legend g_tokens;
#endif
