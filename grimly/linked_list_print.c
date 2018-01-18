/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_print.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 08:00:42 by lilam             #+#    #+#             */
/*   Updated: 2018/01/18 10:54:02 by hiroshius        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grimly.h"

void	print_linked_list(t_linked_list *list)
{
	while (list)
	{
		ft_putstr((char *)list->data);
		ft_putstr("\n");
		list = list->next;
	}
}
