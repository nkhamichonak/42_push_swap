/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhamich <nkhamich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 12:41:07 by nkhamich          #+#    #+#             */
/*   Updated: 2024/10/17 14:43:00 by nkhamich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*ptr;

	i = 0;
	ptr = (char *)s;
	while (i < n)
	{
		ptr[i] = '\0';
		i++;
	}
}

// int	main(void)
// {
// 	char	test1[10];
// 	char	test2[10];

// 	// initialise two strings with 'A's
// 	for (size_t i = 0; i < sizeof(test1); i++)
// 		test1[i] = 'A';
// 	for (size_t i = 0; i < sizeof(test2); i++)
// 		test2[i] = 'A';

// 	// run the custom ft on 'test1' and original on 'test2'
// 	ft_bzero(test1, sizeof(test1));
// 	bzero(test2, sizeof(test2));

// 	// print the string 'test1' itself & custom ft test outcome
// 	printf("libft:\n");
// 	for (size_t i = 0; i < sizeof(test1); i++)
// 		printf("%c ", test1[i]);
// 	printf("\n");

// 	int ft_bzero_success = 1;
// 	for (size_t i = 0; i < sizeof(test1); i++)
// 	{
// 		if (test1[i] != '\0')
// 		{
// 			ft_bzero_success = 0;
// 			break;
// 		}
// 	}
// 	if (ft_bzero_success)
// 		printf("ft_bzero successful\n");
// 	else
// 		printf("ft_bzero failed\n");

// 	// print the string 'test2' itself & original ft test outcome
// 	printf("strings.h:\n");
// 	for (size_t i = 0; i < sizeof(test2); i++)
// 		printf("%c ", test2[i]);
// 	printf("\n");

// 	int bzero_success = 1;
// 	for (size_t i = 0; i < sizeof(test2); i++)
// 	{
// 		if (test2[i] != '\0')
// 		{
// 			bzero_success = 0;
// 			break;
// 		}
// 	}
// 	if (bzero_success)
// 		printf("bzero successful\n");
// 	else
// 		printf("bzero failed\n");
// 	return (0);
// }
