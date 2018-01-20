#include "grimly.h"

void print_result(void)
{
	ft_putstr(ft_strjoin(g_legend, "\n"));
	print_map();
	ft_putstr(ft_strjoin("RESULT IN ", ft_itoa(g_steps)));
	ft_putstr(" STEPS!\n");
}
