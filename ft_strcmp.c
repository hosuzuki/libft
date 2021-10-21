/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hokutosuzuki <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 18:03:51 by hokutosuz         #+#    #+#             */
/*   Updated: 2021/10/16 18:03:51 by hokutosuz        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char	*s1, char	*s2)
{
	int	number;

	number = 0;
	while (s1[number] != '\0' || s2[number] != '\0')
	{
		if (s1[number] < s2[number])
			return ((unsigned)s1[number] - (unsigned)s2[number]);
		else if (s1[number] > s2[number])
			return ((unsigned)s1[number] - (unsigned)s2[number]);
		else
			number++;
	}
	if (s1[number] == '\0' && s2[number] == '\0')
		return (0);
	else if (s1[number] == '\0')
		return (-(unsigned)s2[number]);
	else
		return ((unsigned)s1[number]);
}
