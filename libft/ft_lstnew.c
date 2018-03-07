/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smortier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 17:46:56 by smortier          #+#    #+#             */
/*   Updated: 2017/11/20 08:26:52 by smortier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list		*new;

	if (!(new = (t_list *)ft_memalloc(sizeof(t_list))))
		return (NULL);
	if (content == NULL)
	{
		new->content = NULL;
		new->content_size = 0;
		new->next = NULL;
	}
	else
	{
		if (!(new->content = ft_memalloc(sizeof(*content) * content_size)))
		{
			free((void *)new);
			return (NULL);
		}
		ft_memcpy(new->content, content, sizeof(*content) * content_size);
		new->content_size = content_size;
		new->next = NULL;
	}
	return (new);
}
