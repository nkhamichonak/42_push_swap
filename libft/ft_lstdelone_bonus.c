/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhamich <nkhamich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 14:27:46 by nkhamich          #+#    #+#             */
/*   Updated: 2024/10/18 11:38:06 by nkhamich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	del(lst->content);
	free(lst);
}

// void	free_content(void *content)
// {
// 	free(content);
// }

// int main(void) 
// {
// 	t_list *node = ft_lstnew(malloc(sizeof(int)));
// 	*(int *)(node->content) = 42;
// 	printf("Content before deletion: %d\n", *(int *)(node->content));
// 	ft_lstdelone(node, free_content);
// 	if (node->content == NULL)
// 		printf("Node deleted successfully.\n");
// 	else
// 		printf("Node deletion failed.\n");
// 	return (0);
// }
