/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hokutosuzuki <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 18:03:52 by hokutosuz         #+#    #+#             */
/*   Updated: 2021/11/14 07:04:30 by hokutosuz        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static bool	ft_match(char c, const char *set)
{
	size_t	i;

	i = 0;
	while (set[i])
		if (set[i++] == c)
			return (true);
	return (false);
}

static char	*ft_trim(const char *s1, size_t len, size_t front)
{
	size_t	i;
	char	*dst;

	i = 0;
	dst = ft_calloc(sizeof(char), len + 1);
	if (dst == NULL)
		return (NULL);
	while (i < len)
	{
		dst[i] = s1[front + i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_strtrim(char const	*s1, char const	*set)
{
	size_t	front;
	size_t	back;
	size_t	len;
	char	*dst;

	if (!s1 || !set)
		return (NULL);
	front = 0;
	back = 0;
	len = ft_strlen(s1);
	while (ft_match(*(s1 + front), set))
		front++;
	while (ft_match(s1[len - back - 1], set) && back < len - front)
		back++;
	len = len - (front + back);
	dst = ft_trim(s1, len, front);
	return (dst);
}
