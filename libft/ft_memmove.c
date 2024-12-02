/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhamich <nkhamich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 14:30:00 by nkhamich          #+#    #+#             */
/*   Updated: 2024/12/02 13:13:31 by nkhamich         ###   ########.fr       */
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
