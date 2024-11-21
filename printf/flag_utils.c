/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhamich <nkhamich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 13:27:20 by natallia          #+#    #+#             */
/*   Updated: 2024/10/30 14:36:21 by nkhamich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_initialise_flags(t_flags *flags)
{
	flags->left_align = 0;
	flags->zero_pad = 0;
	flags->dot = 0;
	flags->precision = 0;
	flags->min_width = 0;
	flags->alt_form = 0;
	flags->space = 0;
	flags->force_sign = 0;
}

int	ft_is_valid_arg(const char *str)
{
	while (ft_is_specifier(*str) || ft_isdigit(*str))
		str++;
	if (ft_is_type(*str))
		return (1);
	return (0);
}

int	ft_is_specifier(int c)
{
	if (c == '-' || c == '0' || c == '.' || c == '*'
		|| c == '#' || c == ' ' || c == '+')
		return (1);
	return (0);
}

int	ft_is_type(int c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i'
		|| c == 'u' || c == 'x' || c == 'X' || c == '%')
		return (1);
	return (0);
}
