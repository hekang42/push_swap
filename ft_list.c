/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <hekang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 15:31:58 by hekang            #+#    #+#             */
/*   Updated: 2021/06/14 16:55:31 by hekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_dllist*	init_dlist()
{
	t_dllist* result;

	result = (t_dllist *)malloc(sizeof(t_dllist));
	if (result == NULL)
		return (NULL);
	result->size = 0;
	result->head = NULL;
	result->tail = NULL;
	return (result);
}

t_node*		init_node()
{
	t_node*	result;

	result = (t_node *)malloc(sizeof(t_node));
	if (result == NULL)
		return (NULL);
	result->data = 0;
	result->next = NULL;
	result->prev = NULL;
	return (result);
}

void		append_first(t_dllist* dllst, t_node* node)
{
	if (dllst->head == NULL)
	{
		dllst->head = node;
		dllst->tail = node;
		node->prev = dllst->head;
		node->next = dllst->tail;
	}
	else
	{
		dllst->head->next->prev = node;
		node->next = dllst->head->next;
		dllst->head->next = node;
		node->prev = dllst->head;
	}
	dllst->size++;
}

void		append_last(t_dllist* dllst, t_node* node)
{
	if (dllst->head == NULL)
	{
		dllst->head->next = node;
		node->prev = dllst->head;
		node->next = dllst->tail;
		dllst->tail->prev = node;
	}
	else
	{
		dllst->tail->prev->next = node;
		node->prev = dllst->tail->prev;
		dllst->tail->prev = node;
		node->next = dllst->tail;
	}
	dllst->size++;
}