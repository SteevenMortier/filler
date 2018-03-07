/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smortier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 21:13:48 by smortier          #+#    #+#             */
/*   Updated: 2017/11/27 21:13:53 by smortier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/libft.h"

void	*ft_realloc(void **ptr, size_t oldsize, size_t newsize)
{
	void	*freshptr;

	if (!(freshptr = ft_strnew(sizeof(char) * newsize)))
		return (NULL);
	if (*ptr)
	{
		ft_memcpy(freshptr, *ptr, oldsize);
		ft_memdel(ptr);
	}
	return (freshptr);
}

int		manage_line(char **tmp, char **line, int ret)
{
	char			*temp;

	temp = NULL;
	if (ft_strchr(*tmp, '\n'))
	{
		*line = ft_strsub(*tmp, 0, ft_strclen(*tmp, '\n'));
	}
	else if (*tmp[0])
	{
		*line = ft_strsub(*tmp, 0, ft_strlen(*tmp));
		ft_memdel((void **)tmp);
	}
	temp = ft_strsub(*tmp, ft_strclen(*tmp, '\n') + 1, ft_strlen(*tmp));
	ft_memdel((void **)tmp);
	*tmp = temp;
	return ((*tmp) ? ret : 1);
}

int		readline(const int fd, char **line)
{
	static char			*tmp;
	int					ret;
	char				buf[BUFF_SIZE];

	ret = 1;
	while (ft_strchr(tmp, '\n') == NULL)
	{
		ret = read(fd, buf, BUFF_SIZE);
		if (ret == -1)
			return (-1);
		if (ret <= 0)
			break ;
		tmp = (char *)ft_realloc((void **)&tmp, ft_strlen(tmp),
									ft_strlen(tmp) + ret + 1);
		ft_strncat(tmp, buf, ret);
	}
	return ((tmp) ? manage_line(&tmp, line, ret) : 0);
}

int		get_next_line(const int fd, char **line)
{
	int ret;

	if (line == NULL || fd < 0 || BUFF_SIZE <= 0)
		return (-1);
	ret = readline(fd, line);
	if (ret > 0)
		return (1);
	if (ret == 3)
		return (1);
	if (ret == 0)
		return (0);
	else
		return (-1);
}
