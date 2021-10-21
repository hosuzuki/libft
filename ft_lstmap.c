/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hokutosuzuki <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 18:03:49 by hokutosuz         #+#    #+#             */
/*   Updated: 2021/10/20 20:17:34 by hokutosuz        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_bonus.h"

t_list	*ft_lstmap(t_list *lst, void	*(*f)(void*), void	(*del)(void*))
{
	t_list	*n;
	t_list	*tmp;

	if (lst == NULL || f == NULL)
		return (NULL);
	n = ft_lstnew(f(lst->content));
	if (n == NULL)
		return (NULL);
	tmp = n;
	while (lst->next)
	{
		lst = lst->next;
		tmp->next = ft_lstnew(f(lst->content));
		if (tmp->next == NULL)
		{
			ft_lstclear(&n, del);
			return (NULL);
		}
		tmp = tmp->next;
	}
	return (n);
}
