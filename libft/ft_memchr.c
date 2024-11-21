/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhamich <nkhamich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 11:27:46 by nkhamich          #+#    #+#             */
/*   Updated: 2024/10/17 14:52:29 by nkhamich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	i = 0;
	ptr = (unsigned char *)s;
	while (i < n)
	{
		if (ptr[i] == (unsigned char)c)
			return ((void *)(ptr + i));
		i++;
	}
	return (NULL);
}

// int main(void)
// {
// 	const char *test_str = "Hello, World!";
// 	char *res_libft;
// 	char *res_orig;
// 	char target_char;

// 	// Test case 1: Normal case
// 	target_char = 'o';
// 	res_libft = (char *)ft_memchr(test_str, target_char, strlen(test_str));
// 	res_orig = (char *)memchr(test_str, target_char, strlen(test_str));
// 	printf("Searching for '%c':\n", target_char);
// 	printf("libft: %s | string.h: %s\n", res_libft, res_orig);

// 	// Test case 2: Character not present
// 	target_char = 'x';
// 	res_libft = (char *)ft_memchr(test_str, target_char, strlen(test_str));
// 	res_orig = (char *)memchr(test_str, target_char, strlen(test_str));
// 	printf("Searching for '%c':\n", target_char);
// 	printf("libft: %s | string.h: %s\n", res_libft, res_orig);

// 	// Test case 3: Searching for null terminator
// 	target_char = '\0';
// 	res_libft = (char *)ft_memchr(test_str, target_char, strlen(test_str) + 1);
// 	res_orig = (char *)memchr(test_str, target_char, strlen(test_str) + 1);
// 	printf("Searching for '\\0':\n");
// 	printf("libft: %s | string.h: %s\n", res_libft, res_orig);

// 	// Test case 4: Searching at the start of the string
// 	target_char = 'H';
// 	res_libft = (char *)ft_memchr(test_str, target_char, strlen(test_str));
// 	res_orig = (char *)memchr(test_str, target_char, strlen(test_str));
// 	printf("Searching for '%c':\n", target_char);
// 	printf("libft: %s | string.h: %s\n", res_libft, res_orig);

// 	// Test case 5: Searching in empty string
// 	const char *empty_str = "";
// 	target_char = 'a';
// 	res_libft = (char *)ft_memchr(empty_str, target_char, strlen(empty_str));
// 	res_orig = (char *)memchr(empty_str, target_char, strlen(empty_str));
// 	printf("Searching in empty string for '%c':\n", target_char);
// 	printf("libft: %s | string.h: %s\n", res_libft, res_orig);

// 	return (0);
// }
