/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <hekang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 18:20:46 by hekang            #+#    #+#             */
/*   Updated: 2021/06/15 14:58:08 by hekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_isdigitandspace(char *c)
{
	int cnt;

	cnt = 0;
	while (c[cnt])
	{
		if ((c[cnt] < '0' || c[cnt] > '9') && c[cnt] !=' ' && c[cnt] != '-')
			return (0);
		cnt++;
	}
	return (1);
}

int		check_input(char *str)
{
	int cnt;
	int arr[100000];
	char **num_list;

	if (str == NULL)
		return (0);

	cnt = 0;
	num_list = ft_split(str, ' ');

	// while (num_list[cnt] != 0)
	// 	printf("%d\n", ft_atoi(num_list[cnt++]));
	// cnt = 0;
	while (num_list[cnt])
	{
		if (ft_isdigitandspace(num_list[cnt]) == 0)
			return (0);
		// printf("%d\n\n",ft_atoi(num_list[cnt]));
		if (!arr[+ft_atoi(num_list[cnt])])
		{
			arr[+ft_atoi(num_list[cnt])] = 1;
		}
		else
			return (0);
		cnt++;
	}
	return (1);
}


// void	init_data(t_dllist *stack, char* str)
// {
// 	int		cnt;
// 	char	**num_list;

// 	cnt = 0;
// 	num_list = ft_split(str,' ');
// 	// while (num_list[cnt])
// 	// 	input_data(stack, ft_atoi(num_list[cnt++]));

// 	// init_dllist(stack);

// }


int		main(int argc, char **argv)
{
	argc = 0;
	if (check_input(argv[1]) == 0)// 인풋 인자 확인
	{
		write(1, "Error\n", 6);
		return (0);
	}
	
	// init_data(stack_a, argv[1]);
}

