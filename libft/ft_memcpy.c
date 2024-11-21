/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhamich <nkhamich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 13:00:12 by nkhamich          #+#    #+#             */
/*   Updated: 2024/10/18 12:05:36 by nkhamich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*ptr_src;
	unsigned char	*ptr_dest;

	i = 0;
	ptr_src = (unsigned char *)src;
	ptr_dest = (unsigned char *)dest;
	while (i < n)
	{
		ptr_dest[i] = ptr_src[i];
		i++;
	}
	return (dest);
}

// int	main(void)
// {
// 	char	src[10];
// 	char	dest[10];

// 	// initialise source to 'A's and destination to 'B's
// 	printf("BEFORE COPY\nSource:\n");
// 	for (size_t i = 0; i < sizeof(src); i++)
// 	{
// 		src[i] = 'A';
// 		printf("%c ", src[i]);
// 	}
// 	printf("\nDestination:\n");
// 	for (size_t i = 0; i < sizeof(dest); i++)
// 	{
// 		dest[i] = 'B';
// 		printf("%c ", dest[i]);
// 	}

// 	// run custom ft to copy 4 bytes
// 	ft_memcpy(dest, src, 4);

// 	printf("\n\nAFTER COPY, libft\nSource:\n");
// 	for (size_t i = 0; i < sizeof(src); i++)
// 		printf("%c ", src[i]);
// 	printf("\nDestination:\n");
// 	for (size_t i = 0; i < sizeof(dest); i++)
// 		printf("%c ", dest[i]);

// 	// set destination back to all 'B's
// 	for (size_t i = 0; i < sizeof(dest); i++)
// 		dest[i] = 'B';

// 	// run original ft to copy 4 bytes
// 	memcpy(dest, src, 4);

// 	printf("\n\nAFTER COPY, string.h\nSource:\n");
// 	for (size_t i = 0; i < sizeof(src); i++)
// 		printf("%c ", src[i]);
// 	printf("\nDestination:\n");
// 	for (size_t i = 0; i < sizeof(dest); i++)
// 		printf("%c ", dest[i]);
// 	printf("\n");
// 	return (0);
// }
