/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhamich <nkhamich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 20:20:41 by natallia          #+#    #+#             */
/*   Updated: 2024/12/03 13:37:30 by nkhamich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	execute_silent(t_stack **a, t_stack **b, char *command)
{
	if (ft_strcmp("sa\n", command) == 0)
		swap(a);
	else if (ft_strcmp("sb\n", command) == 0)
		swap(b);
	else if (ft_strcmp("pa\n", command) == 0)
		push(a, b);
	else if (ft_strcmp("pb\n", command) == 0)
		push(b, a);
	else if (ft_strcmp("ra\n", command) == 0)
		rotate(a, false);
	else if (ft_strcmp("rb\n", command) == 0)
		rotate(b, false);
	else if (ft_strcmp("rr\n", command) == 0)
		rotate_both(a, b, false);
	else if (ft_strcmp("rra\n", command) == 0)
		rotate(a, true);
	else if (ft_strcmp("rrb\n", command) == 0)
		rotate(b, true);
	else if (ft_strcmp("rrr\n", command) == 0)
		rotate_both(a, b, true);
}

bool	is_valid_instruct(char *command)
{
	size_t	len;

	len = ft_strlen(command);
	if (len == 3
		&& (!ft_strncmp(command, "ra\n", 3)
			|| !ft_strncmp(command, "rb\n", 3)
			|| !ft_strncmp(command, "rr\n", 3)
			|| !ft_strncmp(command, "sa\n", 3)
			|| !ft_strncmp(command, "sb\n", 3)
			|| !ft_strncmp(command, "ss\n", 3)
			|| !ft_strncmp(command, "pb\n", 3)
			|| !ft_strncmp(command, "pa\n", 3)))
		return (true);
	else if (len == 4
		&& (!ft_strncmp(command, "rra\n", 4)
			|| !ft_strncmp(command, "rrb\n", 4)
			|| !ft_strncmp(command, "rrr\n", 4)))
		return (true);
	else
		return (false);
}

void	free_and_exit_checker(t_stack **a, t_list **instructions)
{
	free_stack(a);
	ft_lstclear(instructions, free);
	ft_putendl_fd("Error", STDERR_FILENO);
	exit(EXIT_FAILURE);
}
