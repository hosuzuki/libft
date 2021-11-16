/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hokutosuzuki <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 18:03:50 by hokutosuz         #+#    #+#             */
/*   Updated: 2021/11/16 10:16:21 by hokutosuz        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static bool	find_words(const char str, char c)
{
	if (str == c || str == '\0')
		return (false);
	return (true);
}

static bool	make_malloc(char **res, size_t letter, size_t word)
{
	res[word] = (char *)ft_calloc(letter + 1, sizeof(char));
	if (!res[word])
	{
		while (word)
			free(res[word--]);
		free(res);
		return (false);
	}
	return (true);
}

static bool	cut_str(char **res, const char *str, char c, size_t start)
{
	size_t	letter;
	size_t	word;

	word = 0;
	while (str[start] != '\0')
	{
		if (!find_words(str[start], c))
			start++;
		else
		{
			letter = 0;
			while (find_words(str[start + letter], c))
				letter++;
			if (!make_malloc(res, letter, word))
				return (false);
			ft_strlcpy(res[word], &str[start], letter + 1);
			start += letter;
			word++;
		}
	}
	res[word] = NULL;
	return (true);
}

char	**ft_split(const char *s, char c)
{
	char	**res;
	size_t	count_words;
	size_t	i;

	count_words = 0;
	i = 0;
	if (!s)
		return (NULL);
	while (s[i] != '\0')
	{
		if (find_words(s[i], c) && !find_words(s[i + 1], c))
			count_words++;
		i++;
	}
	res = (char **)ft_calloc(count_words + 1, sizeof(char *));
	if (!res)
		return (NULL);
	i = 0;
	if (!cut_str(res, s, c, i))
		return (NULL);
	return (res);
}
