/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_create.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 07:55:39 by lilam             #+#    #+#             */
/*   Updated: 2018/01/18 10:53:59 by hiroshius        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grimly.h"

t_linked_list		*create_link(void *data)
{
	t_linked_list	*new;

	new = (t_linked_list *)malloc(sizeof(t_linked_list));
	new->data = data;
	new->next = 0;
	return (new);
}
