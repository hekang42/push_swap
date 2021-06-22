/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <hekang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 10:46:49 by hekang            #+#    #+#             */
/*   Updated: 2021/06/22 11:29:44 by hekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	operator(char *op, t_node **stack_a, t_node **stack_b)
{
	int	len;

	ft_putstr_fd(op, 1);
	write(1, "\n", 1);
	len = ft_strlen(op);
	if (!ft_strncmp(op, "sa", len) || !ft_strncmp(op, "ss", len))
		swap(stack_a);
	if (!ft_strncmp(op, "sb", len) || !ft_strncmp(op, "ss", len))
		swap(stack_b);
	if (!ft_strncmp(op, "pa", len))
		push(stack_b, stack_a);
	if (!ft_strncmp(op, "pb", len))
		push(stack_a, stack_b);
	if (!ft_strncmp(op, "ra", len) || !ft_strncmp(op, "rr", len))
		rotate(stack_a);
	if (!ft_strncmp(op, "rb", len) || !ft_strncmp(op, "rr", len))
		rotate(stack_b);
	if (!ft_strncmp(op, "rra", len) || !ft_strncmp(op, "rrr", len))
		rrotate(stack_a);
	if (!ft_strncmp(op, "rrb", len) || !ft_strncmp(op, "rrr", len))
		rrotate(stack_b);
}