/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimisation_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natallia <natallia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 11:03:11 by natallia          #+#    #+#             */
/*   Updated: 2024/12/01 11:50:20 by natallia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_next_largest_a(t_stack *a, int index)
{
	t_stack		*temp;
	int			next_largest;

	temp = a;
	next_largest = INT_MAX;
	while (temp)
	{
		if (temp->index > index && temp->index < next_largest)
			next_largest = temp->index;
		temp = temp->next;
	}
	return (next_largest);
}

void	execute_best_option(t_moves *best_mv, t_stack **a, t_stack **b)
{
	while (best_mv->rr_count--)
		execute(a, b, "rr");
	while (best_mv->rrr_count--)
		execute(a, b, "rrr");
	while (best_mv->ra_count--)
		execute(a, b, "ra");
	while (best_mv->rra_count-- > 0)
		execute(a, b, "rra");
	while (best_mv->rb_count--)
		execute(a, b, "rb");
	while (best_mv->rrb_count--)
		execute(a, b, "rrb");
	execute(a, b, "pa");
}

void	update_current_best(t_moves *best, t_moves *move)
{
	best->ra_count = move->ra_count;
	best->rra_count = move->rra_count;
	best->rb_count = move->rb_count;
	best->rrb_count = move->rrb_count;
	best->rr_count = move->rr_count;
	best->rrr_count = move->rrr_count;
	best->total = move->total;
}

void	initialise_move(t_moves *move)
{
	move->ra_count = 0;
	move->rra_count = 0;
	move->rb_count = 0;
	move->rrb_count = 0;
	move->rr_count = 0;
	move->rrr_count = 0;
	move->total = INT_MAX;
}
