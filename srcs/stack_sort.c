/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <hekang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 10:34:23 by hekang            #+#    #+#             */
/*   Updated: 2021/06/21 15:09:44 by hekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		stack_sort(t_node *stack_a, t_node *stack_b)
{
	int		size;

	size = ft_stacksize(stack_a);
	if (size == 1)
	{
		clear_stack(&stack_a);
		return ;
	}
	if (size == 2 && (stack_a->content > stack_a->next->content))
		operator("sa", &stack_a, &stack_b);
	if (size == 3)
		sort_three(&stack_a, &stack_b);

	printf("%d \n", stack_a->content);
	printf("%d \n", stack_a->next->content);
	printf("%d\n", stack_a->next->next->content);
	printf("end _sort\n");
}