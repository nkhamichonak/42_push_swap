/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhamich <nkhamich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 13:20:33 by nkhamich          #+#    #+#             */
/*   Updated: 2024/12/03 17:32:17 by nkhamich         ###   ########.fr       */
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

void	parse_arguments(int argc, char *argv[], t_stack **stack_a)
{
	long long	temp;
	bool		error;
	char		**split_argv;

	error = false;
	if (argc == 2)
	{
		split_argv = ft_split(argv[1], ' ');
		if (split_argv == NULL)
			exit(EXIT_FAILURE);
		argv = split_argv;
	}
	else
		argv = &argv[1];
	while (*argv)
	{
		temp = custom_atoi(*argv);
		if (!is_valid_num(temp, *argv) || is_duplicate((int)temp, *stack_a))
			free_and_exit_parse(stack_a, argc, split_argv);
		new_node_add_back((int)temp, stack_a, &error);
		if (error)
			free_and_exit_parse(stack_a, argc, split_argv);
		argv++;
	}
	free_str_array(split_argv, argc);
}
