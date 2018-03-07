/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smortier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 19:12:21 by smortier          #+#    #+#             */
/*   Updated: 2017/11/13 19:28:38 by smortier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list		*lst;
	t_list		*list_nxt;

	lst = *alst;
	while (lst)
	{
		list_nxt = lst->next;
		del(lst->content, lst->content_size);
		free(lst);
		lst = list_nxt;
	}
	(*alst) = NULL;
}
