/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hokutosuzuki <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 18:03:52 by hokutosuz         #+#    #+#             */
/*   Updated: 2021/10/20 20:02:40 by hokutosuz        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_match(char c, const char *set)
{
	size_t	i;

	i = 0;
	while (set[i])
		if (set[i++] == c)
			return (1);
	return (0);
}

static char	*ft_trim(const char *s1, const char *set, size_t len, size_t i)
{
	size_t	j;
	size_t	t;
	char	*dst;

	j = 0;
	t = 0;
	while (ft_match(s1[len - j - 1], set) && j < len - i)
		j++;
	dst = ft_calloc(sizeof(char), len - (i + j) + 1);
	if (dst == NULL)
		return (NULL);
	while (t < len - (i + j))
	{
		dst[t] = s1[i + t];
		t++;
	}
	dst[t] = '\0';
	return (dst);
}

char	*ft_strtrim(char const	*s1, char const	*set)
{
	size_t	i;
	size_t	len;
	char	*dst;

	if (s1 == NULL || set == NULL)
		return (NULL);
	i = 0;
	len = ft_strlen(s1);
	while (ft_match(*(s1 + i), set))
		i++;
	dst = ft_trim(s1, set, len, i);
	return (dst);
}
