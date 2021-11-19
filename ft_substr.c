/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hokutosuzuki <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 18:03:52 by hokutosuz         #+#    #+#             */
/*   Updated: 2021/11/19 17:42:28 by hokutosuz        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_s_length(char *src)
{
	size_t	i;

	i = 0;
	while (i < SIZE_MAX - 1)
	{
		if (!src[i])
			break ;
		i++;
	}
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	s_length;
	char	*str;

	i = 0;
	s_length = get_s_length((char *)s);
	if (!s)
		return (NULL);
	if (start >= s_length || len == 0)
		return (ft_strdup(""));
	else if (len > s_length - start)
		len = s_length - start;
	str = (char *)ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s + start, len + 1);
	return (str);
}
