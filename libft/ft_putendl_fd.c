/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhamich <nkhamich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 15:46:04 by nkhamich          #+#    #+#             */
/*   Updated: 2024/10/17 20:07:40 by nkhamich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	write (fd, s, ft_strlen(s));
	write (fd, "\n", 1);
}

// int main(void)
// {
// 	ft_putendl_fd("Hello, World!", 1);
// 	return (0);
// }
