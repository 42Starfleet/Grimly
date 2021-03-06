/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_prepend.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 07:59:11 by lilam             #+#    #+#             */
/*   Updated: 2018/01/18 15:19:24 by hiroshius        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grimly.h"

void	prepend_link(t_linked_list **list, void *data)
{
	t_linked_list *old;
	t_linked_list *new;

	old = (*list);
	new = data;
	new->next = old;
	*list = new;
}
