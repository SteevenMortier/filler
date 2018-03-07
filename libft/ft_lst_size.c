/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_size.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smortier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 08:57:51 by smortier          #+#    #+#             */
/*   Updated: 2017/11/20 09:00:18 by smortier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		ft_lst_size(t_list *begin_list)
{
	t_list		*start;
	int			i;

	i = 0;
	start = begin_list;
	while (start)
	{
		i += 1;
		start = start->next;
	}
	return (i);
}
