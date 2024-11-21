/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhamich <nkhamich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 11:27:46 by nkhamich          #+#    #+#             */
/*   Updated: 2024/10/17 17:27:21 by nkhamich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	slen;
	char	*sub;

	slen = ft_strlen(s);
	if (start >= slen || !slen)
		return (ft_strdup(""));
	if (start + len > slen)
		len = slen - start;
	sub = malloc((len + 1) * sizeof(char));
	if (sub == NULL)
		return (NULL);
	i = 0;
	while (i < len && s[start + i])
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

// void test_ft_substr(char *s, unsigned int start, size_t len, 
// 					const char *expected)
// {
// 	char *result_custom = ft_substr(s, start, len);

// 	// Compare the result of ft_substr with the expected value
// 	if (strcmp(result_custom, expected) == 0)
// 		printf("OK: ft_substr(\"%s\", %u, %zu) == \"%s\"\n", 
// 			   s, start, len, result_custom);
// 	else
// 		printf("FAIL: ft_substr(\"%s\", %u, %zu) == \"%s\", expected \"%s\"\n",
// 			   s, start, len, result_custom, expected);

// 	free(result_custom);
// }

// int main(void)
// {
// 	// Test case 1: Normal substring
// 	test_ft_substr("Hello, World!", 7, 5, "World");

// 	// Test case 2: Substring from the beginning
// 	test_ft_substr("Hello, World!", 0, 5, "Hello");

// 	// Test case 3: Start index beyond string length
// 	test_ft_substr("Hello", 10, 5, "");

// 	// Test case 4: Start index equals string length
// 	test_ft_substr("Hello", 5, 5, "");

// 	// Test case 5: Length exceeds string size
// 	test_ft_substr("Hello", 2, 10, "llo");

// 	// Test case 6: Empty input string
// 	test_ft_substr("", 0, 5, "");

// 	// Test case 7: Length is zero (should return an empty string)
// 	test_ft_substr("Hello, World!", 5, 0, "");

// 	// Test case 8: Large length compared to string size
// 	test_ft_substr("Hello", 0, 100, "Hello");

// 	return (0);
// }
