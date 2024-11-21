/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhamich <nkhamich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 14:26:44 by nkhamich          #+#    #+#             */
/*   Updated: 2024/10/17 20:44:48 by nkhamich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last_node;

	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	last_node = ft_lstlast(*lst);
	last_node->next = new;
}

// int main(void) 
// {
// 	t_list *list = NULL;

// 	t_list *new_node = ft_lstnew("1");
// 	ft_lstadd_back(&list, new_node);

// 	new_node = ft_lstnew("2");
// 	ft_lstadd_back(&list, new_node);

// 	t_list *current = list;
// 	while (current) {
// 		printf("%s ", (char *)current->content);
// 		current = current->next;
// 	}
// 	printf("\n");

// 	current = list;
// 	while (current) {
// 		t_list *next = current->next;
// 		free(current);
// 		current = next;
// 	}
// 	return (0);
// }