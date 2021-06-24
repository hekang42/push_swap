/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <hekang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 15:12:54 by hekang            #+#    #+#             */
/*   Updated: 2021/06/24 10:50:09 by hekang           ###   ########.fr       */
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
}					t_node;

void				stack_add_back(t_node **lst, t_node *new_list);
t_node				*stack_new(int content);
t_node				*create_stack(int argc, char **argv);
void				clear_stack(t_node **stack);
void				stack_sort(t_node *stack_a, t_node *stack_b);
int					ft_ssize(t_node *lst);
void				operator(char *op, t_node **stack_a, t_node **stack_b,
				int visual);
void				swap(t_node **stack);
void				push(t_node **stack_first, t_node **stack_second);
void				rotate(t_node **stack);
void				rrotate(t_node **stack);
void				sort_three(t_node **stack_a, t_node **stack_b);
void				sort_five(t_node **stack_a, t_node **stack_b);
void				put_index(t_node *stack);
void				sort(t_node **stack_a, t_node **stack_b);
void				print_stack(t_node *stack);
int					operator_pa(t_node **stack_a, t_node **stack_b);
int					operator_pa_ra(t_node **stack_a, t_node **stack_b);
int					operator_pa_rrb(t_node **stack_a, t_node **stack_b);
int					operator_pa_ra_rrb(t_node **stack_a, t_node **stack_b);
int					operator_return_false(char *op, t_node **stack_a,\
				t_node **stack_b);
int					find_from_front(int find, t_node *stack);
int					find_from_rear(int find, t_node *stack);
int					find_index_smaller(int find, t_node *stack);
void				init_var(int *a, int *b, int *c);
int					check_issort(t_node *stack_a, t_node *stack_b);

#endif
