/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhamich <nkhamich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 13:20:33 by nkhamich          #+#    #+#             */
/*   Updated: 2024/11/22 16:52:31 by nkhamich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static void	new_node_add_back(int num, t_stack **stack, bool *error)
{
	t_stack	*node;
	t_stack	*last_node;

	node = malloc(sizeof(t_stack));
	if (node == NULL)
	{
		*error = true;
		return ;
	}
	node->arg = num;
	node->index = 0;
	node->prev = NULL;
	node->next = NULL;
	if (*stack == NULL)
		*stack = node;
	else
	{
		last_node = *stack;
		while (last_node->next)
			last_node = last_node->next;
		last_node->next = node;
		node->prev = last_node;
	}
}

static bool	is_duplicate(int num, t_stack *stack)
{
	while (stack)
	{
		if (stack->arg == num)
			return (true);
		stack = stack->next;
	}
	return (false);
}

static bool	is_valid_num(long long temp, char *num)
{
	int	i;

	i = 0;
	if (temp > INT_MAX || temp < INT_MIN)
		return (false);
	if (num[i] == '-' || num[i] == '+')
		i++;
	while (num[i])
	{
		if (!ft_isdigit(num[i]))
			return (false);
		i++;
	}
	return (true);
}

void	parse_arguments(int argc, char *argv[], t_stack **stack_a)
{
	long long	temp;
	bool		error;

	error = false;
	if (argc == 2)
		argv = ft_split(argv[1], ' ');
	else
		argv = &argv[1];
	if (argv == NULL)
		exit(EXIT_FAILURE);
	while (*argv)
	{
		temp = custom_atoi(*argv);
		if (!is_valid_num(temp, *argv) || is_duplicate((int)temp, *stack_a))
			free_and_exit(stack_a, argc, argv);
		new_node_add_back((int)temp, stack_a, &error);
		if (error)
			free_and_exit(stack_a, argc, argv);
		argv++;
	}
	if (argc == 2)
		free_str_array(argv);
}