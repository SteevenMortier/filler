/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smortier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 15:03:11 by smortier          #+#    #+#             */
/*   Updated: 2017/11/13 16:56:26 by smortier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		nbrw;
	int		i;

	if (s == NULL)
		return (NULL);
	i = 0;
	nbrw = ft_nbcwords(s, c);
	i = 0;
	if (!(tab = (char **)ft_memalloc(sizeof(char *) * (nbrw + 1))))
		return (NULL);
	tab[nbrw] = NULL;
	while (i < nbrw && *s)
	{
		if (*s == c)
			s++;
		if (*s != c)
		{
			tab[i] = ft_strsub(s, 0, ft_strclen(s, c));
			i++;
			while (*s != c)
				s++;
		}
	}
	return (tab);
}
