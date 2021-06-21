/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <hekang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 15:12:54 by hekang            #+#    #+#             */
/*   Updated: 2021/06/21 15:26:13 by hekang           ###   ########.fr       */
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
	int				content;
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


void	stack_add_back(t_node **lst, t_node *new_list);
t_node	*stack_new(int content);
t_node	*create_stack(int argc, char **argv);
void	clear_stack(t_node **stack);
void	stack_sort(t_node *stack_a, t_node *stack_b);
int		ft_stacksize(t_node *lst);

void	operator(char *op, t_node **stack_a, t_node **stack_b);
void	swap(t_node **stack);
void	push(t_node **stack_first, t_node **stack_second);
void	rotate(t_node **stack);
void	rrotate(t_node **stack);

void	sort_three(t_node **stack_a, t_node **stack_b);
void	sort_five(t_node **stack_a, t_node **stack_b);


#endif