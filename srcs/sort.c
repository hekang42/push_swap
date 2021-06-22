/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <hekang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 16:24:21 by hekang            #+#    #+#             */
/*   Updated: 2021/06/22 09:44:21 by hekang           ###   ########.fr       */
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

int			find_index_smaller(int find, t_node *stack)
{
	int		front_count;
	int		rear_count;
	t_node	*cur;

	cur = stack;
	front_count = 0;
	while (cur->index >= find && cur->next)
	{
		front_count++;
		cur = cur->next;
	}
	cur = stack;
	while (cur->next)
		cur = cur->next;
	rear_count = 0;
	while (cur->index > find && cur->prev)
	{
		rear_count++;
		cur = cur->prev;
	}
	printf("front_count: %d\n", front_count);
	printf("rear_count: %d\n", rear_count);
	if (front_count > rear_count)
		return (ft_stacksize(stack) - rear_count);
	return (front_count);
}

void		sort_from_b(t_node **stack_a, t_node **stack_b)
{
	int		find_index;
	int		rb_count;
	int		rrb_count;
	// int		size;

	put_index(*stack_b);
	find_index = ft_stacksize(*stack_b);
	while (*stack_b)
	{
		rb_count = find_from_front(find_index, *stack_b);
		rrb_count = find_from_rear(find_index--, *stack_b);
		if (rb_count < rrb_count)
			while(rb_count--)
				operator("rb", stack_a, stack_b);
		else
			while(rrb_count-- + 1)
				operator("rrb", stack_a, stack_b);
		operator("pa", stack_a, stack_b);
	}
}

void		sort(t_node **stack_a, t_node **stack_b)
{
	int		count;
	int		size;
	int		index_count;
	
	put_index(*stack_a);
	size = ft_stacksize(*stack_a) / 2;
	count = -1;
	while (count < size)
		if ((*stack_a)->index < size)
		{
			operator("pb", stack_a, stack_b);
			if ((*stack_b)->index <= size / 2 )
				operator("rb", stack_a, stack_b);
		}
		else
		{
			index_count = find_index_smaller(size, *stack_a);
			printf("index_count : %d\n", index_count);
			printf("size : %d\n", size);
			printf("stack_a->index : %d\n", (*stack_a)->index);
			while ((*stack_a)->index >= size && count < size && index_count + 1 != size)
			{
				if (index_count < size)
					operator("ra", stack_a, stack_b);
				else
					operator("rra", stack_a, stack_b);
				count++;
			}
			count++;
		}
	if (size < 1)
		sort_from_b(stack_a, stack_b);
	else
		sort(stack_a, stack_b);

}
