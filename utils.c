/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natallia <natallia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 16:36:19 by nkhamich          #+#    #+#             */
/*   Updated: 2024/12/01 11:55:38 by natallia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_median(int size)
{
	if (size % 2 == 0)
		return ((size - 2) / 2);
	else
		return ((size - 1) / 2);
}

int	find_min(t_stack *stack)
{
	int		min_index;

	min_index = stack->index;
	while (stack)
	{
		if (stack->index < min_index)
			min_index = stack->index;
		stack = stack->next;
	}
	return (min_index);
}

int	find_max(t_stack *stack)
{
	int		max_index;

	max_index = stack->index;
	while (stack)
	{
		if (stack->index > max_index)
			max_index = stack->index;
		stack = stack->next;
	}
	return (max_index);
}

bool	is_sorted(t_stack *stack)
{
	int	temp;

	temp = stack->arg;
	stack = stack->next;
	while (stack)
	{
		if (stack->arg < temp)
			return (false);
		temp = stack->arg;
		stack = stack->next;
	}
	return (true);
}

long long	custom_atoi(const char *str)
{
	int			sign;
	long long	num;

	sign = 1;
	num = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = sign * (-1);
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		num = (num * 10) + (*str - '0');
		if (num > INT_MAX || num < INT_MIN)
			return (num * sign);
		str++;
	}
	return (num * sign);
}
