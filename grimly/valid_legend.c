#include "grimly.h"

static int	find_x(char *legend)
{
	int		i;

	i = 0;
	while (legend[i] && legend[i] != 'x')
		i++;
	return (i);
}

static int	there_is_only_a_number_before_x(char *legend)
{
	int		i;
	int		there_is_a_number;

	there_is_a_number = 0;
	while (legend[i] && legend[i] != 'x')
	{
		if (!('0' <= legend[i] && legend[i] <= '9'))
			return (0);
		there_is_a_number = 1;
		i++;
	}
	if (!there_is_a_number)
		return (0);
	if (legend[i] == 'x')
		return (1);
	return (0);
}

static int	valid_5_characters(char *legend)
{
	int		character_array[128];
	int		i;

	i = 0;
	while (i < 128)
	{
		character_array[i] = 0;
		i++;
	}
	if (ft_strlen(legend) != 5)
		return (0);
	while (*legend)
	{
		character_array[(int)*legend]++;
		legend++;
	}
	i = 0;
	while (i < 128)
	{
		if (character_array[i] != 0 && character_array[i] != 1)
			return (0);
		i++;
	}
	return (1);
}

int			valid_legend(char *legend)
{
	int		i;
	int		j;
	char	temp;

	if (!there_is_only_a_number_before_x(legend))
		return (0);
	i = find_x(legend);
	legend[i] = '\0';
	if (ft_atoi(&legend[0]) < 3)
		return (0);
	legend[i] = 'x';
	i++;
	j = i;
	while (legend[j] && '0' <= legend[j] && legend[j] <= '9')
		j++;
	if (!legend[j])
		return (0);
	temp = legend[j];
	legend[j] = '\0';
	if (ft_atoi(&legend[i]) < 3)
		return (0);
	legend[j] = temp;
	if (!valid_5_characters(&legend[j]))
		return (0);
	return (1);
}
