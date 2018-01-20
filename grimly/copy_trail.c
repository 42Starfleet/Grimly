
#include "grimly.h"

void copy_trail(t_node *node)
{
	if (node->parent)
	{
			g_nodes[node->y][node->x] = node;
			copy_trail(node->parent);
	}
}
