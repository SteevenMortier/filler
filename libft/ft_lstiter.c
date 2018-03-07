/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smortier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 19:39:06 by smortier          #+#    #+#             */
/*   Updated: 2017/11/13 19:46:23 by smortier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	t_list		*lst_nxt;

	if (lst == NULL)
		return ;
	while (lst)
	{
		lst_nxt = lst->next;
		f(lst);
		lst = lst_nxt;
	}
}
