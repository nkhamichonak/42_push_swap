/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhamich <nkhamich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 12:09:53 by nkhamich          #+#    #+#             */
/*   Updated: 2024/10/17 20:02:59 by nkhamich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write (fd, &c, 1);
}

// int main(void)
// {
// 	// Test case 1: Output to stdout (fd = 1)
// 	printf("Test 1: Expected output -> A :\n");
// 	ft_putchar_fd('A', 1);
// 	printf("\n");

// 	// Test case 2: Output to stdout again
// 	printf("Test 2: Expected output -> B :\n");
// 	ft_putchar_fd('B', 1);
// 	printf("\n");

// 	// Test case 3: Output a new line character to stdout
// 	printf("Test 3: Expected output -> (a new line):\n");
// 	ft_putchar_fd('\n', 1); 
// 	printf("Done!\n");

// 	return (0);
// }
