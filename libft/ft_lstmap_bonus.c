/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhamich <nkhamich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 14:31:56 by nkhamich          #+#    #+#             */
/*   Updated: 2024/10/18 11:58:15 by nkhamich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_node;
	void	*temp_content;

	new_list = NULL;
	while (lst)
	{
		temp_content = f(lst->content);
		if (temp_content == NULL)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		new_node = ft_lstnew(temp_content);
		if (new_node == NULL)
		{
			del(temp_content);
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_node);
		lst = lst->next;
	}
	return (new_list);
}

// void	free_content(void *content)
// {
// 	free(content);
// }

// void	*double_content(void *content)
// {
// 	int *new_value = malloc(sizeof(int));
// 	if (new_value == NULL)
// 		return (NULL);
// 	*new_value = *(int *)content * 2;
// 	return (new_value);
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

// 	t_list *new_list = ft_lstmap(head, double_content, free_content);

// 	printf("New list contents (doubled): ");
// 	ft_lstiter(new_list, print_content);
// 	printf("\n");

// 	ft_lstclear(&head, free_content);
// 	ft_lstclear(&new_list, free_content);
// 	return (0);
// }
