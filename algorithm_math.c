/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_math.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhamich <nkhamich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 11:46:11 by natallia          #+#    #+#             */
/*   Updated: 2024/12/03 13:35:24 by nkhamich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	get_a_rotations(t_moves *move, t_stack **a, int next_largest)
{
	int			i;
	int			size;
	t_stack		*temp;

	i = 0;
	size = lstsize(*a);
	temp = *a;
	while (temp->index != next_largest)
	{
		temp = temp->next;
		i++;
	}
	if (i <= (size - i))
		move->ra_count = i;
	else
		move->rra_count = size - i;
}

static void	get_b_rotations(t_moves *move, int i, int size)
{
	if (i <= (size - i))
		move->rb_count = i;
	else
		move->rrb_count = size - i;
}

static void	get_double_rotations(t_moves *move)
{
	while (move->ra_count && move->rb_count)
	{
		move->rr_count++;
		move->ra_count--;
		move->rb_count--;
	}
	while (move->rra_count && move->rrb_count)
	{
		move->rrr_count++;
		move->rra_count--;
		move->rrb_count--;
	}
}

static int	get_total(t_moves *move)
{
	int		total;

	total = move->ra_count
		+ move->rb_count
		+ move->rr_count
		+ move->rra_count
		+ move->rrb_count
		+ move->rrr_count;
	move->total = total;
	return (total);
}

void	calculate_moves(t_stack **a, t_stack **b, t_moves *best, int size)
{
	t_stack		*temp_b;
	t_moves		*move;
	int			i;

	temp_b = *b;
	move = malloc(sizeof(t_moves));
	if (move == NULL)
		free_and_exit(a, b);
	i = 0;
	while (i < size)
	{
		initialise_move(move);
		get_b_rotations(move, i, size);
		get_a_rotations(move, a, find_next_largest_a(*a, temp_b->index));
		get_double_rotations(move);
		if (get_total(move) < best->total)
			update_current_best(best, move);
		if (best->total < 2)
			break ;
		temp_b = temp_b->next;
		i++;
	}
	free(move);
}
