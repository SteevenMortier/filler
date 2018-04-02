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

int		just_fill(t_informations *info)
{
	int		index_x;
	int		index_y;

	index_x = -1;
	while (info->map[++index_x])
	{
		index_y = -1;
		while (info->map[++index_y])
		{
			if (check_piece_pos(info, index_x, index_y))
			{
				ft_putnbr(index_x);
				ft_putchar(' ');
				ft_putnbr(index_y);
				ft_putchar('\n');
				return (1);
			}
		}
	}
	ft_putnbr(0);
	ft_putchar(' ');
	ft_putnbr(0);
	ft_putchar('\n');
	return (0);
}

void	reach_the_norm(t_informations *info)
{
	if (check_piece_pos(info, info->place_piece[0], info->place_piece[1]))
	{
//		dprintf(2, "\e[31m JE PRINT AVEC CA : [%d][%d] \e[0m\n", info->place_piece[0], info->place_piece[1]);
		ft_putnbr(info->place_piece[0]);
		ft_putchar(' ');
		ft_putnbr(info->place_piece[1]);
		ft_putchar('\n');
		return ;
	}
	else
		just_fill(info);
}

int		reach_position(t_informations *info)
{
	int		actual_p[2];
	int		index[2];

	actual_p[0] = 0;
	actual_p[1] = 0;
	index[0] = -1;
	info->diff_for_position = 4242;
	if (info->his_last_pos[0] == -42 && info->his_last_pos[1] == -42)
	{
		just_fill(info);
		return (42);
	}
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
