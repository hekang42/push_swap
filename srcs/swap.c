/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <hekang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 10:50:37 by hekang            #+#    #+#             */
/*   Updated: 2021/06/22 17:29:24 by hekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		swap(t_node **stack)
{
	int		tmp;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	tmp = (*stack)->content;
	(*stack)->content = (*stack)->next->content;
	(*stack)->next->content = tmp;
	return ;
}
