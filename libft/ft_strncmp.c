/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smortier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 18:32:32 by smortier          #+#    #+#             */
/*   Updated: 2017/11/14 17:26:18 by smortier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t		i;
	int			res;

	res = 0;
	i = 0;
	if (n == 0)
		return (res);
	while (s1[i] == s2[i] && i < (n - 1) && s1[i] && s2[i])
	{
		i++;
	}
	res = ((unsigned char *)s1)[i] - ((unsigned char *)s2)[i];
	return (res);
}
