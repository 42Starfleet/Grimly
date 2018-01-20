#include "grimly.h"

int			initialize_map(void)
{
	char	*line;
	int		i;

	i = 0;
	g_map = malloc(sizeof(char *) * g_tokens.lines + 1);
	g_map[g_tokens.lines] = 0;
	while (get_next_line(g_fd, &line))
	{
		g_map[i] = line;
		i++;
	}
	return (1);
}
