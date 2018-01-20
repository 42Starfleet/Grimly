/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_add.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 07:53:48 by lilam             #+#    #+#             */
/*   Updated: 2018/01/18 15:51:09 by hiroshius        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grimly.h"

void	add_link(t_linked_list **list, void *data)
{
	t_linked_list *iter;

	if (!*list)
	{
		(*list) = data;
		(*list)->next = 0;
		return ;
	}
	iter = (*list);
	while (iter->next)
		iter = iter->next;
	iter->next = data;
}
