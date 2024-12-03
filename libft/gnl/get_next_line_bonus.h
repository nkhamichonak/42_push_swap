/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhamich <nkhamich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 19:47:30 by natallia          #+#    #+#             */
/*   Updated: 2024/12/03 11:46:08 by nkhamich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_fd_list
{
	int					fd;
	char				*stored_data;
	struct s_fd_list	*next;
}	t_fd_list;

char		*get_next_line(int fd);
size_t		ft_strlen_gnl_bonus(const char *str);
char		*find_newline(char *str);
void		copy_string(char *dest, const char *src);
t_fd_list	*find_fd_node(t_fd_list **head, int fd);
char		*remove_fd_node(t_fd_list **head, int fd);

#endif
