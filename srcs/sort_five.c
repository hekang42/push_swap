/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <hekang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 15:22:30 by hekang            #+#    #+#             */
/*   Updated: 2021/06/21 16:09:22 by hekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int				calc_index(int n, t_node *stack)
{
	int			index;

	index = 0;
	while (stack)
	{
		if (n > stack->content)
			index++;
		stack = stack->next;
	}
	return (index);
}

void		put_index(t_node *stack)
{
	t_node		*cur;
	cur = stack;
	while (cur)
	{
		cur->index = calc_index(cur->content, stack);
		cur = cur->next;
	}
}


void		sort_five(t_node **stack_a, t_node **stack_b)
{
	/*
	insert index 
	*/

	t_node	*cur;
	int		cnt;
	
	put_index(*stack_a);
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