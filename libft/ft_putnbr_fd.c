/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhamich <nkhamich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 15:51:05 by nkhamich          #+#    #+#             */
/*   Updated: 2024/10/17 20:08:15 by nkhamich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	num;

	if (n == INT_MIN)
	{
		write (fd, "-2147483648", 11);
		return ;
	}
	else if (n < 0)
	{
		write (fd, "-", 1);
		n *= -1;
	}
	if (n < 10)
	{
		num = n + '0';
		write (fd, &num, 1);
	}
	else if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
		num = (n % 10) + '0';
		write(fd, &num, 1);
	}
}

// int main(void)
// {
// 	ft_putnbr_fd(-9143647, 1);
// 	return (0);
// }