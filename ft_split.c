/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hokutosuzuki <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 18:03:50 by hokutosuz         #+#    #+#             */
/*   Updated: 2021/11/04 20:49:00 by hokutosuz        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static bool	sep_ck(const char str, char c)
{
	if (str == c || str == '\0')
		return (true);
	return (false);
}

static bool	make_malloc(char **res, size_t j, size_t w)
{
	size_t	i;

	i = 0;
	res[w] = (char *)malloc(sizeof(char) * (j + 1));
	if (res[w] == NULL)
	{
		while (i < w)
			free(res[i++]);
		free(res);
		return (false);
	}
	return (true);
}

static bool	cut_str(char **res, const char *str, char c, size_t i)
{
	size_t	j;
	size_t	w;

	w = 0;
	while (str[i] != '\0')
	{
		if (sep_ck(str[i], c))
			i++;
		else
		{
			j = 0;
			while (!sep_ck(str[i + j], c))
				j++;
			if (!make_malloc(res, j, w))
				return (false);
			ft_strlcpy(res[w], &str[i], j + 1);
			i += j;
			w++;
		}
	}
	res[w] = NULL;
	return (true);
}

char	**ft_split(const char *s, char c)
{
	char	**res;
	size_t	w;
	size_t	i;

	i = 0;
	w = 0;
	if (s == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		if (sep_ck(s[i + 1], c) && !sep_ck(s[i], c))
			w++;
		i++;
	}
	res = (char **)malloc(sizeof(char *) * (w + 1));
	if (res == NULL)
		return (NULL);
	i = 0;
	if (!cut_str(res, s, c, i))
		return (NULL);
	return (res);
}
