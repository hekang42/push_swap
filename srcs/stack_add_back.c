/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_add_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <hekang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 10:13:40 by hekang            #+#    #+#             */
/*   Updated: 2021/06/21 14:07:41 by hekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_add_back(t_node **lst, t_node *new_list)
{
	t_node	*tmp;

	tmp = *lst;
	if (*lst == NULL)
	{
		*lst = new_list;
		return ;
	}
    while ((*lst)->next)
        (*lst) = (*lst)->next;
	(*lst)->next = new_list;
	new_list->prev = *lst;
	*lst = tmp;

}