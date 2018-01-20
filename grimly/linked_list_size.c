/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_size.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 08:01:36 by lilam             #+#    #+#             */
/*   Updated: 2018/01/19 15:33:31 by hiroshius        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grimly.h"

int						get_size(t_linked_list *list)
{
	t_linked_list		*iter;
	int					i;

	iter = list;
	i = 0;
	while (iter)
	{
		iter = iter->next;
		i++;
	}
	return (i);
}
