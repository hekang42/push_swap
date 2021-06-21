/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <hekang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 16:24:21 by hekang            #+#    #+#             */
/*   Updated: 2021/06/21 19:58:30 by hekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			find_from_front(int find, t_node *stack)
{
	int		result;
	t_node	*cur;

	cur = stack;
	result = 0;
	while (cur->index != find && cur->next)
	{
		result++;
		cur = cur->next;
	}
	return (result);
}

int			find_from_rear(int find, t_node *stack)
{
	int		result;
	t_node	*cur;

	cur = stack;
	while (cur->next)
		cur = cur->next;
	result = 0;
	while (cur->index != find && cur->prev)
	{
		result++;
		cur = cur->prev;
	}
	return (result);
}

void		sort_from_b(t_node **stack_a, t_node **stack_b)
{
	int		find_index;
	int		rb_count;
	int		rrb_count;

	find_index = 1;
	while (*stack_b)
	{
		rb_count = find_from_front(find_index, *stack_b);
		rrb_count = find_from_rear(find_index++, *stack_b);
		if (rb_count < rrb_count)
			while(rb_count--)
				operator("rb", stack_a, stack_b);
		else
			while(rrb_count-- + 1)
				operator("rrb", stack_a, stack_b);
		operator("pa", stack_a, stack_b);
		operator("ra", stack_a, stack_b);
	}
}

void		sort(t_node **stack_a, t_node **stack_b, int size)
{
	int		pb_count;

	pb_count = 0;
	while (pb_count <= (size) / 2)
	{
		if ((*stack_a)->index > (size) / 2)
		{
			operator("pb", stack_a, stack_b);
			if ((*stack_b)->index > size * 3 /4 )
				operator("rb", stack_a, stack_b);
		}
		else
		{
			operator("ra", stack_a, stack_b);
			pb_count++;
		}
	}
	if (size < 1)
		sort_from_b(stack_a, stack_b);
	else
		sort(stack_a, stack_b, (size) / 2);

}
