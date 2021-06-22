/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <hekang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 16:24:21 by hekang            #+#    #+#             */
/*   Updated: 2021/06/22 19:03:55 by hekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			sort_from_b_3(t_node **s_b, int *rb_count, \
				int *rrb_count)
{
	int		find_index;

	find_index = ft_ssize(*s_b) - 1;
	*rb_count = find_from_front(find_index, *s_b);
	*rrb_count = find_from_rear(find_index, *s_b);
	return (find_index);
}

void		sort_from_b_2(t_node **s_a, t_node **s_b, int *flag, int *flag2)
{
	operator("pa", s_a, s_b);
	if (*flag == 1)
		*flag = operator_return_false("sa", s_a, s_b);
	if (*flag2 == 1)
		*flag2 = operator_return_false("rra", s_a, s_b);
}

void		sort_from_b(t_node **stack_a, t_node **stack_b, int flag, int flag2)
{
	int		find_index;
	int		rb_count;
	int		rrb_count;

	while (*stack_b)
	{
		find_index = sort_from_b_3(stack_b, &rb_count, &rrb_count);
		if (rb_count <= rrb_count)
			while (rb_count-- && ((*stack_b)->index != find_index))
				if ((*stack_b)->index == find_index - 1)
					flag = operator_pa(stack_a, stack_b);
				else if (flag && (*stack_b)->index == find_index - 2)
					flag2 = operator_pa_ra(stack_a, stack_b);
				else
					operator("rb", stack_a, stack_b);
		else
			while (rrb_count-- + 1 && ((*stack_b)->index != find_index))
				if ((*stack_b)->index == find_index - 1)
					flag = operator_pa_rrb(stack_a, stack_b);
				else if (flag && (*stack_b)->index == find_index - 2)
					flag2 = operator_pa_ra_rrb(stack_a, stack_b);
				else
					operator("rrb", stack_a, stack_b);
		sort_from_b_2(stack_a, stack_b, &flag, &flag2);
	}
}

void		operate_split_1(t_node **stack_a, t_node **stack_b, int size, int c)
{
	c += 0;
	operator("pb", stack_a, stack_b);
	if ((*stack_b)->index > size / 2)
		operator("rb", stack_a, stack_b);
}

void		sort(t_node **stack_a, t_node **stack_b)
{
	int		count;
	int		size;
	int		chunk_count;
	int		flag;
	int		flag2;

	init_var(&flag, &flag2, &count);
	put_index(*stack_a);
	chunk_count = (ft_ssize(*stack_a) > 250) ? 5 : 3;
	size = ft_ssize(*stack_a) / chunk_count + ft_ssize(*stack_a) % chunk_count;
	while (count < size)
		if ((*stack_a)->index < size)
			operate_split_1(stack_a, stack_b, size, count++);
		else
			while ((*stack_a)->index >= size)
				operator("ra", stack_a, stack_b);
	size = ft_ssize(*stack_a) / chunk_count + ft_ssize(*stack_a) % chunk_count;
	if (size < 1)
	{
		put_index(*stack_b);
		sort_from_b(stack_a, stack_b, flag, flag2);
	}
	else
		sort(stack_a, stack_b);
}
