#include "filler.h"

int		check_piece_pos(t_informations *info, int x, int y)
{
	int		index_p_x;
	int		index_p_y;
	int		link;
	int		save_y;

	save_y = y;
	index_p_x = -1;
	link = 0;
	while (++index_p_x < info->p_height)
	{
		index_p_y = -1;
		while (++index_p_y < info->p_widht)
		{
			if (x < 0 || x > info->map_height - 1 || y < 0 || y > info->map_widht - 1)
				return (0);
			if ((info->piece[index_p_x][index_p_y] == '*'
					&& (info->map[x][y] == info->him || info->map[x][y] ==
											info->him - 32)))
			{
//				dprintf(2, "\e[32mJe ne peut pas poser a [%d][%d]\n\e[0m", x , y);
//				dprintf(2, "\e[32mA cause de piece = [%d][%d] map = [%d][%d]\n\e[0m",index_p_x, index_p_y, x, y);
				return (0);
			}
			if ((info->piece[index_p_x][index_p_y] == '*' &&
					((info->map[x][y]) && ((info->map[x][y] == info->me) ||
							info->map[x][y] == info->me - 32))))
				link++;
			y++;
		}
		x++;
		y = save_y;
	}
	if (link != 1)
	{
//		dprintf(2, "\e[32m car link != 1 : link = [%d]\n\e[0m", link);
		return (0);
	}
	return (1);
}

void	get_diff_for_position(t_informations *info,int x ,int y)// repere jjuste le point le plus proche dans la piece
{
	int		index_x;
	int		index_y;
	int		difference;

	index_x = -1;
	difference = 424242;
	if (!check_piece_pos(info, x, y))
	{
//		dprintf(2, "\e[32mJe ne peut pas poser a [%d][%d]\n\e[0m", x , y);
		return ;
	}
	while (++index_x < info->p_height)
	{
		index_y = -1;
		while (++index_y < info->p_widht)
		{
			if (info->piece[index_x][index_y] == '*')
			{
				difference = (ABS((x + index_x) - info->target[0]) +
							ABS((y + index_y) - info->target[1]));
//				dprintf(2, "\e[31mDifference pour [%d][%d] = [%d]\n\e[0m", x, y, difference);
				if (difference <= info->diff_for_position)
				{
					info->diff_for_position = difference;
					info->place_piece[0] = x;
					info->place_piece[1] = y;
					if (difference < 4)
						info->pos_reached = 1;
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
//			dprintf(2, "\e[36m ------dec en x = [%d] , dec en y = [%d]----------\n\e[0m", try_p_x, try_p_y);
//			dprintf(2, "\e[37m ------on envoie x = [%d], y = [%d]----------\n\e[0m", actual_p[0] + try_p_x, actual_p[1] + try_p_y);
			get_diff_for_position(info, actual_p[0] + try_p_x, actual_p[1] + try_p_y);
			try_p_y++;
		}
		try_p_x++;
	}
}

int		reach_position(t_informations *info)
{
	int		actual_p[2];
	int		map_x;
	int		map_y;

	actual_p[0] = 0;
	actual_p[1] = 0;
	map_x = -1;
	info->diff_for_position = 4242;
//	dprintf(2, "\e[32m je suis a [%d][%d]\n\e[0m", actual_p[0], actual_p[1]);
	while (++map_x < info->map_height)
	{
		map_y = -1;
		while (++map_y < info->map_widht)
		{
			if ((info->map[map_x][map_y] == info->me) || (info->map[map_x][map_y] == info->me - 32))
			{
				actual_p[0] = map_x;
				actual_p[1] = map_y;
				all_try_for_piece(info, actual_p[0], actual_p[1]);
			}
			actual_p[1] += 1;
		}
		actual_p[0] += 1;
	}
	if (check_piece_pos(info, info->place_piece[0], info->place_piece[1]))
	{
		ft_putnbr(info->place_piece[0]);
		ft_putchar(' ');
		ft_putnbr(info->place_piece[1]);
		ft_putchar('\n');
	}
	else
	{
		map_x = -1;
		while (++map_x < info->map_height)
		{
			map_y = -1;
			while (++map_y < info->map_widht)
			{
				if (check_piece_pos(info, map_x, map_y))
				{
					ft_putnbr(map_x);
					ft_putchar(' ');
					ft_putnbr(map_y);
					ft_putchar('\n');
				}
			}
		}
		ft_putnbr(map_x);
		ft_putchar(' ');
		ft_putnbr(map_y);
		ft_putchar('\n');
	}
//	ft_putnbr(info->place_piece[0]);
//	ft_putchar(' ');
//	ft_putnbr(info->place_piece[1]);
//	ft_putchar('\n');
	info->diff_for_position = 4242;
//	sleep(1);
	return (42);
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
		{
			info->his_first_pos[0] = index;
			break;
		}
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
	{
		info->old_map[index_old_map] = ft_strdup(info->map[index_old_map]);
	}
	//je creer la la old map;
	return (0);
}