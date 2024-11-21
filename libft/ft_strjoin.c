/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhamich <nkhamich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 13:25:19 by nkhamich          #+#    #+#             */
/*   Updated: 2024/10/17 17:36:45 by nkhamich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*big_string;

	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	big_string = malloc((s1_len + s2_len + 1) * sizeof(char));
	if (big_string == NULL)
		return (NULL);
	ft_memcpy(big_string, s1, s1_len);
	ft_memcpy(big_string + s1_len, s2, s2_len);
	big_string[s1_len + s2_len] = '\0';
	return (big_string);
}

// int	main(void)
// {
// 	// Test case 1: Joining two non-empty strings
// 	char *s1 = "Hello, ";
// 	char *s2 = "World!";
// 	char *result_custom = ft_strjoin(s1, s2);
// 	char *expected = "Hello, World!";

// 	printf("Test 1: Joining two non-empty strings\n");
// 	printf("Expected: %s | Result: %s\n", expected, result_custom);
// 	if (strcmp(result_custom, expected) == 0)
// 		printf("Test 1 Passed\n");
// 	else
// 		printf("Test 1 Failed\n");
// 	free(result_custom);

// 	// Test case 2: First string is NULL
// 	s1 = NULL;
// 	s2 = "World!";
// 	result_custom = ft_strjoin(s1, s2);
// 	expected = "World!";

// 	printf("\nTest 2: First string is NULL\n");
// 	printf("Expected: %s | Result: %s\n", expected, result_custom);
// 	if (strcmp(result_custom, expected) == 0)
// 		printf("Test 2 Passed\n");
// 	else
// 		printf("Test 2 Failed\n");
// 	free(result_custom);

// 	// Test case 3: Second string is NULL
// 	s1 = "Hello, ";
// 	s2 = NULL;
// 	result_custom = ft_strjoin(s1, s2);
// 	expected = "Hello, ";

// 	printf("\nTest 3: Second string is NULL\n");
// 	printf("Expected: %s | Result: %s\n", expected, result_custom);
// 	if (strcmp(result_custom, expected) == 0)
// 		printf("Test 3 Passed\n");
// 	else
// 		printf("Test 3 Failed\n");
// 	free(result_custom);

// 	return (0);
// }
