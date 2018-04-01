/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smortier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 09:44:44 by smortier          #+#    #+#             */
/*   Updated: 2018/03/18 09:44:47 by smortier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H

# define FILLER_H

# include "../libft/libft.h"

# include "get_next_line.h"

# include <stdio.h>

# include <stdlib.h>

# include <unistd.h>

# define ABS(x) ((x) < 0 ? -(x) : (x))

typedef struct		s_informations
{
	int		me;
	int		him;
	int		map_widht;
	int		map_height;
	char	**map;
	char	**old_map;
	int		p_widht;
	int		p_height;
	char	**piece;
	int		first_pos[2];
	int		his_first_pos[2];
	int		his_last_pos[2];
	int		reach_the_position[2];
	int		place_piece[2];
	int		pos_reached;
	int		diff_for_position;
	int		target[2];
}					t_informations;

int					get_piece(t_informations *info);

void				artif_intel(t_informations *info);

int					place_piece(t_informations *info);

int					reach_position(t_informations *info);

void				all_try_for_piece(t_informations *info, int x, int y);

int					check_piece_pos(t_informations *info, int x, int y);

#endif
