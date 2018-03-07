/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbcwords.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smortier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 16:32:23 by smortier          #+#    #+#             */
/*   Updated: 2017/11/13 16:38:09 by smortier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		ft_nbcwords(char const *s, char c)
{
	int		res;
	int		i;

	i = 0;
	res = 0;
	while (i < (int)ft_strlen(s))
	{
		if (i == 0 && s[i] != c)
			res++;
		if (s[i] == c && s[i + 1] && s[i + 1] != c)
			res++;
		i++;
	}
	return (res);
}
