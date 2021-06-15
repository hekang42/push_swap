/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <hekang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 15:12:54 by hekang            #+#    #+#             */
/*   Updated: 2021/06/15 16:32:26 by hekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"
# define FALSE 0
# define TRUE 1
typedef struct		s_node
{
	int				data;
	int				index;
	struct s_node	*prev;
	struct s_node	*next;
}                   t_node;

typedef struct		s_dllist
{
	int				numofdata;
	int				max;
	int				data;
	struct s_node	*head;
	struct s_node	*tail;
}                   t_dllist;


void 	listinit(t_dllist *plist);
void	linsert(t_dllist *plist, int data);

int		lfirst(t_dllist *plist, int *data);
int		lnext(t_dllist *plist, int *data);
int		lprevious(t_dllist *plist, int *data);
int		lcount(t_dllist *plist);
int		lremove(t_dllist *plist);


#endif