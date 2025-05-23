/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_ops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhamich <nkhamich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 14:10:55 by nkhamich          #+#    #+#             */
/*   Updated: 2024/12/04 12:08:56 by nkhamich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_and_exit(t_stack **stack_a, t_stack **stack_b)
{
	free_stack(stack_a);
	free_stack(stack_b);
	ft_putendl_fd("Error", STDERR_FILENO);
	exit(EXIT_FAILURE);
}

void	free_stack(t_stack **stack)
{
	t_stack	*temp;

	if (!stack)
		return ;
	while (*stack)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
	*stack = NULL;
}

void	free_str_array(char **str, int argc)
{
	int	i;

	if (!str)
		return ;
	if (argc != 2)
		return ;
	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	cleanup_and_exit_parse(t_stack **stack_a, int argc, char **argv)
{
	free_str_array(argv, argc);
	free_stack(stack_a);
	ft_putendl_fd("Error", STDERR_FILENO);
	exit(EXIT_FAILURE);
}
