/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hokutosuzuki <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 18:03:50 by hokutosuz         #+#    #+#             */
/*   Updated: 2021/10/20 20:04:34 by hokutosuz        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	sep_ck(const char str, char c)
{
	if (str == c || str == '\0')
		return (1);
	return (0);
}

static void	cpy_word(char *res, const char *str, char c)
{
	int	i;

	i = 0;
	while (sep_ck(str[i], c) == 0)
	{
		res[i] = str[i];
		i++;
	}
	res[i] = '\0';
}

static int	make_malloc(char **res, int j, int w)
{
	res[w] = (char *)malloc(sizeof(char) * (j + 1));
	if (res[w] == NULL)
	{
		while (w >= 0)
			free(res[w--]);
		return (0);
	}
	return (1);
}

static int	cut_str(char **res, const char *str, char c, int i)
{
	int	j;
	int	w;

	w = 0;
	while (str[i] != '\0')
	{
		if (sep_ck(str[i], c) == 1)
			i++;
		else
		{
			j = 0;
			while (sep_ck(str[i + j], c) == 0)
				j++;
			if (make_malloc(res, j, w) == 0)
				return (0);
			cpy_word(res[w], str + i, c);
			i += j;
			w++;
		}
	}
	res[w] = NULL;
	return (1);
}

char	**ft_split(const char *s, char c)
{
	char	**res;
	int		w;
	int		i;

	i = 0;
	w = 0;
	if (s == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		if (sep_ck(s[i + 1], c) == 1 && sep_ck(s[i], c) == 0)
			w++;
		i++;
	}
	res = (char **)malloc(sizeof(char *) * (w + 1));
	if (res == NULL)
		return (NULL);
	i = 0;
	if (cut_str(res, s, c, i) == 0)
		return (NULL);
	return (res);
}
