/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <hekang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 18:20:46 by hekang            #+#    #+#             */
/*   Updated: 2021/06/14 15:53:16 by hekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_strlen(char *c)
{
	int cnt;

	cnt = 0;
	while (c[cnt])
		cnt++;
	return (cnt);
}
int		ft_isdigit(int c)
{
	if ((c >= '0' && c <= '9') || c ==' ')
		return (1);
	else
		return (0);
}

int		check_input(char *str)
{
	int cnt;

	if (str == NULL)
		return (0);

	cnt = 0;
	
	while (cnt < ft_strlen(str) - 1)
	{
		if(ft_isdigit(str[cnt]) == 0)
			return (0);
		cnt++;
	}
	return (1);
}

void	swap_single(t_list *a)
{

}

void	append_data(t_list *stack, int data)
{
	t_list*	new_list;

	while (stack->next != NULL)
		stack = stack->next;
	new_list = (t_list *)malloc(sizeof(t_list));
	new_list->prev = stack->prev;
	new_list->next = stack;
	stack->prev = new_list;
}

void	init_data(t_list *stack, char* str)
{
	t_list*	head;
	t_list*	tail;
	int		cnt;
	
	head = (t_list *)malloc(sizeof(t_list));
	tail = (t_list *)malloc(sizeof(t_list));
	head->next = tail;
	head->prev = head;
	tail->next = tail;
	tail->prev = head;

	cnt = 0;
	while (str[cnt])
		input_data(stack, str[cnt++]);

	init_list(stack);

}


int		main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	if (check_input(argv[1]) == 0)// 인풋 인자 확인
	{
		write(1, "Error\n", 6);
		return (0);
	}
	
	init_data(stack_a, argv[1]);
}

