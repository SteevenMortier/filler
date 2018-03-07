/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smortier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 08:47:00 by smortier          #+#    #+#             */
/*   Updated: 2017/11/20 09:02:34 by smortier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_list		*ft_create_elem(void *data)
{
	t_list		*elem;

	if (!(elem = (t_list *)ft_memalloc(sizeof(t_list))))
		return (NULL);
	elem->content = data;
	elem->next = NULL;
	return (elem);
}
