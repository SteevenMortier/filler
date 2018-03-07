/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smortier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 18:31:02 by smortier          #+#    #+#             */
/*   Updated: 2017/11/13 17:40:39 by smortier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strrchr(const char *s, int c)
{
	size_t				i;
	unsigned char		c1;
	size_t				pos;

	i = 0;
	pos = 0;
	c1 = (char)c;
	while (s[i])
	{
		pos = (s[i] == c1 && pos == 0) ? pos + 1 : pos;
		pos = (s[i] == c1) ? pos + 1 : pos;
		i++;
	}
	if (s[i] == c1)
		return ((char *)s + i);
	i = 0;
	while (s[i])
	{
		pos = (s[i] == c1) ? pos - 1 : pos;
		if (pos == 1)
			return ((char *)s + i);
		i++;
	}
	return (NULL);
}
