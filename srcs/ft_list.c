/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <hekang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 15:31:58 by hekang            #+#    #+#             */
/*   Updated: 2021/06/15 13:57:56 by hekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	listinit(t_dllist *plist)
{
	plist->head = (t_node *)malloc(sizeof(t_node));
	plist->tail = (t_node *)malloc(sizeof(t_node));

	plist->head->prev = NULL;
	plist->head->next = plist->tail;
	plist->tail->prev = plist->head;
	plist->tail->next = NULL;
	plist->numofdata = 0;
}

void		linsert(t_dllist *plist, int data)
{
	t_node	*newnode = (t_node *)malloc(sizeof(t_node));
	newnode->data = data;
	newnode->prev = plist->tail->prev;
	plist->tail->prev->next = newnode;
	newnode->next = plist->tail;
	plist->tail->prev = newnode;
	(plist->numofdata)++;
}

int		lfirst(t_dllist *plist, int *pdata)
{
	if (plist->head->next == plist->tail)
		return (FALSE);
	plist->cur = plist->head->next;
	*pdata = plist->cur->data;
	return (TRUE);
}

int		lremove(t_dllist *plist)
{
	t_node	*rpos;
	int		remv;
	
	rpos = plist->cur;
	remv = rpos->data;
	plist->cur->prev->next = plist->cur->next;
	plist->cur->next->prev = plist->cur->prev;

	plist->cur = plist->cur->prev;
	free(rpos);
	(plist->numofdata)--;
	return (remv);
}

int		lcount(t_dllist *plist)
{
	return (plist->numofdata);
}