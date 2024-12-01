/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natallia <natallia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 20:06:42 by natallia          #+#    #+#             */
/*   Updated: 2024/12/01 10:49:09 by natallia         ###   ########.fr       */
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

static void	rotate_both(t_stack **stack_a, t_stack **stack_b, bool reverse)
{
	rotate(stack_a, reverse);
	rotate(stack_b, reverse);
}

void	execute(t_stack **stack_a, t_stack **stack_b, char *command)
{
	if (ft_strcmp("sa", command) == 0)
		swap(stack_a);
	else if (ft_strcmp("sb", command) == 0)
		swap(stack_b);
	else if (ft_strcmp("sb", command) == 0)
		swap(stack_b);
	else if (ft_strcmp("pa", command) == 0)
		push(stack_a, stack_b);
	else if (ft_strcmp("pb", command) == 0)
		push(stack_b, stack_a);
	else if (ft_strcmp("ra", command) == 0)
		rotate(stack_a, false);
	else if (ft_strcmp("rb", command) == 0)
		rotate(stack_b, false);
	else if (ft_strcmp("rr", command) == 0)
		rotate_both(stack_a, stack_b, false);
	else if (ft_strcmp("rra", command) == 0)
		rotate(stack_a, true);
	else if (ft_strcmp("rrb", command) == 0)
		rotate(stack_b, true);
	else if (ft_strcmp("rrr", command) == 0)
		rotate_both(stack_a, stack_b, true);
	ft_printf("%s\n", command);
}
