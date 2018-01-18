#include "grimly.h"

static int		valid_tail(int n)
{
	int i;

	if (g_map[n][0] != g_tokens.full)
		return (0);
	i = 1;
	while (g_map[n][i])
	{
		if (!(g_map[n][i] == g_tokens.full || g_map[n][i] == g_tokens.entry ||
				g_map[n][i] == g_tokens.exit))
			return (0);
		if (i >= g_tokens.columns)
			return (0);
		i++;
	}
	if (g_map[n][i - 1] != g_tokens.full)
		return (0);
	return (1);
}

static int		valid_line_count(void)
{
	int			i;

	i = 0;
	while (g_map[i])
		i++;
	if (i != g_tokens.lines)
		return (0);
	return (1);
}

static void		add_entries_and_exits_on_first_and_last_lines(void)
{
	int l;
	int j;

	j = 0;
	l = g_tokens.lines - 1;
	while (j < g_tokens.columns)
	{
		if (g_map[0][j] == g_tokens.entry)
			add_link(&g_tokens.entries, create_link(int_pair(0, j)));
		if (g_map[0][j] == g_tokens.exit)
			add_link(&g_tokens.exits, create_link(int_pair(0, j)));
		j++;
	}
	j = 0;
	while (j < g_tokens.columns)
	{
		if (g_map[l][j] == g_tokens.entry)
			add_link(&g_tokens.entries, create_link(int_pair(l, j)));
		if (g_map[l][j] == g_tokens.exit)
			add_link(&g_tokens.exits, create_link(int_pair(l, j)));
		j++;
	}
}

static int		valid_entries_and_exits(void)
{
	int i;
	int j;

	g_tokens.entries = 0;
	g_tokens.exits = 0;
	j = g_tokens.columns - 1;
	add_entries_and_exits_on_first_and_last_lines();
	i = 1;
	while (i < g_tokens.lines - 1)
	{
		if (g_map[i][0] == g_tokens.entry)
			add_link(&g_tokens.entries, create_link(int_pair(i, 0)));
		if (g_map[i][j] == g_tokens.entry)
			add_link(&g_tokens.entries, create_link(int_pair(i, j)));
		if (g_map[i][0] == g_tokens.exit)
			add_link(&g_tokens.exits, create_link(int_pair(i, 0)));
		if (g_map[i][j] == g_tokens.exit)
			add_link(&g_tokens.exits, create_link(int_pair(i, j)));
		i++;
	}
	if (linked_list_size(g_tokens.entries) != 1)
		return (0);
	if (linked_list_size(g_tokens.exits) < 1)
		return (0);
	return (1);
}

int				valid_map(int i, int j, int lines)
{
	if (!valid_line_count() || !valid_tail(0) || !valid_tail(lines - 1))
		return (0);
	while (i < lines - 1)
	{
		if ((j = 0) && i >= lines)
			return (0);
		if (!(g_map[i][0] == g_tokens.full || g_map[i][0] == g_tokens.entry ||
				g_map[i][0] == g_tokens.exit))
			return (0);
		while (g_map[i][j + 1])
		{
			if (g_map[i][j] != g_tokens.full && g_map[i][j] != g_tokens.empty)
				return (0);
			if (j++ >= g_tokens.columns)
				return (0);
		}
		if (!(g_map[i][g_tokens.columns - 1] == g_tokens.full ||
				g_map[i][g_tokens.columns - 1] == g_tokens.entry ||
				g_map[i][g_tokens.columns - 1] == g_tokens.exit))
			return (0);
		i++;
	}
	if (!valid_entries_and_exits())
		return (0);
	return (1);
}
