/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <hekang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 18:16:45 by hekang            #+#    #+#             */
/*   Updated: 2021/06/22 15:51:04 by hekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_node *stack)
{
	t_node	*cur;

	cur = stack;
	while (cur->prev)
		cur = cur->prev;
	while (cur)
	{
		printf("%d\n", cur->content);
		cur = cur->next;
	}
}