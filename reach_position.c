/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reach_position.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smortier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 13:18:35 by smortier          #+#    #+#             */
/*   Updated: 2018/03/18 13:18:38 by smortier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	reach_norme_bis(t_informations *info)
{
	int		map_x;
	int		map_y;

	info->diff_for_position = 4242;
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

void	reach_the_norm(t_informations *info)
{
	if (check_piece_pos(info, info->place_piece[0], info->place_piece[1]))
	{
		ft_putnbr(info->place_piece[0]);
		ft_putchar(' ');
		ft_putnbr(info->place_piece[1]);
		ft_putchar('\n');
	}
	else
		reach_norme_bis(info);
}

int		reach_position(t_informations *info)
{
	int		actual_p[2];
	int		index[2];

	actual_p[0] = 0;
	actual_p[1] = 0;
	index[0] = -1;
	info->diff_for_position = 4242;
	while (++index[0] < info->map_height)
	{
		index[1] = -1;
		while (++index[1] < info->map_widht)
		{
			if ((info->map[index[0]][index[1]] == info->me) ||
					(info->map[index[0]][index[1]] == info->me - 32))
			{
				actual_p[0] = index[0];
				actual_p[1] = index[1];
				all_try_for_piece(info, actual_p[0], actual_p[1]);
			}
			actual_p[1] += 1;
		}
		actual_p[0] += 1;
	}
	reach_the_norm(info);
	return (42);
}
