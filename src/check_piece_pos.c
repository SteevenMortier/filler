/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_piece_pos.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smortier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 13:21:21 by smortier          #+#    #+#             */
/*   Updated: 2018/03/18 13:21:22 by smortier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		return_case(t_informations *info, int x, int y,
					int index_p[2])
{
	if (x <= 0 || x > info->map_height - 1 || y <= 0 ||
		y > info->map_widht - 1)
		return (0);
	if ((info->piece[index_p[0]][index_p[1]] == '*'
		&& (info->map[x][y] == info->him || info->map[x][y] ==
											info->him - 32)))
		return (0);
	return (1);
}

int		check_piece_pos(t_informations *info, int x, int y)
{
	int		index_p[2];
	int		link;
	int		save_y;

	save_y = y;
	x = x + info->p_lag_x;
	link = 0;
	index_p[0] = -1;
	while (++index_p[0] < info->p_height)
	{
		index_p[1] = -1;
		while (++index_p[1] < info->p_widht)
		{
			if (!return_case(info, x, y, index_p))
				return (0);
			if ((info->piece[index_p[0]][index_p[1]] == '*' &&
				((info->map[x][y]) && info->map[x][y] == info->me - 32)))
				link++;
			y++;
		}
		x++;
		y = save_y;
	}
	if (link != 1)
		return (0);
	return (1);
}
