/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smortier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 13:16:59 by smortier          #+#    #+#             */
/*   Updated: 2017/11/13 15:02:50 by smortier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_itoa(int n)
{
	int					size;
	unsigned int		ncpy;
	char				*res;

	ncpy = (n < 0) ? -n : n;
	size = 0;
	size = (n <= 0) ? size + 1 : size;
	while (ncpy)
	{
		ncpy /= 10;
		size++;
	}
	if (!(res = ft_strnew(size)))
		return (NULL);
	size--;
	res[0] = (n < 0) ? '-' : '0';
	ncpy = (n < 0) ? -n : n;
	while (ncpy)
	{
		res[size] = ncpy % 10 + 48;
		ncpy /= 10;
		size--;
	}
	return (res);
}
