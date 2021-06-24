/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_issort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <hekang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 20:51:36 by hekang            #+#    #+#             */
/*   Updated: 2021/06/22 20:56:38 by hekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int			check_issort(t_node *stack_a, t_node *stack_b)
{
	int		count;
	t_node	*cur;

	count = 0;
	if (stack_b != NULL)
		return (0);
	while (stack_a)
	{
		cur = stack_a;
		while (cur && cur->next)
		{
			if (cur->content > cur->next->content)
				return (0);
			cur = cur->next;
		}
		(stack_a) = (stack_a)->next;
	}
	return (1);
}
