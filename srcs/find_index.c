/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_index.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <hekang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 17:33:42 by hekang            #+#    #+#             */
/*   Updated: 2021/06/22 17:33:49 by hekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			find_from_front(int find, t_node *stack)
{
	int		result;
	t_node	*cur;

	cur = stack;
	result = 0;
	while (cur && cur->index != find)
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
		return (ft_ssize(stack) - rear_count);
	return (front_count);
}
