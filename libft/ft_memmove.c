/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhamich <nkhamich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 14:30:00 by nkhamich          #+#    #+#             */
/*   Updated: 2024/10/18 12:05:26 by nkhamich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	copy_backwards(unsigned char *dest, unsigned char *src, size_t n)
{
	size_t	len;

	len = n;
	while (len > 0)
	{
		len--;
		dest[len] = src[len];
	}
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*ptr_src;
	unsigned char	*ptr_dest;

	ptr_src = (unsigned char *)src;
	ptr_dest = (unsigned char *)dest;
	if (ptr_dest < ptr_src)
		ft_memcpy(dest, src, n);
	else
		copy_backwards(ptr_dest, ptr_src, n);
	return (dest);
}

// int main(void)
// {
// 	char	non_overlap_src[20] = "Alpacas are awesome";
// 	char	non_overlap_dest[20] = "Hello, World!";

// 	printf("NO OVERLAP\nBefore non-overlapping ft_memmove:\n");
// 	printf("Source: %s\n", non_overlap_src);
// 	printf("Destination: %s\n", non_overlap_dest);

// 	ft_memmove(non_overlap_dest, non_overlap_src, 6);
// 	printf("\nAfter ft_memmove:\n");
// 	printf("Source: %s\n", non_overlap_src);
// 	printf("Destination: %s\n", non_overlap_dest);

// 	strcpy(non_overlap_dest, "Hello, World!");

// 	memmove(non_overlap_dest, non_overlap_src, 6);
// 	printf("\nAfter standard memmove:\n");
// 	printf("Source: %s\n", non_overlap_src);
// 	printf("Destination: %s\n", non_overlap_dest);

// 	char	overlap_str[15] = "Hello, World!";
// 	printf("\nWITH OVERLAP\n\nBefore overlapping ft_memmove:\n");
// 	printf("Original: %s\n", overlap_str);

// 	ft_memmove(overlap_str + 7, overlap_str, 6);
// 	printf("\nAfter ft_memmove with overlap:\n");
// 	printf("Result: %s\n", overlap_str);

// 	strcpy(overlap_str, "Hello, World!");

// 	memmove(overlap_str + 7, overlap_str, 6);
// 	printf("\nAfter standard memmove with overlap:\n");
// 	printf("Result: %s\n\n", overlap_str);
// 	return (0);
// }
