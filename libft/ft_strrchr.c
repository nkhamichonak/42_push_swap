/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhamich <nkhamich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 11:27:46 by nkhamich          #+#    #+#             */
/*   Updated: 2024/10/17 14:48:13 by nkhamich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	len;

	len = ft_strlen(s);
	if ((unsigned char)c == '\0')
		return ((char *)&s[len]);
	while (len > 0)
	{
		len--;
		if (s[len] == (unsigned char)c)
			return ((char *)&s[len]);
	}
	return (NULL);
}

// int main(void)
// {
// 	const char *test_str = "Hello, World!";
// 	char c1 = 'o';
// 	char c2 = 'H';
// 	char c3 = 'x';
// 	char c4 = '\0';
// 	char *result_custom;
// 	char *result_original;

// 	printf("Testing ft_strrchr against strrchr:\n");

// 	// Test case 1: Last occurrence of 'o'
// 	result_custom = ft_strrchr(test_str, c1);
// 	result_original = strrchr(test_str, c1);
// 	printf("Searching for '%c':\n", c1);
// 	printf("libft: %s | string.h: %s\n", result_custom, result_original);

// 	// Test case 2: Last occurrence of 'H'
// 	result_custom = ft_strrchr(test_str, c2);
// 	result_original = strrchr(test_str, c2);
// 	printf("Searching for '%c':\n", c2);
// 	printf("libft: %s | string.h: %s\n", result_custom, result_original);

// 	// Test case 3: Character not in string
// 	result_custom = ft_strrchr(test_str, c3);
// 	result_original = strrchr(test_str, c3);
// 	printf("Searching for '%c':\n", c3);
// 	printf("libft: %s | string.h: %s\n", result_custom, result_original);

// 	// Test case 4: Null terminator
// 	result_custom = ft_strrchr(test_str, c4);
// 	result_original = strrchr(test_str, c4);
// 	printf("Searching for '\\0':\n");
// 	printf("libft: %s | string.h: %s\n", result_custom, result_original);

// 	return (0);
// }
