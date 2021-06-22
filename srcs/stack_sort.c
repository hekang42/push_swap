/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <hekang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 10:34:23 by hekang            #+#    #+#             */
/*   Updated: 2021/06/22 17:29:12 by hekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		stack_sort(t_node *stack_a, t_node *stack_b)
{
	int		size;

	put_index(stack_a);
	size = ft_ssize(stack_a);
	if (size == 1)
	{
		clear_stack(&stack_a);
		return ;
	}
	else if (size == 2 && (stack_a->content > stack_a->next->content))
		operator("sa", &stack_a, &stack_b);
	else if (size == 3)
		sort_three(&stack_a, &stack_b);
	else if (size == 5)
		sort_five(&stack_a, &stack_b);
	else
		sort(&stack_a, &stack_b);
}
