#include "filler.h"

void	artif_intel(t_informations *info)
{
	static int		swap;
//	if (!info->pos_reached) // la j ai une premiere target
//		reach_position(info);
	/*else */ if (info->p_height > 1)
	{
		info->target[0] = info->his_first_pos[0] - 5;
		info->target[1] = info->his_first_pos[1];
		swap = 0;
		reach_position(info);
	}
	/*else if (info->map[info->map_height - 1][0] == '.')
	{
		info->target[0] = info->map_height - 1;
		info->target[1] = 0;
		reach_position(info);
	}*/
	else
	{
		info->target[0] = info->his_first_pos[0] + 5;
		info->target[1] = info->his_first_pos[1];
		swap = 1;
		reach_position(info);
	}
}
