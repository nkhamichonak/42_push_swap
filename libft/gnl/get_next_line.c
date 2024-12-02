/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhamich <nkhamich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 16:10:50 by natallia          #+#    #+#             */
/*   Updated: 2024/11/07 14:56:13 by nkhamich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*extract_line(char *stored_data, char *newline)
{
	size_t		i;
	size_t		len;
	char		*line;

	if (newline)
		len = newline - stored_data + 1;
	else
		len = ft_strlen(stored_data);
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

	if (newline == NULL || *(newline + 1) == '\0')
		return (ft_free(&stored_data));
	remainder = ft_strdup(newline + 1);
	if (remainder == NULL)
	{
		*error = true;
		return (ft_free(&stored_data));
	}
	ft_free(&stored_data);
	return (remainder);
}

static char	*append_and_free(char *stored_data, char *buffer)
{
	size_t	stored_len;
	size_t	buffer_len;
	char	*new_data;

	stored_len = ft_strlen(stored_data);
	buffer_len = ft_strlen(buffer);
	new_data = malloc((stored_len + buffer_len + 1) * sizeof(char));
	if (new_data == NULL)
		return (ft_free(&stored_data));
	if (stored_data)
	{
		copy_string(new_data, stored_data);
		ft_free(&stored_data);
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
		return (ft_free(&stored_data));
	bytes_read = 0;
	while (!find_newline(stored_data))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
		{
			ft_free(&buffer);
			if (bytes_read == -1)
				return (ft_free(&stored_data));
			else
				return (stored_data);
		}
		buffer[bytes_read] = '\0';
		stored_data = append_and_free(stored_data, buffer);
		if (stored_data == NULL)
			return (ft_free(&buffer));
	}
	ft_free (&buffer);
	return (stored_data);
}

char	*get_next_line(int fd)
{
	static char		*stored_data;
	char			*current_line;
	char			*newline;
	bool			error_flag;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > INT_MAX)
		return (NULL);
	stored_data = read_and_store_data(fd, stored_data);
	if (stored_data == NULL)
		return (NULL);
	newline = find_newline(stored_data);
	current_line = extract_line(stored_data, newline);
	if (current_line == NULL)
		return (ft_free(&stored_data));
	error_flag = 0;
	stored_data = extract_remainder(stored_data, newline, &error_flag);
	if (error_flag)
		return (ft_free(&current_line));
	return (current_line);
}
