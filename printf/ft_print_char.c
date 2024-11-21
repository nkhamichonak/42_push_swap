/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natallia <natallia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 13:28:59 by natallia          #+#    #+#             */
/*   Updated: 2024/10/30 19:44:58 by natallia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(int c, t_flags *flags)
{
	int	count;

	count = 0;
	if (flags->left_align)
		count += ft_putchar(c);
	count += ft_fill_width(flags->min_width, flags->zero_pad, 1);
	if (!flags->left_align)
		count += ft_putchar(c);
	return (count);
}
