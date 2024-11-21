/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natallia <natallia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 13:23:44 by natallia          #+#    #+#             */
/*   Updated: 2024/10/30 19:44:58 by natallia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hex_len(unsigned long int n)
{
	int	digit_count;

	digit_count = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 16;
		digit_count++;
	}
	return (digit_count);
}

char	*ft_hextoa(unsigned long int num)
{
	int			digit_count;
	char		*hex_str;
	const char	*hex_digits;

	digit_count = ft_hex_len(num);
	hex_str = malloc((digit_count + 1) * sizeof(char));
	if (hex_str == NULL)
		return (NULL);
	hex_digits = "0123456789abcdef";
	hex_str[digit_count] = '\0';
	while (digit_count > 0)
	{
		hex_str[--digit_count] = hex_digits[num % 16];
		num /= 16;
	}
	return (hex_str);
}

static int	ft_add_prefix(unsigned int n, t_flags *flags, int upper, int pad)
{
	int	count;

	count = 0;
	if (flags->alt_form && n != 0)
	{
		if ((pad && flags->zero_pad)
			|| (!pad && !flags->zero_pad))
		{
			if (upper)
				count += ft_putstr("0X");
			else
				count += ft_putstr("0x");
		}
	}
	return (count);
}

static int	ft_print_numstr(unsigned int n, char *str, t_flags *flags, int up)
{
	int	count;
	int	digit_len;
	int	len;
	int	total_len;

	count = 0;
	digit_len = ft_strlen(str);
	if (digit_len < flags->precision)
		len = flags->precision;
	else
		len = digit_len;
	if (flags->alt_form && n != 0)
		total_len = len + 2;
	else
		total_len = len;
	count += ft_add_prefix(n, flags, up, 1);
	if (!flags->left_align)
		count += ft_fill_width(flags->min_width, flags->zero_pad, total_len);
	count += ft_add_prefix(n, flags, up, 0);
	if (flags->precision > digit_len)
		count += ft_fill_width(flags->precision, 1, digit_len);
	count += ft_putstr(str);
	if (flags->left_align)
		count += ft_fill_width(flags->min_width, 0, total_len);
	return (count);
}

int	ft_print_hex(unsigned int num, t_flags *flags, int upper_case)
{
	int		count;
	int		i;
	char	*num_str;

	count = 0;
	i = 0;
	if (flags->dot && flags->precision == 0 && num == 0)
	{
		count += ft_fill_width(flags->min_width, 0, 0);
		return (count);
	}
	num_str = ft_hextoa(num);
	if (num_str == NULL)
		return (-1);
	if (upper_case)
	{
		while (num_str[i])
		{
			num_str[i] = ft_toupper(num_str[i]);
			i++;
		}
	}
	count += ft_print_numstr(num, num_str, flags, upper_case);
	free (num_str);
	return (count);
}
