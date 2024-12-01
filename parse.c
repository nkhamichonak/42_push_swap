/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natallia <natallia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 13:20:33 by nkhamich          #+#    #+#             */
/*   Updated: 2024/12/01 11:55:28 by natallia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
			free_and_exit_parse(stack_a, argc, argv);
		new_node_add_back((int)temp, stack_a, &error);
		if (error)
			free_and_exit_parse(stack_a, argc, argv);
		argv++;
	}
	if (argc == 2)
		free_str_array(argv);
}

int	index_stack(t_stack *stack, int *index)
{
	t_stack		*min_node;
	t_stack		*temp;

	while (true)
	{
		min_node = NULL;
		temp = stack;
		while (temp)
		{
			if (temp-> index == -1 && (!min_node || temp->arg < min_node->arg))
				min_node = temp;
			temp = temp->next;
		}
		if (!min_node)
			break ;
		min_node->index = *index;
		(*index)++;
	}
	return (*index);
}
