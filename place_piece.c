/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_piece.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smortier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 09:45:23 by smortier          #+#    #+#             */
/*   Updated: 2018/03/18 09:45:25 by smortier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	get_diff_for_position(t_informations *info, int x, int y)
{
	int		index[2];
	int		difference;

	difference = 424242;
	if (!check_piece_pos(info, x, y))
		return ;
	index[0] = -1;
	while (++index[0] < info->p_height)
	{
		index[1] = -1;
		while (++index[1] < info->p_widht)
		{
			if (info->piece[index[0]][index[1]] == '*')
			{
				difference = (ABS((x + index[0]) - info->target[0]) +
							ABS((y + index[1]) - info->target[1]));
				if (difference <= info->diff_for_position)
				{
					info->diff_for_position = difference;
					info->place_piece[0] = x;
					info->place_piece[1] = y;
				}
			}
		}
	}
}

void	all_try_for_piece(t_informations *info, int x, int y)
{
	int		try_p_x;
	int		try_p_y;
	int		actual_p[2];

	actual_p[0] = x;
	actual_p[1] = y;
	try_p_x = (info->p_height - 1) * (-1);
	while (try_p_x <= info->p_height - 1)
	{
		try_p_y = (info->p_widht - 1) * (-1);
		while (try_p_y <= info->p_widht - 1)
		{
			get_diff_for_position(info, actual_p[0] + try_p_x,
								actual_p[1] + try_p_y);
			try_p_y++;
		}
		try_p_x++;
	}
}

int		get_first_pos(t_informations *info)
{
	int		index;
	int		index_me;
	int		index_bis;

	index = -1;
	while (++index < info->map_height - 1)
	{
		if (ft_strchr(info->map[index], info->me - 32))
			info->first_pos[0] = index_me;
		if (ft_strchr(info->map[index], info->him - 32))
			info->his_first_pos[0] = index;
	}
	index_bis = -1;
	while (info->map[index][++index_bis])
	{
		if (info->map[index][index_bis] == (info->me - 32))
			info->first_pos[1] = index_bis;
		if (info->map[index][index_bis] == (info->him - 32))
			info->his_first_pos[1] = index_bis;
	}
	info->reach_the_position[0] = info->first_pos[0];
	info->reach_the_position[1] = info->first_pos[1];
	return (42);
}

int		place_piece(t_informations *info)
{
	int			index_piece;
	int			index;
	static int	first;
	int			index_old_map;

	index_piece = -1;
	if (!first)
	{
		get_first_pos(info);
		first = 42;
	}
	artif_intel(info);
	index_old_map = -1;
	if (!(info->old_map = ft_memalloc(sizeof(char *) * info->map_height)))
		return (-1);
	while (++index_old_map < info->map_height)
		info->old_map[index_old_map] = ft_strdup(info->map[index_old_map]);
	return (0);
}
