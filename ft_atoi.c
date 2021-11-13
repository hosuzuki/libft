/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hokutosuzuki <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 18:03:48 by hokutosuz         #+#    #+#             */
/*   Updated: 2021/11/13 22:20:37 by hokutosuz        ###   ########.fr       */
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

static bool check_overflow(size_t res, int i, int sign)
{
	(void)i;
	if (sign == 1)
	{
		if (res > (size_t)(LLONG_MAX / 10))
			return (true);
	}
	else if (sign == -1) 
	{
		if (res > (size_t)(LLONG_MIN / 10))
			return (true);
	}
	return (false);
}

static int overflow_result(int sign)
{
	if (sign == 1)
		return ((int)LLONG_MAX);
	return ((int)LLONG_MIN);
}

int ft_atoi(const char *str)
{
	int		sign;
	size_t	res;
	size_t	i;

	res = 0;
	sign = 1;
	i = 0;
	while (spaceck(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign = -1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (check_overflow(res, str[i] - '0', sign))
			return(overflow_result(sign));
		res = (res * 10) + (str[i++] - '0');
	}
	return ((int)res * sign);
}
