/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhamich <nkhamich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 09:39:51 by nkhamich          #+#    #+#             */
/*   Updated: 2024/10/17 20:01:35 by nkhamich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

// void	change_to_x(unsigned int i, char *c)
// {
// 	if (i % 2 != 0)
// 		*c = 'x';
// }

// void	test_ft_striteri()
// {
// 	char str1[] = "abcdef";
// 	char str2[] = "123456789";
// 	char str3[] = "";
// 	char str4[] = "A";
// 	char str5[] = "xy";

// 	// Apply ft_striteri with the change_to_x function
// 	ft_striteri(str1, change_to_x);
// 	ft_striteri(str2, change_to_x);
// 	ft_striteri(str3, change_to_x);
// 	ft_striteri(str4, change_to_x);
// 	ft_striteri(str5, change_to_x);

// 	// Test cases and expected outputs
// 	printf("Test 1: %s (expected: axcxex)\n", str1);
// 	printf("Test 2: %s (expected: 1x3x5x7x9)\n", str2);
// 	printf("Test 3: %s (expected: )\n", str3); // Empty string
// 	printf("Test 4: %s (expected: A)\n", str4); // Single character
// 	printf("Test 5: %s (expected: xx)\n", str5); // Only two characters
// }

// int	main(void)
// {
// 	test_ft_striteri();
// 	return (0);
// }
