/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhamich <nkhamich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 11:59:53 by nkhamich          #+#    #+#             */
/*   Updated: 2024/10/17 17:13:19 by nkhamich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	needle_len;

	i = 0;
	if (!*needle)
		return ((char *)haystack);
	needle_len = ft_strlen(needle);
	while (haystack[i] && (i + needle_len) <= len)
	{
		j = 0;
		while ((haystack[i + j] == needle[j]) && (needle[j]))
			j++;
		if (needle[j] == '\0')
			return ((char *)&haystack[i]);
		i++;
	}
	return (NULL);
}

// int main(void)
// {
// 	const char *haystack = "Hello, World!";
// 	const char *needle1 = "World";
// 	const char *needle2 = "lo";
// 	const char *needle3 = "";
// 	const char *needle4 = "xyz";
// 	const char *needle5 = "World!";

// 	char *result_custom;
// 	size_t len = 12;

// 	// Test case 1: Normal substring
// 	result_custom = ft_strnstr(haystack, needle1, len);
// 	printf("Test 1 - Searching for 'World':\n");
// 	printf("%s\n\n", result_custom);

// 	// Test case 2: Substring partially inside haystack
// 	result_custom = ft_strnstr(haystack, needle2, len);
// 	printf("Test 2 - Searching for 'lo':\n");
// 	printf("%s\n\n", result_custom);

// 	// Test case 3: Searching for an empty string
// 	result_custom = ft_strnstr(haystack, needle3, len);
// 	printf("Test 3 - Searching for empty string:\n");
// 	printf("%s\n\n", result_custom);

// 	// Test case 4: Searching for a non-existent substring
// 	result_custom = ft_strnstr(haystack, needle4, len);
// 	printf("Test 4 - Searching for 'xyz':\n");
// 	printf("%s\n\n", result_custom);

// 	// Test case 5: Searching for substring that's longer than len
// 	result_custom = ft_strnstr(haystack, needle5, len);
// 	printf("Test 5 - Searching for 'World!' (exceeds len):\n");
// 	printf("%s\n\n", result_custom);

// 	return (0);
// }
