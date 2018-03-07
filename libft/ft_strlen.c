/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smortier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 18:37:31 by smortier          #+#    #+#             */
/*   Updated: 2017/11/27 22:10:06 by smortier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

size_t		ft_strlen(const char *s)
{
	int			i;
	size_t		count;

	if (s == NULL)
		return (0);
	count = 0;
	i = -1;
	while (s[++i])
		count++;
	return (count);
}
