/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hokutosuzuki <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 18:03:49 by hokutosuz         #+#    #+#             */
/*   Updated: 2021/10/20 20:19:05 by hokutosuz        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_bonus.h"

void	ft_lstadd_front(t_list	**lst, t_list	*new)
{
	if (lst != NULL && new != NULL)
	{
		if (*lst)
		{
			new->next = *lst;
			*lst = new;
		}
		else
			*lst = new;
	}
}
