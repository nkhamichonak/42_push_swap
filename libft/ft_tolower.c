/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhamich <nkhamich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 11:27:46 by nkhamich          #+#    #+#             */
/*   Updated: 2024/10/17 14:45:53 by nkhamich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}

// void test_tolower(int c)
// {
// 	int result_custom = ft_tolower(c);
// 	int result_original = tolower(c);

// 	printf("Character: %c | ft_tolower: %c | tolower: %c\n",
// 			c, result_custom, result_original);

// 	// Compare results
// 	if (result_custom == result_original)
// 		printf("Test passed.\n");
// 	else
// 		printf("Test failed.\n");
// }

// int main(void)
// {
// 	// Test with uppercase letters
// 	printf("\nTesting uppercase letters:\n");
// 	test_tolower('A');
// 	test_tolower('Z');
// 	test_tolower('M');

// 	// Test with lowercase letters
// 	printf("\nTesting lowercase letters:\n");
// 	test_tolower('a');
// 	test_tolower('z');

// 	// Test with non-alphabetic characters
// 	printf("\nTesting non-alphabetic characters:\n");
// 	test_tolower('1');
// 	test_tolower('$');
// 	test_tolower(' ');

// 	// Test with boundary cases
// 	printf("\nTesting boundary cases:\n");
// 	test_tolower('A' - 1); // character just before 'A'
// 	test_tolower('Z' + 1); // character just after 'Z'

// 	return (0);
// }
