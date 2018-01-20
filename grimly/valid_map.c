#include "grimly.h"

int				valid_map(int i, int j)
{
	while (g_map[i])
	{
		if (i >= g_tokens.lines)
			return (0);
		j = 0;
		while (g_map[i][j])
		{
			if (j >= g_tokens.columns)
				return (0);
			if (!(g_map[i][j] == g_tokens.full || g_map[i][j] == g_tokens.empty
					   || g_map[i][j] == g_tokens.entry ||
					   g_map[i][j] == g_tokens.exit))
				return (0);
			if (g_map[i][j] == g_tokens.entry)
				add_link(&g_tokens.entries, create_link(int_pair(i, j)));
			if (g_map[i][j] == g_tokens.exit)
				add_link(&g_tokens.exits, create_link(int_pair(i, j)));
			j++;
		}
		i++;
	}
	if (get_size(g_tokens.entries) != 1 || get_size(g_tokens.exits) < 1)
		return (0);
	return (1);
}
