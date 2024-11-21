/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhamich <nkhamich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 10:27:30 by nkhamich          #+#    #+#             */
/*   Updated: 2024/10/17 11:57:36 by nkhamich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	else
		return (0);
}

// int main(void)
// {
// 	printf("'g' | libft: %d; ctype: %d; "
// 		   "expected: non-zero\n", ft_isascii('g'), isascii('g'));
// 	printf("DEL | libft: %d; ctype: %d; "
// 		   "expected: non-zero\n", ft_isascii(127), isascii(127));
// 	printf("\\0  | libft: %d; ctype: %d; "
// 		   "expected: non-zero\n", ft_isascii('\0'), isascii('\0'));
// 	printf("'5' | libft: %d; ctype: %d; "
// 		   "expected: non-zero\n", ft_isascii('5'), isascii('5'));
// 	printf("-1  | libft: %d; ctype: %d; "
// 		   "expected: 0\n", ft_isascii(-1), isascii(-1));
// 	printf("200 | libft: %d; ctype: %d; "
// 		   "expected: 0\n", ft_isascii(200), isascii(200));
// 	return (0);
// }