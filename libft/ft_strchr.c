/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natallia <natallia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 11:27:46 by nkhamich          #+#    #+#             */
/*   Updated: 2024/10/27 13:53:32 by natallia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (unsigned char)c)
			return ((char *)s);
		s++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)s);
	return (NULL);
}

// int main(void)
// {
// 	const char *str = "Hello, World!";
// 	char c1 = 'o';
// 	char c2 = 'W';
// 	char c3 = 'z';
// 	char c4 = '\0';

// 	printf("Testing ft_strchr against strchr:\n");

// 	// Test case 1: Character present in the string
// 	char *libft_res1 = ft_strchr(str, c1);
// 	char *orig_res1 = strchr(str, c1);
// 	printf("'%c'': libft: %s | string.h: %s\n", c1, libft_res1, orig_res1);

// 	// Test case 2: Character present in the string
// 	char *libft_res2 = ft_strchr(str, c2);
// 	char *orig_res2 = strchr(str, c2);
// 	printf("'%c': libft: %s | string.h: %s\n", c2, libft_res2, orig_res2);

// 	// Test case 3: Character not present in the string
// 	char *libft_res3 = ft_strchr(str, c3);
// 	char *orig_res3 = strchr(str, c3);
// 	printf("'%c': libft: %s | string.h: %s\n", c3, libft_res3, orig_res3);

// 	// Test case 4: Null terminator
// 	char *libft_res4 = ft_strchr(str, c4);
// 	char *orig_res4 = strchr(str, c4);
// 	printf("'%c': libft: %s | string.h: %s\n", c4, libft_res4, orig_res4);

// 	return (0);
// }
