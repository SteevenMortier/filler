/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smortier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 17:33:36 by smortier          #+#    #+#             */
/*   Updated: 2017/11/10 14:36:41 by smortier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	c1;
	size_t			i;
	void			*sr;

	sr = (void *)s;
	c1 = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if ((((unsigned char *)s)[i]) == c1)
			return (sr + i);
		i++;
	}
	return (NULL);
}
