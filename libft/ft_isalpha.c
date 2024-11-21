/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhamich <nkhamich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 13:12:00 by nkhamich          #+#    #+#             */
/*   Updated: 2024/10/17 11:56:49 by nkhamich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

// int	main(void)
// {
// 	printf("'g' | libft: %d; ctype: %d; "
// 			"expected: non-zero\n", ft_isalpha('g'), isalpha('g'));
// 	printf("'A' | libft: %d; ctype: %d; "
// 			"expected: non-zero\n", ft_isalpha('A'), isalpha('A'));
// 	printf("'z' | libft: %d; ctype: %d; "
// 			"expected: non-zero\n", ft_isalpha('z'), isalpha('z'));
// 	printf("'5' | libft: %d; ctype: %d; "
// 			"expected: 0\n", ft_isalpha('5'), isalpha('5'));
// 	printf("' ' | libft: %d; ctype: %d; "
// 			"expected: 0\n", ft_isalpha(' '), isalpha(' '));
// 	printf(" -1 | libft: %d; ctype: %d; "
// 			"expected: 0\n", ft_isalpha(-1), isalpha(-1));
// 	printf("200 | libft: %d; ctype: %d; "
// 			"expected: 0\n", ft_isalpha(200), isalpha(200));
// 	return (0);
// }