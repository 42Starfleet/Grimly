#include "grimly.h"

int	is_empty(t_queue *queue)
{
	if (!queue->first && !queue->last)
		return 1;
	return 0;
}
