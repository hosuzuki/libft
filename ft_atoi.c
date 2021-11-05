/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hokutosuzuki <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 18:03:48 by hokutosuz         #+#    #+#             */
/*   Updated: 2021/11/04 12:09:51 by hokutosuz        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	spaceck(const char c)
{
	if (c == '\n' || c == '\t' || c == '\v'
		|| c == '\f' || c == '\r' || c == ' ')
		return (1);
	return (0);
}

int	ft_atoi(const char	*str)
{
	int		nega;
	size_t	to_int;
	size_t	i;

	to_int = 0;
	nega = 1;
	i = 0;
	while (spaceck(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			nega = -1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		to_int = (to_int * 10) + (str[i++] - '0');
		if (to_int >= LONG_MAX && nega == 1)
			return (-1);
		else if (to_int >= (size_t)(-(LONG_MIN + 1)) + 1 && nega == -1)
			return (0);
	}
	return ((int)to_int * nega);
}
