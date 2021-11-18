/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hokutosuzuki <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 18:03:51 by hokutosuz         #+#    #+#             */
/*   Updated: 2021/11/18 16:00:00 by hokutosuz        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	len1;
	size_t	len2;

	if (dst == NULL)
		len1 = 0;
	else 
		len1 = ft_strlen(dst);
	len2 = ft_strlen(src);
	i = 0;
	if (dstsize == 0)
		return (len2);
	else if (len1 > dstsize)
		return (len2 + dstsize);
	while (src[i] != '\0' && len1 + i + 1 < dstsize)
	{
		dst[len1 + i] = src[i];
		i++;
	}
	dst[len1 + i] = '\0';
	return (len1 + len2);
}
*/

size_t const	dst_length(char *dst, size_t dstsize)
{
	size_t	i;

	i  = 0;
	while (i < dstsize)
	{
		if (!*dst)
			break;
		++;
		dst++;
	}
	return (i);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	len1;
	size_t	len2;

	len1 = dst_length(dst, dstsize);
	len2 = ft_strlen(src);
	if (len1 >= dstsize)
		return (len2 + dstsize);
	if (len2 < dstsize -len1)
		ft_memcpy(dst + len1, src, len2 + 1);
	else
	{
		ft_memcpy(dst + len1, src, dstsize - 1);
		dst[len1 + dstsize - 1] = '\0';
	}
	return (len1 + len2);
}
