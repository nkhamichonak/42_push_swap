/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natallia <natallia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 13:14:47 by natallia          #+#    #+#             */
/*   Updated: 2024/10/31 20:45:54 by natallia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(unsigned char c)
{
	int	count;

	count = write (1, &c, 1);
	if (count < 0)
	{
		write (2, "Write failed in ft_putchar\n", 27);
		return (-1);
	}
	else
		return (count);
}

int	ft_putstr(const char *s)
{
	int	len;
	int	count;

	len = ft_strlen(s);
	count = write(1, s, len);
	if (count < 0)
	{
		write (2, "Write failed in ft_putstr\n", 27);
		return (-1);
	}
	else
		return (count);
}

int	ft_fill_width(int min_width, int zero_pad, int size)
{
	int	count;

	count = 0;
	while (min_width - size > 0)
	{
		if (!zero_pad)
		{
			count += ft_putchar(' ');
		}
		else
			count += ft_putchar('0');
		min_width--;
	}
	return (count);
}

int	ft_print_substr(const char *str, const char *ptr)
{
	int			count;
	size_t		len;
	char		*temp;

	count = 0;
	len = ptr - str;
	temp = ft_substr(str, 0, len);
	if (temp == NULL)
	{
		write (2, "Memory allocation failed in print_substr\n", 41);
		return (-1);
	}
	count += ft_putstr(temp);
	free (temp);
	return (count);
}
