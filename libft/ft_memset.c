/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhamich <nkhamich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 12:09:53 by nkhamich          #+#    #+#             */
/*   Updated: 2024/10/17 12:01:07 by nkhamich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	i = 0;
	ptr = (unsigned char *)s;
	while (i < n)
	{
		ptr[i] = (unsigned char)c;
		i++;
	}
	return (s);
}

// int	main(void)
// {
// 	char	test1[10];
// 	char	test2[10];

// 	ft_memset(test1, 'A', sizeof(test1));
// 	memset(test2, 'A', sizeof(test2));

// 	printf("libft:\n");
// 	for (size_t i = 0; i < sizeof(test1); i++)
// 		printf("%c ", test1[i]);
// 	printf("\nstring.h\n");
// 	for (size_t i = 0; i < sizeof(test2); i++)
// 		printf("%c ", test2[i]);
// 	printf("\n");
// 	return (0);
// }
