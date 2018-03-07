/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smortier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 14:37:10 by smortier          #+#    #+#             */
/*   Updated: 2017/11/14 18:09:14 by smortier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int		is_splitter(char c)
{
	if (!c)
		return (0);
	if (c == ' ' || c == '\t' || c == '\n')
		return (1);
	return (0);
}

char			*ft_strtrim(char const *s)
{
	char	*str;
	int		posdo;
	int		posup;
	int		size;

	if (!s)
		return (NULL);
	posdo = 0;
	posup = ft_strlen(s) - 1;
	while (is_splitter(s[posdo]) && s[posdo])
		posdo++;
	if (!s[posdo])
	{
		if (!(str = (char *)ft_memalloc(sizeof(char) * 1)))
			return (NULL);
		return (str);
	}
	while (is_splitter(s[posup]) && posup > 1)
		posup--;
	size = posup - posdo + 1;
	if (!(str = ft_strnew(size)))
		return (NULL);
	str = ft_strncpy(str, s + posdo, size);
	return (str);
}
