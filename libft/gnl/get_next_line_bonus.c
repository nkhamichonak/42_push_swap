/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhamich <nkhamich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 19:53:10 by natallia          #+#    #+#             */
/*   Updated: 2024/12/03 11:46:05 by nkhamich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*extract_line(char *stored_data, char *newline)
{
	size_t		i;
	size_t		len;
	char		*line;

	if (newline)
		len = newline - stored_data + 1;
	else
		len = ft_strlen_gnl_bonus(stored_data);
	line = malloc((len + 1) * sizeof(char));
	if (line == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		line[i] = stored_data[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*extract_remainder(char *stored_data, char *newline, bool *error)
{
	char	*remainder;
	size_t	i;

	if (newline == NULL || *(newline + 1) == '\0')
		return (free(stored_data), NULL);
	remainder = malloc((ft_strlen_gnl_bonus(newline + 1) + 1) * sizeof(char));
	if (remainder == NULL)
	{
		*error = true;
		return (free(stored_data), NULL);
	}
	i = 0;
	while (newline[1 + i])
	{
		remainder[i] = newline[1 + i];
		i++;
	}
	remainder[i] = '\0';
	free(stored_data);
	stored_data = NULL;
	return (remainder);
}

static char	*append_and_free(char *stored_data, char *buffer)
{
	size_t	stored_len;
	size_t	buffer_len;
	char	*new_data;

	stored_len = ft_strlen_gnl_bonus(stored_data);
	buffer_len = ft_strlen_gnl_bonus(buffer);
	new_data = malloc((stored_len + buffer_len + 1) * sizeof(char));
	if (new_data == NULL)
		return (free(stored_data), NULL);
	if (stored_data)
	{
		copy_string(new_data, stored_data);
		free(stored_data);
	}
	copy_string(new_data + stored_len, buffer);
	return (new_data);
}

static char	*read_and_store_data(int fd, char *stored_data)
{
	char	*buffer;
	int		bytes_read;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (buffer == NULL)
		return (free(stored_data), NULL);
	bytes_read = 0;
	while (!find_newline(stored_data))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
		{
			free(buffer);
			if (bytes_read == -1)
				return (free(stored_data), NULL);
			else
				return (stored_data);
		}
		buffer[bytes_read] = '\0';
		stored_data = append_and_free(stored_data, buffer);
		if (stored_data == NULL)
			return (free(buffer), NULL);
	}
	free (buffer);
	return (stored_data);
}

char	*get_next_line(int fd)
{
	static t_fd_list	*fd_list;
	t_fd_list			*node;
	char				*current_line;
	char				*newline;
	bool				error;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > INT_MAX)
		return (NULL);
	node = find_fd_node(&fd_list, fd);
	if (!node)
		return (NULL);
	node->stored_data = read_and_store_data(fd, node->stored_data);
	if (node->stored_data == NULL)
		return (remove_fd_node(&fd_list, fd));
	newline = find_newline(node->stored_data);
	current_line = extract_line(node->stored_data, newline);
	if (current_line == NULL)
		return (remove_fd_node(&fd_list, fd));
	error = 0;
	node->stored_data = extract_remainder(node->stored_data, newline, &error);
	if (error)
		return (free(current_line), remove_fd_node(&fd_list, fd));
	if (node->stored_data == NULL)
		remove_fd_node(&fd_list, fd);
	return (current_line);
}
