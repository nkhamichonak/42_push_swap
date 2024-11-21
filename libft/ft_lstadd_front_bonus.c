/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhamich <nkhamich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 14:17:29 by nkhamich          #+#    #+#             */
/*   Updated: 2024/10/17 20:18:46 by nkhamich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}

// int main(void) 
// {
// 	t_list *head = ft_lstnew("World");
// 	t_list *new_node = ft_lstnew("Hello");

// 	ft_lstadd_front(&head, new_node);

// 	printf("First node: %s\n", (char *)head->content);
// 	printf("Second node: %s\n", (char *)head->next->content);

// 	t_list *temp;
// 	while (head != NULL) 
// 	{
// 		temp = head->next;
// 		free(head);
// 		head = temp;
// 	}
// 	return (0);
// }
