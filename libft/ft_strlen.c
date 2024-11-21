/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhamich <nkhamich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 11:27:46 by nkhamich          #+#    #+#             */
/*   Updated: 2024/10/17 11:59:07 by nkhamich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

// int	main(void)
// {
// 	const char *str = "Alpacas are awesome!";
// 	size_t length1 = ft_strlen(str);
// 	size_t length2 = strlen(str);
// 	printf("Length of the string:\n");
// 	printf("libft: %zu; string.h: %zu\n", length1, length2);
// 	return (0);
// }
