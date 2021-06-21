/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <hekang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 11:17:01 by hekang            #+#    #+#             */
/*   Updated: 2021/06/21 15:10:54 by hekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		rrotate(t_node **stack)
{
	t_node	*tmp;
	t_node	*last;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	tmp = *stack;
	last = *stack;
	while (last->next)
        (last) = (last)->next;
	last->prev->next = NULL;
	last->next = tmp;
	tmp->prev = last;
	last->prev = NULL;
	*stack = last;
}