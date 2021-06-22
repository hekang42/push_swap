/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <hekang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 11:11:03 by hekang            #+#    #+#             */
/*   Updated: 2021/06/22 17:23:05 by hekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		rotate(t_node **stack)
{
	t_node	*tmp;
	t_node	*last;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	tmp->next = NULL;
	last = *stack;
	while ((last)->next)
		last = (last)->next;
	tmp->prev = last;
	tmp->prev->next = tmp;
}
