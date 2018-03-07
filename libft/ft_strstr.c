/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smortier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 18:46:55 by smortier          #+#    #+#             */
/*   Updated: 2017/11/12 15:56:47 by smortier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strstr(const char *meule_de_foin, const char *aiguille)
{
	size_t		i;
	size_t		y;

	i = 0;
	y = 0;
	if (aiguille[0] == '\0')
		return ((char *)meule_de_foin);
	while (meule_de_foin[i])
	{
		while (meule_de_foin[i + y] == aiguille[y])
		{
			if (!aiguille[y + 1])
				return ((char *)meule_de_foin + i);
			y++;
		}
		y = 0;
		i++;
	}
	return (NULL);
}
