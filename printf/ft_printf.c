/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natallia <natallia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 12:08:40 by nkhamich          #+#    #+#             */
/*   Updated: 2024/10/31 21:18:26 by natallia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_type(char format_spec, va_list args, t_flags *flags)
{
	int	count;

	count = 0;
	if (format_spec == 'c')
		count += ft_print_char(va_arg(args, int), flags);
	if (format_spec == 's')
		count += ft_print_string(va_arg(args, const char *), flags);
	if (format_spec == 'd' || format_spec == 'i')
		count += ft_print_int(va_arg(args, int), flags);
	if (format_spec == 'x')
		count += ft_print_hex(va_arg(args, unsigned int), flags, 0);
	if (format_spec == 'X')
		count += ft_print_hex(va_arg(args, unsigned int), flags, 1);
	if (format_spec == '%')
		count += ft_putchar('%');
	if (format_spec == 'u')
		count += ft_print_unsigned(va_arg(args, unsigned int), flags);
	if (format_spec == 'p')
		count += ft_print_pointer(va_arg(args, void *), flags);
	return (count);
}

static int	ft_print_till_end(const char **str)
{
	int	count;

	count = 0;
	count += ft_putstr(*str);
	*str += ft_strlen(*str) - 1;
	return (count);
}

static int	ft_print_arg(const char **str, const char **ptr, va_list args)
{
	int			count;
	char		format_spec;
	t_flags		flags;

	count = 0;
	count += ft_print_substr(*str, *ptr);
	if (count < 0)
		return (-1);
	*str = *ptr + 1;
	ft_initialise_flags(&flags);
	format_spec = ft_parse_flags(str, &flags, args);
	count += ft_print_type(format_spec, args, &flags);
	return (count);
}

static int	ft_parse(const char *format, va_list args)
{
	int			count;
	const char	*ptr;

	count = 0;
	while (*format)
	{
		ptr = ft_strchr(format, '%');
		if (ptr && ft_is_valid_arg(ptr + 1))
			count += ft_print_arg(&format, &ptr, args);
		else if (!ft_strchr(format + 1, '%'))
			count += ft_print_till_end(&format);
		else
		{
			count += ft_print_substr(format, ptr + 1);
			format = ptr;
		}
		if (count < 0)
			return (-1);
		format++;
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list		args;
	int			count;

	if (!format || *format == '\0')
		return (0);
	va_start(args, format);
	count = ft_parse(format, args);
	va_end(args);
	return (count);
}
