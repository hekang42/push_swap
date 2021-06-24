/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <hekang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 19:24:27 by hekang            #+#    #+#             */
/*   Updated: 2021/06/24 09:38:35 by hekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int			switch_instruction(char *instruction, t_node **stack_a,
		t_node **stack_b)
{
	int		len;

	len = ft_strlen(instruction);
	if (!ft_strncmp(instruction, "pa", len) || \
		!ft_strncmp(instruction, "pb", len) || \
		!ft_strncmp(instruction, "sa", len) || \
		!ft_strncmp(instruction, "sb", len) || \
		!ft_strncmp(instruction, "ss", len) || \
		!ft_strncmp(instruction, "ra", len) || \
		!ft_strncmp(instruction, "rb", len) || \
		!ft_strncmp(instruction, "rr", len) || \
		!ft_strncmp(instruction, "rra", len) || \
		!ft_strncmp(instruction, "rrb", len) || \
		!ft_strncmp(instruction, "rrr", len))
	{
		operator(instruction, stack_a, stack_b, 0);
		return (0);
	}
	return (1);
}

void		put_error_and_clear(t_list *instructions, char *instruction)
{
	if (instruction)
		free(instruction);
	ft_lstclear(&instructions, free);
	ft_putendl_fd("Error", 2);
	exit(1);
}

int			exec_instruction(t_list *instructions, t_node **stack_a,
		t_node **stack_b)
{
	int		instruction_err;

	while (instructions)
	{
		instruction_err = switch_instruction(\
			instructions->content, stack_a, stack_b);
		if (instruction_err)
			return (0);
		instructions = instructions->next;
	}
	return (1);
}

t_list		*read_instruction(void)
{
	int		gnl_status;
	char	*instruction;
	t_list	*instructions;
	t_list	*tmp;

	instructions = NULL;
	gnl_status = get_next_line(0, &instruction);
	while (gnl_status > 0)
	{
		tmp = ft_lstnew(instruction);
		if (tmp == NULL)
			put_error_and_clear(instructions, instruction);
		ft_lstadd_back(&instructions, tmp);
		gnl_status = get_next_line(0, &instruction);
	}
	if (ft_strlen(instruction) || gnl_status == -1)
		put_error_and_clear(instructions, NULL);
	free(instruction);
	return (instructions);
}

int			main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;
	t_list	*instructions;

	stack_a = create_stack(argc, argv);
	if (!stack_a)
		return (0);
	stack_b = NULL;
	instructions = read_instruction();
	if (!exec_instruction(instructions, &stack_a, &stack_b))
		error_and_clear(stack_a);
	else
	{
		if (check_issort(stack_a, stack_b))
			ft_putendl_fd("OK", 1);
		else
			ft_putendl_fd("KO", 1);
	}
	clear_stack(&stack_b);
	clear_stack(&stack_a);
	ft_lstclear(&instructions, free);
	return (0);
}
