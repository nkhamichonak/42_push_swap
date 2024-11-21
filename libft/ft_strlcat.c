/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhamich <nkhamich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 10:01:26 by nkhamich          #+#    #+#             */
/*   Updated: 2024/10/17 14:42:32 by nkhamich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	len_till_size(const char *dest, size_t size)
{
	size_t	i;

	i = 0;
	while (dest[i] && i < size)
		i++;
	return (i);
}

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	dlen;
	size_t	slen;

	i = 0;
	dlen = len_till_size(dest, size);
	slen = ft_strlen(src);
	if (size == 0)
		return (slen);
	if (size == dlen)
		return (dlen + slen);
	while (i < (size - dlen - 1) && src[i])
	{
		dest[dlen + i] = src[i];
		i++;
	}
	dest[dlen + i] = '\0';
	return (dlen + slen);
}

// int	main(void)
// {
// 	char		dest1[20];
// 	const char	*src = "World";

// 	strcpy(dest1, "Hello ");
// 	size_t ret1 = ft_strlcat(dest1, src, 11);
// 	printf("%s\n", dest1);
// 	printf("Return value: %zu\n", ret1);
// 	return (0);
// }
