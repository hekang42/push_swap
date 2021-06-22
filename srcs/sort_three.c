/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <hekang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 13:50:15 by hekang            #+#    #+#             */
/*   Updated: 2021/06/22 17:27:49 by hekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_node **stack_a, t_node **stack_b)
{
	if ((*stack_a)->content > (*stack_a)->next->content &&
		(*stack_a)->content > (*stack_a)->next->next->content)
		if ((*stack_a)->next->content > (*stack_a)->next->next->content)
		{
			operator("sa", stack_a, stack_b);
			operator("rra", stack_a, stack_b);
		}
		else
			operator("ra", stack_a, stack_b);
	else if ((*stack_a)->next->content > (*stack_a)->content &&
		(*stack_a)->next->content > (*stack_a)->next->next->content)
		if ((*stack_a)->content > (*stack_a)->next->next->content)
			operator("rra", stack_a, stack_b);
		else
		{
			operator("sa", stack_a, stack_b);
			operator("ra", stack_a, stack_b);
		}
	else
	{
		if ((*stack_a)->content > (*stack_a)->next->content)
			operator("sa", stack_a, stack_b);
		else
			return ;
	}
}
