#include "grimly.h"

int		get_distance_cost(int y1, int x1, int y2, int x2)
{
	int y_cost;
	int x_cost;

	y_cost = y2 - y1;
	if (y_cost < 0)
		y_cost = -y_cost;
	x_cost = x2 - x1;
	if (x_cost < 0)
		x_cost = -x_cost;
	return (x_cost + y_cost);
}
