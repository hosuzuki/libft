/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hokutosuzuki <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 18:03:51 by hokutosuz         #+#    #+#             */
/*   Updated: 2021/11/02 11:41:45 by hokutosuz        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strcpy(char	*dest, const char	*src)
{
	int i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static char	*ft_strcat(char	*dest, const char	*src)
{
	long long	i;
	long long	d_i;

	i = 0;
	d_i = 0;
	while (dest[d_i] != '\0')
		d_i++;
	while (src[i] != '\0')
	{
		dest[d_i] = src[i];
		d_i++;
		i++;
	}
	dest[d_i] = '\0';
	return (dest);
}

char	*ft_strjoin(char const	*s1, char const	*s2)
{
	char		*d;
	size_t		size;

	d = NULL;
	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	d = ft_calloc(sizeof(char), size);
	if (d == NULL)
		return (NULL);
	ft_strcpy(d, s1);
	ft_strcat(d, s2);
	return (d);
}
