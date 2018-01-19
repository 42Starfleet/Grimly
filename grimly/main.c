#include "grimly.h"

int main(int argc, char **argv)
{
	int i;

	i = 1;
	while (i < argc || argc == 1)
	{
		if (argc == 1)
			g_fd = 0;
		else
			g_fd = open(argv[i], O_RDONLY);
		if (get_next_line(g_fd, &g_legend) > 0 && valid_legend(g_legend))
		{
			tokenize_legend(g_legend);
			initialize_map();
			if (valid_map(1, 1, g_tokens.lines))
			{
				printf("MAP IS VALID\n");
				solve_map(&g_map);
//				print_map(g_map);
			}
			else
				ft_putstr("MAP ERROR\n");
		}
		else
			ft_putstr("MAP ERROR\n");
		if (argc == 1 || i++)
			break ;
	}
}
