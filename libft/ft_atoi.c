/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smortier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 18:42:02 by smortier          #+#    #+#             */
/*   Updated: 2017/11/12 15:51:53 by smortier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int		is_blanks(char c)
{
	if (c == ' ' || c == '\t' || c == '\v' || c == '\f' || c == '\r' ||
			c == '\n')
		return (1);
	return (0);
}

int				ft_atoi(const char *str)
{
	int		i;
	int		res;
	int		neg;

	neg = 0;
	i = 0;
	res = 0;
	while (is_blanks(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			neg = 1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return ((neg) ? res * -1 : res);
}
