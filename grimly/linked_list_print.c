/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_print.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 08:00:42 by lilam             #+#    #+#             */
/*   Updated: 2018/01/18 13:39:15 by hiroshius        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grimly.h"

void	print_linked_list(t_linked_list *list)
{
	while (list)
	{
		printf("%d, %d\n", ((int *)list->data)[0], ((int *)list->data)[1]);
		list = list->next;
	}
}
