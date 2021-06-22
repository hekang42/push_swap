/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <hekang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 10:11:01 by hekang            #+#    #+#             */
/*   Updated: 2021/06/22 17:28:34 by hekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node		*stack_new(int content)
{
	t_node	*lst;

	lst = malloc(sizeof(t_node));
	if (lst == NULL)
		return (0);
	lst->next = 0;
	lst->prev = 0;
	lst->content = content;
	return (lst);
}
