/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <hekang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 15:12:54 by hekang            #+#    #+#             */
/*   Updated: 2021/06/14 16:43:11 by hekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct		s_node
{
	int				data;
	struct s_node	*prev;
	struct s_node	*next;
}                   t_node;

typedef struct		s_dllist
{
	int				size;
	struct s_node	*head;
	struct s_node	*tail;
}                   t_dllist;
