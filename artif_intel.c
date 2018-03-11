#include "filler.h"

void	artif_intel(t_informations *info)
{
	static int		i_got_u;

//	if (!info->pos_reached) // la j ai une premiere target
//		reach_position(info);
	i_got_u = 0;
	/*else */ if (/*info->p_height > 1 && */!i_got_u)
	{
		info->target[0] = (info->his_first_pos[0] >= info->map_height / 2) ? info->his_first_pos[0] - 3 : info->his_first_pos[0] + 3;
		info->target[1] = info->his_first_pos[1];
		reach_position(info);
	}//un truc comme ca
	/*else if (info->map[info->map_height - 1][0] == '.')
	{
		info->target[0] = info->map_height - 1;
		info->target[1] = 0;
		reach_position(info);
	}*/
	else
	{
		info->target[0] = info->his_first_pos[0] + 3;
		info->target[1] = info->his_first_pos[1];
		reach_position(info);
	}
//	dprintf(2, "\e[34mi_got_u = [%d] TARGET = [%d][%d]\n\e[0m", i_got_u, info->target[0], info->target[1]);
//	sleep(1);
	//jvais try de faire un truc qui preshot sa target et l'intercepter =}
}
