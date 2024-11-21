/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhamich <nkhamich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 14:24:54 by nkhamich          #+#    #+#             */
/*   Updated: 2024/10/17 20:29:34 by nkhamich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

// int main(void) 
// {
// 	t_list *list = ft_lstnew("First");
// 	ft_lstadd_front(&list, ft_lstnew("Second"));
// 	ft_lstadd_front(&list, ft_lstnew("Third"));

// 	t_list *last = ft_lstlast(list);
// 	if (last)
// 		printf("Last element: %s\n", (char *)last->content);
// 	else
// 		printf("List is empty.\n");
// 	t_list *temp;
// 	while (list != NULL) 
// 	{
// 		temp = list->next;
// 		free(list);
// 		list = temp;
// 	}
// 	return (0);
// }