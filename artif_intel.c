#include "filler.h"

void	clear_old_map(t_informations *info)
{
	int		index;

	index = -1;
	while (++index < info->map_height)
		ft_memdel((void **)&(info->old_map[index]));
	ft_memdel((void **)&(info->old_map));
}

void	artif_intel(t_informations *info)
{
	static int		swap;
	int				index_x;
	int				index_y;

	index_x = -1;

	swap = 1;
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
					break;
				}
			}
		}
	}
	if (swap)
	{
		info->target[0] = info->his_last_pos[0] - 3;
		info->target[1] = (info->his_last_pos[1] >= info->map_widht / 2) ?
						info->his_last_pos[1] + 2 : info->his_last_pos[1] - 2;
		swap = 0;
		reach_position(info);
	}
	/*else
	{
		info->target[0] = info->his_last_pos[0] + 3;
		info->target[1] = (info->his_last_pos[1] >= info->map_widht / 2) ?
						info->his_last_pos[1] + 2 : info->his_last_pos[1] - 2;
		swap = 1;
		reach_position(info);
	}*/
	//la je supprime la old map
	if (info->old_map)
		clear_old_map(info);
//	dprintf(2, "\e[34m him = [%c]\n\e[0m", info->him);
//	dprintf(2, "\e[34m his_last_pos = [%d][%d]\n\e[0m", info->his_last_pos[0], info->his_last_pos[1]);
//	dprintf(2, "\e[34m TARGET = [%d][%d]\n\e[0m", info->target[0], info->target[1]);
//	sleep(1);
}
