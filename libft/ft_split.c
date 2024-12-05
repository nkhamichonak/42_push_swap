/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhamich <nkhamich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 15:06:21 by nkhamich          #+#    #+#             */
/*   Updated: 2024/12/04 10:56:19 by nkhamich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*free_everything(char **strs, size_t j)
{
	if (strs == NULL)
		return (NULL);
	while (j > 0)
	{
		free(strs[j - 1]);
		j--;
	}
	free(strs);
	return (NULL);
}

static size_t	strlen_till_sep(const char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static char	*get_word(const char *s, char c, size_t *i)
{
	size_t	word_len;
	char	*word;

	word_len = strlen_till_sep(&s[*i], c);
	word = ft_substr(s, *i, word_len);
	*i += word_len;
	return (word);
}

static int	count_words(const char *str, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (str[i])
		{
			count++;
			while (str[i] && str[i] != c)
				i++;
		}
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	char	**strs;

	i = 0;
	j = 0;
	if (!s || *s == '\0')
		return (NULL);
	strs = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (strs == NULL || count_words(s, c) == 0)
		return (free_everything(strs, j));
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
		{
			strs[j] = get_word(s, c, &i);
			if (strs[j] == NULL)
				return (free_everything(strs, j));
			j++;
		}
	}
	strs[j] = NULL;
	return (strs);
}
