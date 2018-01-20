#include "grimly.h"
#define BREAK if (argc == 1) break ;

int main(int argc, char **argv)
{
	int i;

	i = 1;
	while (i < argc || argc == 1)
	{
		g_fd = (argc == 1) ? 0 : open(argv[i], O_RDONLY);
		reset_variables();
		if (get_next_line(g_fd, &g_legend) > 0 && valid_legend(g_legend) &&
				tokenize_legend(g_legend) && initialize_map())
		{
			if (valid_map(0, 0))
			{
				solve_map();
				if (g_solved)
					print_result();
				else
					ft_putstr("MAP ERROR\n");
			}
			else
				ft_putstr("MAP ERROR\n");
		}
		else
			ft_putstr("MAP ERROR\n");
		BREAK;
		i++;
	}
}
