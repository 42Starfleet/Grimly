#include "grimly.h"

int		*int_pair(int y, int x)
{
	int	*new;

	new = malloc(sizeof(int) * 2);
	new[0] = y;
	new[1] = x;
	return (new);
}
