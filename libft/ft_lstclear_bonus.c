/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhamich <nkhamich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 14:28:44 by nkhamich          #+#    #+#             */
/*   Updated: 2024/10/18 11:45:18 by nkhamich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*temp;

	while (*lst)
	{
		temp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = temp;
	}
	*lst = NULL;
}

// void	free_content(void *content)
// {
// 	free(content);  // Free the content memory
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

// 	t_list *current = head;
// 	printf("List contents before clearing: ");
// 	while (current)
// 	{
// 		printf("%d ", *(int *)(current->content));
// 		current = current->next;
// 	}
// 	printf("\n");

// 	ft_lstclear(&head, free_content);

// 	if (head == NULL)
// 		printf("List cleared successfully.\n");
// 	else
// 		printf("List clear failed.\n");
// 	return (0);
// }