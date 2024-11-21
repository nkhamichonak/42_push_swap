/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhamich <nkhamich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 13:37:36 by nkhamich          #+#    #+#             */
/*   Updated: 2024/11/21 17:29:50 by nkhamich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_duplicate()
{

}

bool	is_valid_num()
{

}

bool	parse_arguments(int argc, char *argv[])
{
	int		i;
	long	temp;
	char	**args;

	i = 0;
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
		args = &argv[1];
	if (args == NULL)
		return ; // RETURN / EXIT / WHAT ???
	while (args[i])
	{
		temp = ft_atoi(args[i]);
		if (!is_valid_num(args[i]))
		
		i++;
	}
}

int	main(int argc, char *argv[])
{
	bool	parse;
	t_node	*stack_a;
	t_node	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1)
		return (0);
	
	return (0);
}
