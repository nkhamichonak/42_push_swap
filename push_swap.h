/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhamich <nkhamich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 13:29:27 by nkhamich          #+#    #+#             */
/*   Updated: 2024/11/22 16:37:57 by nkhamich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "printf/ft_printf.h"
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

// parsing
void		parse_arguments(int argc, char *argv[], t_stack **stack_a);

// mallocs and freeing
void		free_and_exit(t_stack **stack_a, int argc, char *argv[]);
void		free_stack(t_stack **stack);
void		free_str_array(char **str);

// utils
long long	custom_atoi(const char *str);

#endif
