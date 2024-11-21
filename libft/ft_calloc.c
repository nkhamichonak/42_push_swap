/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhamich <nkhamich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 12:41:07 by nkhamich          #+#    #+#             */
/*   Updated: 2024/10/18 12:20:43 by nkhamich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*space;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	if (size > SIZE_MAX / nmemb)
		return (NULL);
	space = malloc(nmemb * size);
	if (space == NULL)
		return (NULL);
	ft_memset(space, 0, nmemb * size);
	return (space);
}

// int	main(void)
// {
// 	// Test case 1: Allocate memory for 5 integers
// 	int *arr_custom = (int *)ft_calloc(5, sizeof(int));
// 	int *arr_original = (int *)calloc(5, sizeof(int));

// 	printf("Test case 1: Allocate 5 integers\n");
// 	printf("libft: ");
// 	for (int i = 0; i < 5; i++) {
// 		printf("%d ", arr_custom[i]);
// 	}
// 	printf("| string.h: ");
// 	for (int i = 0; i < 5; i++) {
// 		printf("%d ", arr_original[i]);
// 	}
// 	printf("\n");

// 	// Test case 2: Allocate memory for 0 elements
// 	int *arr_custom_zero = (int *)ft_calloc(0, sizeof(int));
// 	int *arr_original_zero = (int *)calloc(0, sizeof(int));

// 	printf("Test case 2: Allocate 0 ints (exp. to return a pointer address)\n");
// 	printf("libft: %p | string.h: %p\n", arr_custom_zero, arr_original_zero);

// 	// Test case 3: Allocate a large amount of memory
// 	int *arr_custom_large = (int *)ft_calloc(1000, sizeof(int));
// 	int *arr_original_large = (int *)calloc(1000, sizeof(int));

// 	printf("Test case 3: Allocate 1000 integers (print first 5)\n");
// 	printf("libft: ");
// 	for (int i = 0; i < 5; i++) {
// 		printf("%d ", arr_custom_large[i]);
// 	}
// 	printf("| string.h: ");
// 	for (int i = 0; i < 5; i++) {
// 		printf("%d ", arr_original_large[i]);
// 	}
// 	printf("\n");

// 	free(arr_custom);
// 	free(arr_original);
// 	free(arr_custom_zero);
// 	free(arr_original_zero);
// 	free(arr_custom_large);
// 	free(arr_original_large);

// 	return (0);
// }
