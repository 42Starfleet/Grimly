#include "grimly.h"

static void	tokenize_letters(char *letters)
{
	g_tokens.empty = letters[0];
	g_tokens.path = letters[1];
	g_tokens.entry = letters[2];
	g_tokens.exit = letters[3];
}

int		tokenize_legend(char *legend)
{
	char	*iter;
	int		i;

	legend = ft_strdup(legend);
	i = 0;
	while (legend[i] != 'x')
		i++;
	legend[i] = '\0';
	g_tokens.lines = ft_atoi(legend);
	iter = legend;
	while (*iter)
		iter++;
	iter++;
	i++;
	while ('0' <= legend[i] && legend[i] <= '9')
		i++;
	g_tokens.full = legend[i];
	legend[i] = '\0';
	g_tokens.columns = ft_atoi(iter);
	while (*iter)
		iter++;
	iter++;
	tokenize_letters(iter);
	return (1);
}
