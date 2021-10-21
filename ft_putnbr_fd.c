/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hokutosuzuki <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 18:03:50 by hokutosuz         #+#    #+#             */
/*   Updated: 2021/10/16 18:24:48 by hokutosuz        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int i, int fd)
{
	if (i == -2147483648)
	{
		ft_putnbr_fd(i / 10, fd);
		ft_putchar_fd('8', fd);
	}
	else if (i < 0)
	{
		ft_putchar_fd('-', fd);
		ft_putnbr_fd(-i, fd);
	}
	else
	{
		if (i > 9)
		{
			ft_putnbr_fd(i / 10, fd);
			ft_putchar_fd('0' + (i % 10), fd);
		}
		else
			ft_putchar_fd('0' + i, fd);
	}
}
