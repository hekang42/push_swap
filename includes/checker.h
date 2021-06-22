/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <hekang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 19:48:56 by hekang            #+#    #+#             */
/*   Updated: 2021/06/22 20:54:56 by hekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"
# include "get_next_line.h"
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
void				operator(char *op, t_node **stack_a, t_node **stack_b,
				int visual);
int					check_issort(t_node *stack_a, t_node *stack_b);
#endif
