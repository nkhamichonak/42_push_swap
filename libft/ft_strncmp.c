/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhamich <nkhamich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 09:39:51 by nkhamich          #+#    #+#             */
/*   Updated: 2024/10/17 14:50:40 by nkhamich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && (s1[i] || s2[i]))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

// int main(void)
// {
// 	// Test cases
// 	const char *str1 = "Hello, World!";
// 	const char *str2 = "Hello, Earth!";
// 	const char *str3 = "Hello, World!";
// 	const char *str4 = "Hello";

// 	printf("Testing ft_strncmp against strncmp:\n");

// 	// Test case 1: Different strings
// 	printf("Comparing '%s' and '%s' for first 10 chars:\n", 
// 		str1, str2);
// 	printf("libft: %d | string.h: %d\n", 
// 		ft_strncmp(str1, str2, 10), strncmp(str1, str2, 10));

// 	// Test case 2: Same strings
// 	printf("\nComparing '%s' and '%s' for first 10 chars:\n", 
// 		str3, str1);
// 	printf("libft: %d | string.h: %d\n", 
// 		ft_strncmp(str3, str1, 10), strncmp(str3, str1, 10));

// 	// Test case 3: Different lengths
// 	printf("\nComparing '%s' and '%s' for first 5 chars:\n", 
// 		str4, str1);
// 	printf("libft: %d | string.h: %d\n", 
// 		ft_strncmp(str4, str1, 5), strncmp(str4, str1, 5));

// 	// Test case 4: Same characters, different cases
// 	const char *str7 = "Hello";
// 	const char *str8 = "hello";
// 	printf("\nComparing '%s' and '%s' for first 5 chars:\n", 
// 		str7, str8);
// 	printf("libft: %d | string.h: %d\n", 
// 		ft_strncmp(str7, str8, 5), strncmp(str7, str8, 5));

// 	return (0);
// }
