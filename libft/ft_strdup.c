/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhamich <nkhamich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 18:40:09 by nkhamich          #+#    #+#             */
/*   Updated: 2024/10/17 17:20:03 by nkhamich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	i;
	char	*dest;

	dest = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

// int main(void)
// {
// 	const char *test_strings[] = {
// 		"Hello, World!",
// 		"",
// 		"This is a longer string to test strdup functionality.",
// 		"Test with special characters: @#&*($%)!",
// 		"1234567890",
// 		NULL
// 	};

// 	int i = 0;
// 	while (test_strings[i])
// 	{
// 		char *result_custom = ft_strdup(test_strings[i]);
// 		char *result_original = strdup(test_strings[i]);

// 		printf("Test %d: \"%s\"\n", i + 1, test_strings[i]);
// 		if (result_custom && result_original)
// 		{
// 			printf("Custom strdup:   \"%s\"\n", result_custom);
// 			printf("Original strdup: \"%s\"\n", result_original);
// 		}

// 		if (strcmp(result_custom, result_original) == 0)
// 			printf("Result: PASS\n");
// 		else
// 			printf("Result: FAIL\n");

// 		free(result_custom);
// 		free(result_original);

// 		printf("----------------------\n");
// 		i++;
// 	}

// 	return (0);
// }
