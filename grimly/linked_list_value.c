/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_value.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 08:04:01 by lilam             #+#    #+#             */
/*   Updated: 2018/01/18 10:58:29 by hiroshius        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grimly.h"

void				*value(t_linked_list *list, int n)
{
	t_linked_list	*iter;

	iter = list;
	while (n-- && iter->next)
		iter = iter->next;
	return (iter->data);
}
