/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natallia <natallia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 20:20:41 by natallia          #+#    #+#             */
/*   Updated: 2024/12/02 20:25:56 by natallia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
