/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_index.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <hekang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 16:25:09 by hekang            #+#    #+#             */
/*   Updated: 2021/06/22 10:19:16 by hekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int				calc_index(int n, t_node *stack)
{
	int			index;

	index = 0;
	while (stack)
	{
		if (n > stack->content)
			index++;
		stack = stack->next;
	}
	return (index);
}

void			put_index(t_node *stack)
{
	t_node		*cur;
	
	cur = stack;
	while (cur)
	{
		cur->index = calc_index(cur->content, stack);
		cur = cur->next;
	}
}