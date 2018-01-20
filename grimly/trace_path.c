#include "grimly.h"

int	trace_path(t_node *node, int do_trace, int first_run)
{
	if (node->parent)
	{
		if (!first_run && do_trace)
			g_map[node->y][node->x] = g_tokens.path;
		if (node->parent->parent)
			return (1 + trace_path(node->parent, do_trace, 0));
	}
	return (0);
}

