/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhamich <nkhamich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 14:30:54 by nkhamich          #+#    #+#             */
/*   Updated: 2024/10/18 11:53:59 by nkhamich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}

// void	free_content(void *content)
// {
// 	free(content);
// }

// void	print_content(void *content)
// {
// 	printf("%d ", *(int *)content);
// }

// int main(void) 
// {
// 	t_list *head = ft_lstnew(malloc(sizeof(int)));
// 	*(int *)(head->content) = 1;

// 	t_list *second = ft_lstnew(malloc(sizeof(int)));
// 	*(int *)(second->content) = 2;
// 	ft_lstadd_back(&head, second);

// 	t_list *third = ft_lstnew(malloc(sizeof(int)));
// 	*(int *)(third->content) = 3;
// 	ft_lstadd_back(&head, third);

// 	printf("List contents: ");
// 	ft_lstiter(head, print_content);
// 	printf("\n");

// 	ft_lstclear(&head, free_content);
// 	return (0);
// }
