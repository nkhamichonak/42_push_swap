/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhamich <nkhamich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 20:06:42 by natallia          #+#    #+#             */
/*   Updated: 2024/12/02 13:08:27 by nkhamich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack **stack_dest, t_stack **stack_src)
{
	t_stack		*temp;

	if (!(*stack_src))
		return ;
	temp = *stack_src;
	*stack_src = temp->next;
	if ((*stack_src))
		(*stack_src)->prev = NULL;
	temp->next = *stack_dest;
	if (*stack_dest)
		(*stack_dest)->prev = temp;
	else
		temp->prev = NULL;
	*stack_dest = temp;
}

static void	swap(t_stack **stack)
{
	t_stack		*temp;

	if (!(*stack) || !(*stack)->next)
		return ;
	temp = (*stack)->next;
	(*stack)->next = temp->next;
	if (temp->next)
		temp->next->prev = *stack;
	temp->next = *stack;
	temp->prev = NULL;
	(*stack)->prev = temp;
	*stack = temp;
}

static void	rotate(t_stack **stack, bool reverse)
{
	t_stack		*last;
	t_stack		*temp;

	if (!(*stack) || !(*stack)->next)
		return ;
	last = last_node(*stack);
	temp = *stack;
	if (!reverse)
	{
		*stack = (*stack)->next;
		(*stack)->prev = NULL;
		temp->next = NULL;
		temp->prev = last;
		last->next = temp;
	}
	else
	{
		last->prev->next = NULL;
		last->prev = NULL;
		last->next = *stack;
		(*stack)->prev = last;
		(*stack) = last;
	}
}

static void	rotate_both(t_stack **a, t_stack **b, bool reverse)
{
	rotate(a, reverse);
	rotate(b, reverse);
}

void	execute(t_stack **a, t_stack **b, char *command, bool silent)
{
	if (ft_strcmp("sa", command) == 0)
		swap(a);
	else if (ft_strcmp("sb", command) == 0)
		swap(b);
	else if (ft_strcmp("sb", command) == 0)
		swap(b);
	else if (ft_strcmp("pa", command) == 0)
		push(a, b);
	else if (ft_strcmp("pb", command) == 0)
		push(b, a);
	else if (ft_strcmp("ra", command) == 0)
		rotate(a, false);
	else if (ft_strcmp("rb", command) == 0)
		rotate(b, false);
	else if (ft_strcmp("rr", command) == 0)
		rotate_both(a, b, false);
	else if (ft_strcmp("rra", command) == 0)
		rotate(a, true);
	else if (ft_strcmp("rrb", command) == 0)
		rotate(b, true);
	else if (ft_strcmp("rrr", command) == 0)
		rotate_both(a, b, true);
	if (!silent)
		ft_printf("%s\n", command);
}
