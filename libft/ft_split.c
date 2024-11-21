/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhamich <nkhamich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 15:06:21 by nkhamich          #+#    #+#             */
/*   Updated: 2024/10/17 19:47:40 by nkhamich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*free_everything(char **strs, size_t j)
{
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

	strs = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (strs == NULL)
		return (NULL);
	i = 0;
	j = 0;
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

// int main(void) 
// {
// 	char	**result;

// 	// Test 1: Normal case
// 	result = ft_split("Hello,World,Test", ',');
// 	printf("Test 1: '%s', '%s', '%s'\n", result[0], result[1], result[2]);
// 	for (int i = 0; result[i]; i++)
// 		free(result[i]);
// 	free(result);

// 	// Test 2: Leading and trailing delimiters
// 	result = ft_split(",Hello,World,Test,", ',');
// 	printf("Test 2: '%s', '%s', '%s'\n", result[0], result[1], result[2]);
// 	for (int i = 0; result[i]; i++)
// 		free(result[i]);
// 	free(result);

// 	return (0);
// }
