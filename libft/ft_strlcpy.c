/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhamich <nkhamich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 12:28:29 by nkhamich          #+#    #+#             */
/*   Updated: 2024/10/17 14:37:13 by nkhamich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	if (size == 0)
		return (ft_strlen(src));
	i = 0;
	while (src[i] && i < (size - 1))
	{
		dest [i] = src [i];
		i++;
	}
	dest[i] = '\0';
	return (ft_strlen(src));
}

// int main(void)
// {
// 	char	dest1[20];

// 	const char *src = "Hello, Donuts!";

// 	size_t ret1 = ft_strlcpy(dest1, src, 5);
// 	printf("%s\n", dest1);
// 	printf("Return value: %zu \n", ret1);
// 	return (0);
// }
