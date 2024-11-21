/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhamich <nkhamich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 16:58:47 by nkhamich          #+#    #+#             */
/*   Updated: 2024/10/17 11:56:28 by nkhamich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

// int	main(void)
// {
// 	printf("'g' | libft: %d; ctype: %d; "
// 			"expected: non-zero\n", ft_isalnum('g'), isalnum('g'));
// 	printf("'A' | libft: %d; ctype: %d; "
// 			"expected: non-zero\n", ft_isalnum('A'), isalnum('A'));
// 	printf("'z' | libft: %d; ctype: %d; "
// 			"expected: non-zero\n", ft_isalnum('z'), isalnum('z'));
// 	printf("'5' | libft: %d; ctype: %d; "
// 			"expected: non-zero\n", ft_isalnum('5'), isalnum('5'));
// 	printf("' ' | libft: %d; ctype: %d; "
// 			"expected: 0\n", ft_isalnum(' '), isalnum(' '));
// 	printf(" -1 | libft: %d; ctype: %d; "
// 			"expected: 0\n", ft_isalnum(-1), isalnum(-1)); //EOF
// 	printf("200 | libft: %d; ctype: %d; "
// 			"expected: 0\n", ft_isalnum(200), isalnum(200)); // Extended ASCII
// 	return (0);
// }