/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhamich <nkhamich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 11:03:11 by nkhamich          #+#    #+#             */
/*   Updated: 2024/10/17 11:58:19 by nkhamich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	else
		return (0);
}

// int main(void)
// {
// 	printf("'g' | libft: %d; ctype: %d; "
// 		   "expected: non-zero\n", ft_isprint('g'), isprint('g'));
// 	printf("'A' | libft: %d; ctype: %d; "
// 		   "expected: non-zero\n", ft_isprint('A'), isprint('A'));
// 	printf("' ' | libft: %d; ctype: %d; "
// 		   "expected: non-zero\n", ft_isprint(' '), isprint(' '));
// 	printf("\\0  | libft: %d; ctype: %d; "
// 		   "expected: 0\n", ft_isprint('\0'), isprint('\0'));
// 	printf("'0' | libft: %d; ctype: %d; "
// 		   "expected: non-zero\n", ft_isprint('0'), isprint('0'));
// 	printf(" -1 | libft: %d; ctype: %d; "
// 		   "expected: 0\n", ft_isprint(-1), isprint(-1));
// 	printf("200 | libft: %d; ctype: %d; "
// 		   "expected: 0\n", ft_isprint(200), isprint(200));
// 	return (0);
// }