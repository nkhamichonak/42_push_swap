/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhamich <nkhamich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 13:57:56 by nkhamich          #+#    #+#             */
/*   Updated: 2024/10/17 17:43:12 by nkhamich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trimmed_str;
	size_t	start;
	size_t	end;
	size_t	len;

	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	end = ft_strlen(s1);
	while (end > start && ft_strchr(set, s1[end - 1]))
		end--;
	len = end - start;
	trimmed_str = malloc((len + 1) * sizeof(char));
	if (trimmed_str == NULL)
		return (NULL);
	ft_memcpy(trimmed_str, s1 + start, len);
	trimmed_str[len] = '\0';
	return (trimmed_str);
}

// void test_strtrim(const char *s1, const char *set, const char *expected) 
// {
// 	char *result = ft_strtrim(s1, set);

// 	if (strcmp(result, expected) == 0) {
// 		printf("OK: ft_strtrim(\"%s\", \"%s\") "
// 				"-> \"%s\"\n", s1, set, result);
// 	} else {
// 		printf("Failed: ft_strtrim(\"%s\", \"%s\") -> \"%s\", "
// 				"expected \"%s\"\n", s1, set, result, expected);
// 	}
// 	free(result);
// }

// int main() {
// 	test_strtrim("   Hello, World!   ", " ", "Hello, World!");
// 	test_strtrim("!!!Hello!!!", "!", "Hello");
// 	test_strtrim("abc", "xyz", "abc");
// 	test_strtrim("", " ", "");
// 	test_strtrim("   ", " ", "");

// 	return (0);
// }