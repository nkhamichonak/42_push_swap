/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhamich <nkhamich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 09:39:51 by nkhamich          #+#    #+#             */
/*   Updated: 2024/10/17 19:57:30 by nkhamich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*result;
	size_t	i;

	result = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!result)
		return (NULL);
	i = 0;
	while (s[i])
	{
		result[i] = f(i, s[i]);
		i++;
	}
	result[i] = '\0';
	return (result);
}

// // Transformation function: converts characters to uppercase
// char transform(unsigned int index, char c) {
// 	return (c >= 'a' && c <= 'z') ? (c - 32 + (index * 0)) : c;
// }

// // Function to run a single test case
// void run_test(const char *input, char (*f)(unsigned int, char), 
//               const char *expected) {
// 	char *result = ft_strmapi(input, f);

// 	// Check if the result matches the expected outcome
// 	if (result && strcmp(result, expected) == 0) {
// 		printf("Test passed for input \"%s\": expected \"%s\", got \"%s\"\n", 
// 		       input, expected, result);
// 	} else {
// 		printf("Test failed for input \"%s\": expected \"%s\", got \"%s\"\n", 
// 		       input, expected, result ? result : "NULL");
// 	}
// 	free(result);
// }

// int main(void) 
// {
// 	run_test("abc", transform, "ABC");    // Lowercase to uppercase
// 	run_test("xyz", transform, "XYZ");    // Lowercase to uppercase
// 	run_test("", transform, "");           // Edge case: empty string
// 	run_test("A", transform, "A");         // Single uppercase char unchanged
// 	run_test("test", transform, "TEST");   // Lowercase to uppercase
// 	run_test("HELLO", transform, "HELLO"); // Uppercase chars unchanged
// 	return (0);
// }
