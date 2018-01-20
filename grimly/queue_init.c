#include "grimly.h"

t_queue		*init(void)
{
	t_queue	*queue;

	queue = malloc(sizeof(struct s_queue));
	queue->first = 0;
	queue->last = 0;
	return queue;
}
