/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhamich <nkhamich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 11:27:46 by nkhamich          #+#    #+#             */
/*   Updated: 2024/10/17 14:54:35 by nkhamich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*ptr1;
	unsigned char	*ptr2;

	i = 0;
	ptr1 = (unsigned char *)s1;
	ptr2 = (unsigned char *)s2;
	while (i < n)
	{
		if (ptr1[i] != ptr2[i])
			return (ptr1[i] - ptr2[i]);
		i++;
	}
	return (0);
}

// int main(void)
// {
// 	const char *str1 = "Hello, World!";
// 	const char *str2 = "Hello, World!";
// 	const char *str3 = "Hello, World.";
// 	const char *str4 = "Hello, everyone!";

// 	// Test case 1: Identical strings
// 	int res1 = ft_memcmp(str1, str2, strlen(str1));
// 	int res2 = memcmp(str1, str2, strlen(str1));
// 	printf("Identical strings: libft: %d | string.h: %d\n", res1, res2);

// 	// Test case 2: Different strings
// 	res1 = ft_memcmp(str1, str3, strlen(str1));
// 	res2 = memcmp(str1, str3, strlen(str1));
// 	printf("Diff strings: libft: %d | string.h: %d\n", res1, res2);

// 	// Test case 3: Same prefix, different length
// 	res1 = ft_memcmp(str1, str2, 10);
// 	res2 = memcmp(str1, str2, 10);
// 	printf("Same prefix: libft: %d | string.h: %d\n", res1, res2);

// 	// Test case 4: Completely different strings
// 	res1 = ft_memcmp(str1, str4, strlen(str1));
// 	res2 = memcmp(str1, str4, strlen(str1));
// 	printf("Completely different: libft: %d | string.h: %d\n", res1, res2);

// 	// Test case 5: Comparing zero length
// 	res1 = ft_memcmp(str1, str2, 0);
// 	res2 = memcmp(str1, str2, 0);
// 	printf("Zero length: libft: %d | string.h: %d\n", res1, res2);

// 	return (0);
// }
