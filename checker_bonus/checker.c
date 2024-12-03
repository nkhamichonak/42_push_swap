/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhamich <nkhamich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 12:58:29 by nkhamich          #+#    #+#             */
/*   Updated: 2024/12/03 13:28:40 by nkhamich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	execute_instructions(t_stack **a, t_stack **b, t_list **instructs)
{
	t_list	*temp;

	temp = *instructs;
	while (temp)
	{
		execute_silent(a, b, temp->content);
		temp = temp->next;
	}
	ft_lstclear(instructs, free);
}

static void	parse_instructions(t_stack **a, t_list **instructions)
{
	t_list		*node;
	char		*command;

	command = get_next_line(STDIN_FILENO);
	while (command)
	{
		if (!is_valid_instruct(command))
			free_and_exit_checker(a, instructions);
		node = ft_lstnew(command);
		if (node == NULL)
			free_and_exit_checker(a, instructions);
		ft_lstadd_back(instructions, node);
		command = get_next_line(STDIN_FILENO);
	}
}

int	main(int argc, char *argv[])
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	t_list		*instructions;

	stack_a = NULL;
	stack_b = NULL;
	instructions = NULL;
	if (argc == 1)
		return (0);
	parse_arguments(argc, argv, &stack_a);
	parse_instructions(&stack_a, &instructions);
	execute_instructions(&stack_a, &stack_b, &instructions);
	if (is_sorted(stack_a) && stack_b == NULL)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free_stack(&stack_a);
	return (0);
}
