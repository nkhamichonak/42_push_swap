/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhamich <nkhamich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 13:00:12 by nkhamich          #+#    #+#             */
/*   Updated: 2024/10/17 19:50:46 by nkhamich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	int_length(int n)
{
	int	len;

	len = 0;
	if (n < 0)
	{
		n *= -1;
		len++;
	}
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static char	*convert_to_str(char *str, int n, int len)
{
	if (n < 0)
	{
		n *= -1;
		*str = '-';
	}
	str[len] = '\0';
	while (n > 0)
	{
		str[len - 1] = (n % 10) + '0';
		n /= 10;
		len--;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*str;

	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = int_length(n);
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	return (convert_to_str(str, n, len));
}

// int main(void)
// {
// 	int test_values[] = {0, 123, -123, 2147483647, -2147483648};
// 	const char *exp_res[] = {"0", "123", "-123", "2147483647", "-2147483648"};
// 	char *result;

// 	for (int i = 0; i < 5; i++)
// 	{
// 		result = ft_itoa(test_values[i]);
// 		printf("Test case: %d\n", test_values[i]);
// 		printf("Result: %s | Expected: %s\n\n", result, exp_res[i]);
// 		free(result);
// 	}
// 	return (0);
// }
