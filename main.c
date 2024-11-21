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

static bool	is_duplicate(int num, int *args, int i)
{
	while (i > 0)
	{
		i--;
		if (num == args[i])
			return (true);
	}
	return (false);
}

static bool	is_valid_num(long temp, char *num)
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

char	*ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	while (i >= 0)
	{
		free(str[i]);
		i--;
	}
	return (NULL);
}

void	parse_arguments(int argc, char *argv[], int *args)
{
	int		i;
	long	temp;

	i = 0;
	if (argc == 2)
		argv = ft_split(argv[1], ' ');
	else
		argv = &argv[1];
	if (argv == NULL)
		exit (EXIT_FAILURE);
	while (argv[i])
	{
		temp = ft_atoi(argv[i]);
		if (!is_valid_num(temp, argv[i]) || is_duplicate(temp, args, i))
		{
			if (argc == 2)
				ft_free(argv);
			exit (EXIT_FAILURE);
		}
		args[i] = temp;
		i++;
	}
	if (argc == 2)
		ft_free(argv);
}

int	main(int argc, char *argv[])
{
	int			*args;

	if (argc == 1)
		return (0);
	parse_arguments(argc, argv, args);
	return (0);
}
