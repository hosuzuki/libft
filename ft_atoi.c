/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hokutosuzuki <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 18:03:48 by hokutosuz         #+#    #+#             */
/*   Updated: 2021/10/19 20:35:52 by hokutosuz        ###   ########.fr       */
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
	int					nega;
	unsigned long long	to_int;
	int					i;

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
		if (to_int > LONG_MAX)
		{
			if (nega == -1)
				return (0);
			return (-1);
		}
		to_int = (to_int * 10) + (str[i++] - '0');
	}
	return (to_int * nega);
}
