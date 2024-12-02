/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhamich <nkhamich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 13:59:40 by nkhamich          #+#    #+#             */
/*   Updated: 2024/10/30 13:25:17 by nkhamich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_process_star(t_flags *flags, va_list args)
{
	int	value;

	value = va_arg(args, int);
	if (flags->dot)
	{
		if (value >= 0)
			flags->precision = value;
		else
			flags->precision = 0;
	}
	else
	{
		if (value < 0)
		{
			flags->left_align = 1;
			flags->min_width = -value;
		}
		else
			flags->min_width = value;
	}
}

static void	ft_process_digit(const char **ptr, t_flags *flags)
{
	if (flags->dot)
		flags->precision = (flags->precision * 10) + (**ptr - '0');
	else
	{
		if (flags->min_width == 0 && **ptr == '0')
			flags->zero_pad = 1;
		else
			flags->min_width = (flags->min_width * 10) + (**ptr - '0');
	}
}

char	ft_parse_flags(const char **ptr, t_flags *flags, va_list args)
{
	while (**ptr && !ft_is_type(**ptr))
	{
		if (ft_isdigit(**ptr))
			ft_process_digit(ptr, flags);
		else if (**ptr == '#')
			flags->alt_form = 1;
		else if (**ptr == '.')
		{
			flags->dot = 1;
			flags->zero_pad = 0;
		}
		else if (**ptr == ' ')
			flags->space = 1;
		else if (**ptr == '+')
			flags->force_sign = 1;
		else if (**ptr == '-')
			flags->left_align = 1;
		else if (**ptr == '*')
			ft_process_star(flags, args);
		(*ptr)++;
	}
	return (**ptr);
}
