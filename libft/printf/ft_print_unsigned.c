/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natallia <natallia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 15:38:21 by natallia          #+#    #+#             */
/*   Updated: 2024/10/30 20:09:06 by natallia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_utoa(unsigned int n)
{
	char			*num_str;
	int				digit_count;
	unsigned int	num;

	num = n;
	digit_count = 0;
	if (n == 0)
		digit_count = 1;
	while (n > 0)
	{
		n /= 10;
		digit_count++;
	}
	num_str = malloc((digit_count + 1) * sizeof(char));
	if (num_str == NULL)
		return (NULL);
	num_str[digit_count] = '\0';
	while (digit_count > 0)
	{
		num_str[--digit_count] = (num % 10) + '0';
		num /= 10;
	}
	return (num_str);
}

static int	ft_print_numstr(char *num_str, t_flags *flags)
{
	int	count;
	int	digit_len;
	int	len;

	count = 0;
	digit_len = ft_strlen(num_str);
	if (digit_len < flags->precision)
		len = flags->precision;
	else
		len = digit_len;
	if (!flags->left_align)
		count += ft_fill_width(flags->min_width, flags->zero_pad, len);
	if (flags->precision > digit_len)
		count += ft_fill_width(flags->precision, 1, digit_len);
	count += ft_putstr(num_str);
	if (flags->left_align)
		count += ft_fill_width(flags->min_width, 0, len);
	return (count);
}

int	ft_print_unsigned(unsigned int num, t_flags *flags)
{
	int		count;
	char	*num_str;

	count = 0;
	if (flags->dot && flags->precision == 0 && num == 0)
	{
		count += ft_fill_width(flags->min_width, 0, 0);
		return (count);
	}
	num_str = ft_utoa(num);
	if (num_str == NULL)
		return (-1);
	count += ft_print_numstr(num_str, flags);
	free (num_str);
	return (count);
}
