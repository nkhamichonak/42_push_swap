/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natallia <natallia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 21:09:43 by natallia          #+#    #+#             */
/*   Updated: 2024/12/01 11:40:37 by natallia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	realign_stack_a(t_stack **a, int size)
{
	int			i;
	int			min_index;
	t_stack		*temp;

	i = 0;
	min_index = 0;
	temp = *a;
	while (temp->index != min_index)
	{
		temp = temp->next;
		i++;
	}
	if (i < size - i)
		while (i--)
			execute(a, NULL, "ra");
	else
	{
		i = size - i;
		while (i--)
			execute(a, NULL, "rra");
	}
}

static void	push_back_sorted(t_stack **a, t_stack **b)
{
	t_moves		*best_move;

	best_move = malloc(sizeof(t_moves));
	if (best_move == NULL)
		free_and_exit(a, b);
	while (*b)
	{
		initialise_move(best_move);
		calculate_options(a, b, best_move, lstsize(*b));
		execute_best_option(best_move, a, b);
	}
	free(best_move);
}

static void	push_all(t_stack **a, t_stack **b, int max, int median)
{
	int			i;
	int			current_count;

	i = 0;
	current_count = lstsize(*a);
	if (current_count <= 5)
	{
		mini_sort(a, b, current_count);
		return ;
	}
	while (i < current_count)
	{
		if ((*a)->index < (max - 4))
		{
			execute(a, b, "pb");
			if ((*b)->index < median)
				execute(a, b, "rb");
		}
		else
			execute(a, b, "ra");
		i++;
	}
	mini_sort(a, b, 5);
}

static void	push_median(t_stack **a, t_stack **b, int median, int len)
{
	int			shortest;
	t_stack		*temp;

	shortest = 0;
	temp = *a;
	while (temp->index != median)
	{
		shortest++;
		temp = temp->next;
	}
	if (shortest <= (len - shortest))
	{
		while (shortest--)
			execute(a, b, "ra");
	}
	else
	{
		shortest = len - shortest;
		while (shortest--)
			execute(a, b, "rra");
	}
	execute(a, b, "pb");
}

void	mega_sort(t_stack **a, t_stack **b, int total_numbers)
{
	int		median;

	median = find_median(total_numbers);
	push_median(a, b, median, total_numbers);
	push_all(a, b, total_numbers - 1, median);
	push_back_sorted(a, b);
	realign_stack_a(a, total_numbers);
}
