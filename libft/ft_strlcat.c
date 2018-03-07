/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smortier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 16:45:02 by smortier          #+#    #+#             */
/*   Updated: 2017/11/13 17:36:39 by smortier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

size_t		ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	int		i;
	int		j;

	i = 0;
	while (dst[i] && i < (int)dstsize)
		i++;
	j = i;
	while (src[i - j] && i < (int)dstsize - 1)
	{
		dst[i] = src[i - j];
		i++;
	}
	if (i < (int)dstsize)
		dst[i] = '\0';
	return (j + ft_strlen(src));
}
