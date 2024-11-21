/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhamich <nkhamich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 11:27:46 by nkhamich          #+#    #+#             */
/*   Updated: 2024/10/17 14:45:15 by nkhamich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}

// void test_toupper(int c)
// {
// 	int result_custom = ft_toupper(c);
// 	int result_original = toupper(c);

// 	printf("Character: %c | ft_toupper: %c | toupper: %c\n",
// 			c, result_custom, result_original);

// 	// Compare results
// 	if (result_custom == result_original)
// 		printf("Test passed.\n");
// 	else
// 		printf("Test failed.\n");
// }

// int main(void)
// {
// 	// Test with lowercase letters
// 	printf("\nTesting lowercase letters:\n");
// 	test_toupper('a');
// 	test_toupper('z');
// 	test_toupper('m');

// 	// Test with uppercase letters
// 	printf("\nTesting uppercase letters:\n");
// 	test_toupper('A');
// 	test_toupper('Z');

// 	// Test with non-alphabetic characters
// 	printf("\nTesting non-alphabetic characters:\n");
// 	test_toupper('1');
// 	test_toupper('$');
// 	test_toupper(' ');

// 	// Test with boundary cases
// 	printf("\nTesting boundary cases:\n");
// 	test_toupper('a' - 1); // character just before 'a'
// 	test_toupper('z' + 1); // character just after 'z'

// 	return (0);
// }
