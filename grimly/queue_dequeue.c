#include "grimly.h"

void				*dequeue(t_queue *queue)
{
	t_queue_node	*iter;

	if (is_empty(queue))
		return 0;
	iter = queue->first;
	if (!iter->next)
	{
		queue->first = 0;
		queue->last = 0;
		return iter;
	}
	while (iter->next->next)
		iter = iter->next;
	queue->last = iter;
	iter++;
	queue->last->next = 0;
	return (iter);
}
