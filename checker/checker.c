/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhamich <nkhamich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 12:58:29 by nkhamich          #+#    #+#             */
/*   Updated: 2024/12/02 15:27:48 by nkhamich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	execute_instructions(t_stack **a, t_stack **b, t_list **instruct_list)
{
	while (instruct_list)
	{
		execute(a, b, (*instruct_list)->content);
		instruct_list = (*instruct_list)->next;
	}
	ft_lstclear(instruct_list, free);
}

bool	is_valid_instruct(char *node)
{
	
}

void	free_and_exit_checker(t_stack **a, t_list **instruct_list)
{
	free_stack(a);
	ft_lstclear(instruct_list, free);
	ft_putendl_fd("Error", STDERR_FILENO);
	exit(EXIT_FAILURE);
}

void	parse_instructions(t_stack *a, t_list **instruct_list)
{
	t_list	*node;
	char	*command;

	command = get_next_line(STDIN_FILENO);
	while (command)
	{
		if (!is_valid_instruct)
			free_and_exit_checker(a, instruct_list);
		node = ft_lstnew(command);
		if (node == NULL)
			free_and_exit_checker(a, instruct_list);
		ft_lstadd_back(instruct_list, node);
		command = get_next_line(STDIN_FILENO);
	}
}

int	main(int argc, char *argv[])
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	t_list		*instruct_list;

	stack_a = NULL;
	stack_b = NULL;
	instruct_list = NULL;
	if (argc == 1)
		return (0);
	parse_arguments(argc, argv, &stack_a);
	parse_instructions(&stack_a, &instruct_list);
	execute_instructions(&stack_a, &stack_b, &instruct_list);
	if (is_sorted(stack_a) && stack_b == NULL)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free_stack(&stack_a);
	return (0);
}
