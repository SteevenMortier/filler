#include "filler.h"

void	artif_intel(t_informations *info)
{
	static int		swap;

	if (!info->pos_reached) // la j ai une premiere target
	{
		info->target[0] = info->his_first_pos[0];
		info->target[1] = info->map_widht / 2;
		if (info->map[info->his_first_pos[0]][info->map_widht / 2] ==
				info->him - 32)
			info->pos_reached = 1;
		reach_position(info);
	}
	else if (swap)
	{
		info->target[0] = info->his_first_pos[0] - 3;
		info->target[1] = info->his_first_pos[1];
		swap = 0;
		reach_position(info);
	}
	else
	{
		info->target[0] = info->his_first_pos[0] + 3;
		info->target[1] = info->his_first_pos[1];
		swap = 1;
		reach_position(info);
	}
//	dprintf(2, "\e[34m TARGET = [%d][%d]\n\e[0m", info->target[0], info->target[1]);
//	sleep(1);
}
