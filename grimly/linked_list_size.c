/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_size.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 08:01:36 by lilam             #+#    #+#             */
/*   Updated: 2018/01/18 10:54:03 by hiroshius        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grimly.h"

int				linked_list_size(t_linked_list *list)
{
	t_linked_list		*iter;
	int			i;

	iter = list;
	i = 0;
	while (iter)
	{
		iter = iter->next;
		i++;
	}
	return (i);
}
