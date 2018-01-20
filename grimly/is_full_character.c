#include "grimly.h"

int is_full_character(int y, int x)
{
	if (g_map[y][x] == g_tokens.full)
		return (1);
	return (0);
}
