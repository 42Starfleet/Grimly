#include "grimly.h"

int					node_is_in_list(t_linked_list *list, t_node *node)
{
	t_linked_list	*iter;

	iter = list;
	if (!iter)
		return (0);
	while (iter)
	{
		if (iter->data == node)
			return (1);
		iter = iter->next;
	}
	return (0);
}

