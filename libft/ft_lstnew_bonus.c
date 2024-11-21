/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhamich <nkhamich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 11:32:52 by nkhamich          #+#    #+#             */
/*   Updated: 2024/10/18 11:28:34 by nkhamich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}

// int main(void) 
// {
// 	int content = 42;
// 	t_list *node = ft_lstnew(&content);

// 	if (node != NULL && *(int *)(node->content) == 42 && node->next == NULL) 
// 		printf("OK: Node created with content = %d\n", *(int *)(node->content));
// 	else
// 		printf("KO: Node not created as expected.\n");
// 	free(node);
// 	return (0);
// }