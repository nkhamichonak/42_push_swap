/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natallia <natallia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 14:10:57 by natallia          #+#    #+#             */
/*   Updated: 2024/10/30 20:05:32 by natallia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_null_printable_len(t_flags *flags)
{
	if (flags->dot && flags->precision < 6)
		return (0);
	else
		return (6);
}

static int	ft_printable_len(const char *s, t_flags *flags)
{
	int	len;

	len = 0;
	if (flags->dot)
	{
		while (s[len] && len < flags->precision)
			len++;
	}
	else
	{
		while (s[len])
			len++;
	}
	return (len);
}

int	ft_print_string(const char *str, t_flags *flags)
{
	int	count;
	int	len;

	count = 0;
	if (str == NULL)
	{
		str = "(null)";
		len = ft_null_printable_len(flags);
	}
	else
		len = ft_printable_len(str, flags);
	if (flags->left_align)
	{
		write (1, str, len);
		count += len;
	}
	count += ft_fill_width(flags->min_width, flags->zero_pad, len);
	if (!flags->left_align)
	{
		write (1, str, len);
		count += len;
	}
	return (count);
}
