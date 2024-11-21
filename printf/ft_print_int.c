/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natallia <natallia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 16:08:03 by natallia          #+#    #+#             */
/*   Updated: 2024/10/30 20:02:54 by natallia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_signs_and_space(int num, t_flags *flags)
{
	int	count;

	count = 0;
	if (num < 0)
		count += ft_putchar('-');
	else if (flags->force_sign)
		count += ft_putchar('+');
	else if (flags->space)
		count += ft_putchar(' ');
	return (count);
}

static int	ft_print_numstr(int num, char *num_str, t_flags *flags)
{
	int	count;
	int	digit_len;
	int	total_len;

	count = 0;
	digit_len = ft_strlen(num_str);
	if (digit_len < flags->precision)
		digit_len = flags->precision;
	if (num < 0 || flags->space || flags->force_sign)
		total_len = digit_len + 1;
	else
		total_len = digit_len;
	if (flags->zero_pad)
		count += ft_signs_and_space(num, flags);
	if (!flags->left_align)
		count += ft_fill_width(flags->min_width, flags->zero_pad, total_len);
	if (!flags->zero_pad)
		count += ft_signs_and_space(num, flags);
	count += ft_fill_width(flags->precision, 1, ft_strlen(num_str));
	count += ft_putstr(num_str);
	if (flags->left_align)
		count += ft_fill_width(flags->min_width, 0, total_len);
	return (count);
}

int	ft_print_int(int num, t_flags *flags)
{
	int		count;
	char	*num_str;
	int		nbr;

	count = 0;
	nbr = num;
	if (flags->dot && flags->precision == 0 && num == 0)
	{
		count += ft_fill_width(flags->min_width, 0, 0);
		return (count);
	}
	if (num == INT_MIN)
		num_str = "2147483648";
	else
	{
		if (num < 0)
			nbr = -num;
		num_str = ft_itoa(nbr);
		if (num_str == NULL)
			return (-1);
	}
	count += ft_print_numstr(num, num_str, flags);
	if (num != INT_MIN)
		free (num_str);
	return (count);
}
