#include "grimly.h"

void				enqueue(t_queue *queue, void *content)
{
	t_queue_node	*node;
	t_queue_node	*iter;

	node = malloc(sizeof(t_queue_node));
	node->content = content;
	node->next = 0;
	if (is_empty(queue))
	{
		queue->first = node;
		queue->last = node;
	}
	else
	{
		iter = queue->first;
		while (iter->next)
			iter = iter->next;
		iter->next = node;
		queue->last = node;
	}
}
