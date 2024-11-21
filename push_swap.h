/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhamich <nkhamich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 13:29:27 by nkhamich          #+#    #+#             */
/*   Updated: 2024/11/21 12:12:32 by nkhamich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "printf/ft_printf.h"
# include "libft/libft.h"
# include <stdlib.h>
# include <stdbool.h>

typedef struct s_node
{
	int				arg;
	int				index;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

#endif