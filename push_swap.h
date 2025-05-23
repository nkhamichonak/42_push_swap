/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhamich <nkhamich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 13:29:27 by nkhamich          #+#    #+#             */
/*   Updated: 2024/12/04 12:25:31 by nkhamich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdlib.h>
# include <stdbool.h>

typedef struct s_stack
{
	int				arg;
	int				index;
	struct s_stack	*prev;
	struct s_stack	*next;
}	t_stack;

typedef struct s_moves
{
	int		ra_count;
	int		rra_count;
	int		rb_count;
	int		rrb_count;
	int		rr_count;
	int		rrr_count;
	int		total;
}	t_moves;

// parsing
void		parse_arguments(int argc, char *argv[], t_stack **stack_a);
int			index_stack(t_stack *stack, int *index);

// stack operations
bool		new_node_add_back(int num, t_stack **stack);
t_stack		*last_node(t_stack *stack);
int			lstsize(t_stack *lst);

// algorithm, optimisations, and execution
void		mini_sort(t_stack **stack_a, t_stack **stack_b, int total_numbers);
void		mega_sort(t_stack **a, t_stack **b, int total_numbers);
void		calculate_moves(t_stack **a, t_stack **b, t_moves *best, int size);
int			find_next_largest_a(t_stack *a, int index);
void		execute_best_option(t_moves *best_mv, t_stack **a, t_stack **b);
void		update_current_best(t_moves *best, t_moves *move);
void		initialise_move(t_moves *best_moves);

// commands and instructions
void		execute(t_stack **a, t_stack **b, char *command);
void		push(t_stack **stack_dest, t_stack **stack_src);
void		swap(t_stack **stack);
void		rotate(t_stack **stack, bool reverse);
void		rotate_swap_both(t_stack **a, t_stack **b, bool reverse, bool swp);

// utilities
int			find_median(int size);
int			find_min(t_stack *stack);
int			find_max(t_stack *stack);
bool		is_sorted(t_stack *stack);
long long	custom_atoi(const char *str);

// mallocs and freeing
void		cleanup_and_exit_parse(t_stack **stack_a, int argc, char **argv);
void		free_and_exit(t_stack **stack_a, t_stack **stack_b);
void		free_stack(t_stack **stack);
void		free_str_array(char **str, int argc);

#endif
