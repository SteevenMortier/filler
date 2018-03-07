/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smortier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 17:59:03 by smortier          #+#    #+#             */
/*   Updated: 2017/11/10 18:32:03 by smortier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t		i;
	size_t		y;

	y = 0;
	i = 0;
	if (s2[0] == '\0')
		return ((char *)s1);
	while (s1[i])
	{
		while (s1[i + y] == s2[y] && (i + y) < n)
		{
			if (!s2[y + 1] && s1[i + y] == s2[y])
				return ((char *)s1 + i);
			y++;
		}
		y = 0;
		i++;
	}
	return (NULL);
}
