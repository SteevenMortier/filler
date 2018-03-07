/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smortier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 17:56:02 by smortier          #+#    #+#             */
/*   Updated: 2017/11/12 15:54:05 by smortier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	int		i;
	char	*tab;

	i = 0;
	while (s[i] != '\0')
		i++;
	if (!(tab = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	tab[i] = '\0';
	i = 0;
	while (s[i] != '\0')
	{
		tab[i] = s[i];
		i++;
	}
	return (tab);
}
