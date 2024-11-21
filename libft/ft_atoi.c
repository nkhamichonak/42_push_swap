/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhamich <nkhamich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 11:27:46 by nkhamich          #+#    #+#             */
/*   Updated: 2024/10/17 17:16:55 by nkhamich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	sign;
	int	num;

	sign = 1;
	num = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = sign * (-1);
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		num = (num * 10) + (*str - '0');
		str++;
	}
	return (num * sign);
}

// void test_ft_atoi(const char *str)
// {
// 	int result_custom = ft_atoi(str);
// 	int result_original = atoi(str);

// 	printf("Input: '%s'\n", str);
// 	printf("libft: %d | string.h: %d\n\n", result_custom, result_original);
// }
// int main(void)
// {
// 	// Test cases
// 	test_ft_atoi("123");
// 	test_ft_atoi("-123");
// 	test_ft_atoi("   42");
// 	test_ft_atoi("2147483647"); // INT_MAX
// 	test_ft_atoi("-2147483648"); // INT_MIN
// 	test_ft_atoi("2147483648"); // Out of range
// 	test_ft_atoi("-2147483649"); // Out of range
// 	test_ft_atoi("abc123"); // Invalid input
// 	test_ft_atoi(""); // Empty string
// 	test_ft_atoi("   +42");
// 	test_ft_atoi("   -42");

// 	return (0);
// }
