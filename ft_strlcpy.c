/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hokutosuzuki <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 18:03:51 by hokutosuz         #+#    #+#             */
/*   Updated: 2021/11/03 15:13:56 by hokutosuz        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char	*dst, const char	*src, size_t	dstsize)
{
	size_t	n;
	size_t	c;

	n = 0;
	c = 0;
	while (src[c])
		c++;
	if (dstsize > 0)
	{
		while (src[n] != '\0' && n < (dstsize - 1))
		{
			dst[n] = src[n];
			n++;
		}
		dst[n] = '\0';
	}
	return (c);
}
