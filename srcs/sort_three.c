/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <hekang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 13:50:15 by hekang            #+#    #+#             */
/*   Updated: 2021/06/21 15:10:43 by hekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* 
	3 2 1
	3 1 2
	2 3 1
	1 3 2
	2 1 3
	1 2 3
*/

void	sort_three(t_node **stack_a, t_node **stack_b)
{
	// printf("%d %d %d\n", (*stack_a)->content, (*stack_a)->next->content, (*stack_a)->next->next->content);
	
	if ((*stack_a)->content > (*stack_a)->next->content &&
		(*stack_a)->content > (*stack_a)->next->next->content)
		if ((*stack_a)->next->content > (*stack_a)->next->next->content)
		{
			operator("sa",stack_a, stack_b);
			operator("rra",stack_a, stack_b);
		}
		else
			operator("ra",stack_a, stack_b);
	else if ((*stack_a)->next->content > (*stack_a)->content &&
		(*stack_a)->next->content > (*stack_a)->next->next->content)
		if ((*stack_a)->content > (*stack_a)->next->next->content)
			operator("rra",stack_a, stack_b);
		else
		{
			operator("sa",stack_a, stack_b);
			operator("ra",stack_a, stack_b);
		}
	else
		if ((*stack_a)->content > (*stack_a)->next->content)
			operator("sa",stack_a, stack_b);
		else
			return ;
	// // printf("12122\n");
	// printf("%d \n", (*stack_a)->content);
	// printf("%d \n", (*stack_a)->next->content);
	// printf("%d\n", (*stack_a)->next->next->content);
	// printf("%d %d %d\n", (*stack_a)->content, (*stack_a)->next->content, (*stack_a)->next->next->content);

}