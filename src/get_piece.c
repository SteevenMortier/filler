/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_piece.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smortier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 09:45:03 by smortier          #+#    #+#             */
/*   Updated: 2018/03/18 09:45:10 by smortier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		create_piece(t_informations *info)
{
	int			index;
	char		*line;
	int			index_p;
	int			first;

	info->p_lag_x = 0;
	first = 0;
	info->piece = ft_memalloc(sizeof(char *) * info->p_height);
	index = -1;
	index_p = 0;
	while (++index < info->p_height)
	{
		if (get_next_line(0, &line) == -1)
		{
			ft_putstr_fd("Error with get_next_line", 2);
			return (-1);
		}
		if (ft_strchr(line, '*'))
		{
			if (!info->p_lag_x && !first)
			{
				first = 42;
				info->p_lag_x = index;
			}
			info->piece[index_p] = ft_strnew(info->p_widht);
			ft_strcpy(info->piece[index_p], line);
			index_p++;
		}
		ft_strdel(&line);
	}
	info->p_height = index_p;
	return (42);
}

void	get_lag_y(t_informations *info)
{
	int		index_x;
	int		index_y;
	char	*str;

	info->p_lag_y = 42;
	index_x = -1;
	str = NULL;
	while (++index_x < info->p_height)
	{
		index_y = -1;
		while (info->piece[index_x][++index_y])
		{
			if (info->piece[index_x][index_y] == '*' && index_y <=
					info->p_lag_y)
				info->p_lag_y = index_y;
		}
	}
	info->p_lag_y = (info->p_lag_y == 42) ? 0 : info->p_lag_y;
	index_x = -1;
	while (++index_x < info->p_height && info->p_lag_y)
	{
		str = ft_strdup(info->piece[index_x]);
		ft_memdel((void **)&(info->piece[index_x]));
		info->piece[index_x] = ft_strdup(str + info->p_lag_y);
		ft_memdel((void **)&(str));
	}
}

int		get_piece(t_informations *info)
{
	char	*line;
	int		index;

	if (get_next_line(0, &line) == -1)
	{
		ft_putstr_fd("Error with get_next_line", 2);
		return (-1);
	}
	if (!ft_strstr(line, "Piece "))
		return (1);
	info->p_height = ft_atoi(line + 6);
	index = 6;
	while (ft_isdigit(line[index]))
		index++;
	info->p_widht = ft_atoi(line + index);
	if (create_piece(info) == -1)
		return (-1);
	get_lag_y(info);
	ft_strdel(&line);
	return (42);
}
