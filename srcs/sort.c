/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <hekang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 16:24:21 by hekang            #+#    #+#             */
/*   Updated: 2021/06/22 16:44:25 by hekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			find_from_front(int find, t_node *stack)
{
	int		result;
	t_node	*cur;

	cur = stack;
	result = 0;
	while (cur && cur->index != find )
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
	while (cur && cur->index != find)
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
	while (cur && cur->index >= find)
	{
		front_count++;
		cur = cur->next;
	}
	cur = stack;
	while (cur->next)
		cur = cur->next;
	rear_count = 1;
	while (cur && cur->index > find)
	{
		rear_count++;
		cur = cur->prev;
	}
	if (front_count >= rear_count)
		return (ft_stacksize(stack) - rear_count);
	return (front_count);
}

void		sort_from_b(t_node **stack_a, t_node **stack_b)
{
	int		find_index;
	int		rb_count;
	int		rrb_count;
	int		flag;
	int		flag2;

	flag = 0;
	flag2 = 0;
	put_index(*stack_b);
	while (*stack_b)
	{
		find_index = ft_stacksize(*stack_b) - 1;
		rb_count = find_from_front(find_index, *stack_b); 
		rrb_count = find_from_rear(find_index, *stack_b);
		if (rb_count <= rrb_count)
			while(rb_count--  && ((*stack_b)->index != find_index))
				if ((*stack_b)->index == find_index - 1)
				{
					operator("pa", stack_a, stack_b);
					flag = 1;
				}
				else if (flag && (*stack_b)->index == find_index - 2)
				{
					operator("pa", stack_a, stack_b);
					operator("ra", stack_a, stack_b);
					flag2 = 1;
				}	
				else
					operator("rb", stack_a, stack_b);
		else
			while(rrb_count-- + 1 && ((*stack_b)->index != find_index))
				if ((*stack_b)->index == find_index - 1)
				{
					operator("pa", stack_a, stack_b);
					operator("rrb", stack_a, stack_b);
					flag = 1;
				}
				else if (flag && (*stack_b)->index == find_index - 2)
				{
					operator("pa", stack_a, stack_b);
					operator("ra", stack_a, stack_b);
					operator("rrb", stack_a, stack_b);
					flag2 = 1;
				}
				else
					operator("rrb", stack_a, stack_b);
		operator("pa", stack_a, stack_b);
		if (flag == 1)
		{
			operator("sa", stack_a, stack_b);
			flag = 0;
		}
		if (flag2 == 1)
		{
			operator("rra", stack_a, stack_b);
			flag2 = 0;
		}
	}
}

void		sort(t_node **stack_a, t_node **stack_b)
{
	int		count;
	int		size;
	int		index_count;
	int		chunk_count;
	
	put_index(*stack_a);
	if (ft_stacksize(*stack_a) > 250)
		chunk_count = 5;
	else
		chunk_count = 3;
	size = ft_stacksize(*stack_a) / chunk_count + ft_stacksize(*stack_a) % chunk_count;
	count = 0;
	while (count < size)
		if ((*stack_a)->index < size)
		{
			operator("pb", stack_a, stack_b);
			if ((*stack_b)->index > size / 2 )
				operator("rb", stack_a, stack_b);
			count++;
		}
		else
		{
			index_count = find_index_smaller(size, *stack_a);
			while ((*stack_a)->index >= size && index_count != 0)
				operator("ra", stack_a, stack_b);
			// if ((*stack_a)->index < size || index_count == 0)
			// 	continue;
		}
	size = ft_stacksize(*stack_a) / chunk_count + ft_stacksize(*stack_a) % chunk_count;
	if (size < 1)
		sort_from_b(stack_a, stack_b);
	else
		sort(stack_a, stack_b);

}
