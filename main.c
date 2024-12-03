/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhamich <nkhamich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 13:37:36 by nkhamich          #+#    #+#             */
/*   Updated: 2024/12/03 13:28:55 by nkhamich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	int			total_numbers;

	stack_a = NULL;
	stack_b = NULL;
	total_numbers = 0;
	if (argc == 1)
		return (0);
	parse_arguments(argc, argv, &stack_a);
	if (is_sorted(stack_a))
		return (free_stack(&stack_a), 0);
	index_stack(stack_a, &total_numbers);
	if (total_numbers <= 5)
		mini_sort(&stack_a, &stack_b, total_numbers);
	else
		mega_sort(&stack_a, &stack_b, total_numbers);
	free_stack(&stack_a);
	return (0);
}
