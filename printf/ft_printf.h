/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natallia <natallia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 13:29:14 by nkhamich          #+#    #+#             */
/*   Updated: 2024/10/31 20:46:21 by natallia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <limits.h>
# include "libft/libft.h"

typedef struct s_flags
{
	int	left_align;
	int	zero_pad;
	int	dot;
	int	precision;
	int	min_width;
	int	alt_form;
	int	space;
	int	force_sign;
}	t_flags;

// FLAGS
void	ft_initialise_flags(t_flags *flags);
int		ft_is_valid_arg(const char *str);
char	ft_parse_flags(const char **ptr, t_flags *flags, va_list args);
int		ft_is_specifier(int c);
int		ft_is_type(int c);

// PRINT ARGUMENTS
int		ft_print_char(int c, t_flags *flags);
int		ft_print_hex(unsigned int num, t_flags *flags, int upper_case);
int		ft_print_int(int num, t_flags *flags);
int		ft_print_pointer(void *ptr, t_flags *flags);
int		ft_print_string(const char *str, t_flags *flags);
int		ft_print_unsigned(unsigned int num, t_flags *flags);

// HELPER FUNCTIONS
int		ft_putchar(unsigned char c);
int		ft_putstr(const char *s);
int		ft_fill_width(int min_width, int zero_pad, int size);
char	*ft_hextoa(unsigned long int num);
int		ft_hex_len(unsigned long int n);
int		ft_printf(const char *format, ...);
int		ft_print_substr(const char *str, const char *ptr);

#endif
