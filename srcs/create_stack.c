/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <hekang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 09:47:11 by hekang            #+#    #+#             */
/*   Updated: 2021/06/24 09:42:18 by hekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			error_and_clear(t_node *stack)
{
	clear_stack(&stack);
	ft_putendl_fd("Error", 2);
	exit(1);
}

int				atoi_check(char *str, t_node *stack)
{
	long long	num;
	t_node		*cur;

	num = ft_atoll(str);
	if (num > 2147483647 || num < -2147483648)
		error_and_clear(stack);
	cur = stack;
	while (cur)
	{
		if (cur->content == num)
			error_and_clear(stack);
		cur = cur->next;
	}
	return (num);
}

int				ft_isdigit_str(char *str)
{
	int			cnt;
	int			c;

	cnt = 0;
	if (str[cnt] == '-')
		cnt++;
	while (str[cnt])
	{
		c = str[cnt++];
		if ((c < '0' || c > '9'))
		{
			return (0);
		}
	}
	return (1);
}

t_node			*create_stack(int argc, char **argv)
{
	t_node		*result;
	t_node		*tmp;
	int			argc_count;

	result = NULL;
	argc_count = 0;
	while (++argc_count < argc)
	{
		if (!ft_isdigit_str(argv[argc_count])
		|| ft_strlen(argv[argc_count]) > 11
		|| ft_strlen(argv[argc_count]) == 0)
			error_and_clear(result);
		tmp = stack_new(atoi_check(argv[argc_count], result));
		stack_add_back(&result, tmp);
	}
	return (result);
}
