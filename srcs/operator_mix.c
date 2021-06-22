/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator_mix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <hekang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 17:08:32 by hekang            #+#    #+#             */
/*   Updated: 2021/06/22 20:47:05 by hekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		operator_pa(t_node **stack_a, t_node **stack_b)
{
	operator("pa", stack_a, stack_b, 1);
	return (1);
}

int		operator_pa_ra(t_node **stack_a, t_node **stack_b)
{
	operator("pa", stack_a, stack_b, 1);
	operator("ra", stack_a, stack_b, 1);
	return (1);
}

int		operator_pa_rrb(t_node **stack_a, t_node **stack_b)
{
	operator("pa", stack_a, stack_b, 1);
	operator("rrb", stack_a, stack_b, 1);
	return (1);
}

int		operator_pa_ra_rrb(t_node **stack_a, t_node **stack_b)
{
	operator("pa", stack_a, stack_b, 1);
	operator("ra", stack_a, stack_b, 1);
	operator("rrb", stack_a, stack_b, 1);
	return (1);
}

int		operator_return_false(char *op, t_node **stack_a, t_node **stack_b)
{
	operator(op, stack_a, stack_b, 1);
	return (0);
}
