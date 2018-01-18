#include "grimly.h"

int main(int argc, char **argv)
{
	int fd;
	int i;
	char *legend;
	char **map;
	char **tokens;

	i = 1;
	while (i < argc || argc == 1)
	{
		if (argc == 1)
			fd = 0;
		else
			fd = open(argv[i], O_RDONLY);
		if (get_next_line(fd, &legend) > 0 && valid_legend(legend))
		{
//			tokens = tokenize_legend(legend);
//			initialize_map(fd, &map, tokens);
//			if (valid_map(map, tokens))
//			{
//				solve_map(&map);
//				print_map(map);
//			}
//			else
//				ft_putstr("MAP ERROR\n");
		}
		else
			ft_putstr("MAP ERROR\n");
		if (argc == 1 || i++)
			break ;
	}
}
