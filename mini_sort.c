/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natallia <natallia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 18:05:49 by natallia          #+#    #+#             */
/*   Updated: 2024/12/01 10:51:45 by natallia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_three(t_stack **a, t_stack **b)
{
	int		highest_node;

	highest_node = find_max(*a);
	if (is_sorted(*a))
		return ;
	if ((*a)->index == highest_node)
		execute(a, b, "ra");
	else if ((*a)->next->index == highest_node)
		execute(a, b, "rra");
	if ((*a)->index > (*a)->next->index)
		execute(a, b, "sa");
}

static void	sort_four(t_stack **a, t_stack **b)
{
	int		lowest_node;

	lowest_node = find_min(*a);
	if (is_sorted(*a))
		return ;
	while ((*a)->index != lowest_node)
	{
		if ((*a)->next->index == lowest_node)
			execute(a, b, "sa");
		else if ((*a)->next->next->index == lowest_node)
			execute(a, b, "ra");
		else
			execute(a, b, "rra");
	}
	execute(a, b, "pb");
	sort_three(a, b);
	execute(a, b, "pa");
}

static void	sort_five(t_stack **a, t_stack **b)
{
	int		lowest_node;

	lowest_node = find_min(*a);
	if (is_sorted(*a))
		return ;
	while ((*a)->index != lowest_node)
	{
		if ((*a)->next->index == lowest_node)
			execute(a, b, "sa");
		else if ((*a)->next->next->index == lowest_node)
			execute(a, b, "ra");
		else
			execute(a, b, "rra");
	}
	execute(a, b, "pb");
	sort_four(a, b);
	execute(a, b, "pa");
}

void	mini_sort(t_stack **a, t_stack **b, int total_numbers)
{
	if (is_sorted(*a))
		return ;
	else if (total_numbers == 2)
		execute(a, b, "sa");
	else if (total_numbers == 3)
		sort_three(a, b);
	else if (total_numbers == 4)
		sort_four(a, b);
	else if (total_numbers == 5)
		sort_five(a, b);
}
