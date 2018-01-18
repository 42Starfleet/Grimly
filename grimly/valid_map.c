#include "grimly.h"

static int		valid_first_line(void)
{
	int i;

	if (g_map[0][0] != g_tokens.full)
		return (0);
	i = 1;
	while (g_map[0][i])
	{
		if (!(g_map[0][i] == g_tokens.full || g_map[0][i] == g_tokens.entry ||
				g_map[0][i] == g_tokens.exit))
			return (0);
		if (i >= g_tokens.columns)
			return (0);
		i++;
	}
	if (g_map[0][i - 1] != g_tokens.full)
		return (0);
	return (1);
}

static int		valid_last_line(void)
{
	int			i;
	int			l;

	l = g_tokens.lines - 1;
	if (g_map[l][0] != g_tokens.full)
		return (0);
	i = 1;
	while (g_map[l][i])
	{
		if (!(g_map[l][i] == g_tokens.full || g_map[l][i] == g_tokens.entry ||
				g_map[l][i] == g_tokens.exit))
			return (0);
		if (i >= g_tokens.columns)
			return (0);
		i++;
	}
	if (g_map[l][i - 1] != g_tokens.full)
		return (0);
	return (1);
}

static int		valid_line_count(void)
{
	int			i;

	while (g_map[i])
		i++;
	if (i != g_tokens.lines)
		return (0);
	return (0);
}

static int		valid_entries_and_exits(void)
{
	return (1);
}

int				valid_map(void, int i, int j)
{
	if (!valid_first_line() || valid_line_count() || !valid_last_line())
		return (0);
	i = 1;
	while (i < g_tokens.lines - 1)
	{
		j = 1;
		if (i >= g_tokens.lines)
			return (0);
		if (g_map[i][0] != g_tokens.full)
			return (0);
		while (g_map[i][j])
		{
			if (!(g_map[i][j] == g_tokens.full || g_map[i][j] == g_tokens.empty))
				return (0);
			if (j++ >= g_tokens.columns)
				return (0);
		}
		if (g_map[i][g_tokens.columns - 1] != g_tokens.full)
			return (0);
		i++;
	}
	if (!valid_entries_and_exits())
		return (0);
	return (1);
}
