/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hokutosuzuki <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 18:03:51 by hokutosuz         #+#    #+#             */
/*   Updated: 2021/10/20 19:50:42 by hokutosuz        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	d_i;
	size_t	s_i;
	size_t	d_l;
	size_t	s_l;

	d_l = ft_strlen(dst);
	d_i = d_l;
	s_l = ft_strlen(src);
	s_i = 0;
	while (src[s_i] != '\0' && d_l + s_i + 1 < dstsize)
		dst[d_i++] = src[s_i++];
	dst[d_i] = '\0';
	if (d_l > dstsize)
		return (s_l + dstsize);
	else
		return (d_l + s_l);
}
