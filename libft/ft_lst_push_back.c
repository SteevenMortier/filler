/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_pushb.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smortier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 08:49:58 by smortier          #+#    #+#             */
/*   Updated: 2017/11/20 09:03:08 by smortier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_lst_push_back(t_list **begin_list, void *data)
{
	t_list		*start;
	t_list		*elem;

	start = *begin_list;
	elem = ft_create_elem(data);
	if (!data)
		return ;
	while (start->next)
		start = start->next;
	start->next = elem;
}
