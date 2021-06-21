/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <hekang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 10:57:25 by hekang            #+#    #+#             */
/*   Updated: 2021/06/21 15:11:05 by hekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		push(t_node **stack_first, t_node **stack_second)
{
	t_node	*tmp;

	if (*stack_first == NULL)
		return ;
	tmp = (*stack_first);
	*stack_first = (*stack_first)->next;
	if (*stack_first)
		(*stack_first)->prev = NULL;
	if (*stack_second)
		(*stack_second)->prev = tmp;
	tmp->next = *stack_second;
	*stack_second = tmp;
	(*stack_second)->prev = NULL;
}