#include "grimly.h"

void set_exit_node_trail(t_node *node, t_node *exit_node)
{
	if (node->parent)
	{
		node->exit_node = exit_node;
		set_exit_node_trail(node->parent, exit_node);
	}
}
