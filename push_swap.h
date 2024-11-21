/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natallia <natallia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 13:29:27 by nkhamich          #+#    #+#             */
/*   Updated: 2024/11/21 21:49:17 by natallia         ###   ########.fr       */
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
	struct s_node	*prev;
	struct s_node	*next;
}	t_stack;

#endif
