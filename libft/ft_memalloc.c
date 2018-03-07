/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smortier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 14:10:40 by smortier          #+#    #+#             */
/*   Updated: 2017/11/14 17:34:32 by smortier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	void	*mem;
	int		i;

	i = -1;
	if (!(mem = (void *)malloc(sizeof(void) * size)))
		return (NULL);
	while (++i < (int)size)
		((unsigned char *)mem)[i] = 0;
	return (mem);
}
