/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <hekang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 15:22:30 by hekang            #+#    #+#             */
/*   Updated: 2021/06/21 18:06:46 by hekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		sort_five(t_node **stack_a, t_node **stack_b)
{
	/*
	insert index 
	*/

	t_node	*cur;
	int		cnt;
	
	cur = *stack_a;
	cnt = 0;
	while (cnt < 2)
	{
		if ((*stack_a)->index >= 3)
		{
			operator("pb", stack_a, stack_b);
			cnt++;
		}
		else
			operator("ra", stack_a, stack_b);
	}
	sort_three(stack_a, stack_b);
	cur = *stack_b;
	if (cur->index == 3)
		operator("sb", stack_a, stack_b);
	operator("pa", stack_a, stack_b);
	operator("pa", stack_a, stack_b);
	operator("ra", stack_a, stack_b);
	operator("ra", stack_a, stack_b);
}