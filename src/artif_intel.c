/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   artif_intel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smortier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 09:43:48 by smortier          #+#    #+#             */
/*   Updated: 2018/03/18 09:44:02 by smortier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	clear_old_map(t_informations *info)
{
	int		index;

	index = -1;
	while (++index < info->map_height)
		ft_memdel((void **)&(info->old_map[index]));
	ft_memdel((void **)&(info->old_map));
}

void	spot_his_last_pos(t_informations *info)
{
	int				index_x;
	int				index_y;
	static int		start;

	index_x = -1;
//	info->his_last_pos[0] = 0;
//	info->his_last_pos[1] = 0;
	if (info->old_map)
	{
		index_x = -1;
		while (++index_x < info->map_height)
		{
			index_y = -1;
			while (++index_y < info->map_widht)
			{
				if ((info->map[index_x][index_y] == info->him - 32) &&
					(info->old_map[index_x][index_y] == '.'))
				{
					info->his_last_pos[0] = index_x;
					info->his_last_pos[1] = index_y;
					dprintf(2, "HIS LAST POS = [%d][%d]\n", info->his_last_pos[0], info->his_last_pos[1]);
					return ;
				}
			}
		}
	}
	if (start)
	{
		info->his_last_pos[0] = -42;
		info->his_last_pos[1] = -42;
	}
	start = 1;
}

void	artif_intel(t_informations *info)
{
	spot_his_last_pos(info);
	info->target[0] = info->his_last_pos[0] - 3;
	info->target[1] = (info->his_last_pos[1] >= info->map_widht / 2) ?
					info->his_last_pos[1] + 2 : info->his_last_pos[1] - 2;
	reach_position(info);
	if (info->old_map)
		clear_old_map(info);
}
