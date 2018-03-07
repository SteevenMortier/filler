/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smortier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 15:48:09 by smortier          #+#    #+#             */
/*   Updated: 2017/11/13 15:50:52 by smortier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		ft_strclen(char const *s, char c)
{
	int		i;
	int		res;

	if (s == NULL)
		return (0);
	i = 0;
	res = 0;
	while (s[i] && s[i] != c)
	{
		res++;
		i++;
	}
	return (res);
}
