/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smortier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 20:05:14 by smortier          #+#    #+#             */
/*   Updated: 2017/11/08 20:15:22 by smortier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strcat(char *dest, const char *src)
{
	int		i;
	int		y;

	i = -1;
	while (dest[++i])
		;
	y = -1;
	while (src[++y])
	{
		dest[i + y] = src[y];
	}
	dest[i + y] = '\0';
	return (dest);
}
