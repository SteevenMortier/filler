/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smortier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 09:44:34 by smortier          #+#    #+#             */
/*   Updated: 2018/03/18 09:44:37 by smortier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		refresh_map(t_informations *info)
{
	char	*line;
	int		i;
	int		index;

	if (!(info->map = ft_memalloc(sizeof(char *) * info->map_height)))
		return (0);
	index = -1;
	while (++index < info->map_height)
		if (!(info->map[index] = ft_strnew((size_t)info->map_widht)))
			return (0);
	if (get_next_line(0, &line) == -1)
		return (-1);
	if (ft_strncmp(line, "    0", 5))
		return (-1);
	ft_strdel(&line);
	i = -1;
	while (++i < info->map_height)
	{
		if (get_next_line(0, &line) == -1)
			return (-1);
		ft_strcpy(info->map[i], line + 4);
		ft_strdel(&line);
	}
	return (42);
}

int		init_info(t_informations *info)
{
	char	*line;
	int		identifier;

	if (get_next_line(0, &line) == -1)
		return (-1);
	identifier = (int)(line[10]) - 48;
	info->me = (identifier == 1) ? 'o' : 'x';
	info->him = (identifier == 1) ? 'x' : 'o';
	ft_strdel(&line);
	if (get_next_line(0, &line) == -1)
		return (-1);
	info->map_height = ft_atoi(line + 7);
	identifier = 8;
	while (ft_isdigit(line[identifier]))
		identifier += 1;
	info->map_widht = ft_atoi(line + identifier);
	info->target[0] = info->map_height / 2;
	info->target[1] = info->map_widht / 2;
	info->his_last_pos[0] = 0;
	info->his_last_pos[1] = 0;
	info->old_map = NULL;
	ft_strdel(&line);
	return (42);
}

void	leaks_holder(t_informations *info)
{
	int		index;

	index = -1;
	while (++index < info->map_height)
		ft_memdel((void **)&(info->map[index]));
	ft_memdel((void **)&(info->map));
	if (info->piece)
	{
		index = -1;
		while (++index < info->p_height)
			ft_memdel((void **)&(info->piece[index]));
		ft_memdel((void **)&(info->piece));
	}
}

int		main(void)
{
	t_informations	info;
	char			*line;

	if (init_info(&info) == -1)
		return (0);
	info.pos_reached = 0;
	while (42)
	{
		if (refresh_map(&info) == -1)
			return (0);
		if (get_piece(&info) == -1)
			return (0);
		place_piece(&info);
		if (get_next_line(0, &line) == 0)
			return (-1);
		if (line)
			ft_strdel(&line);
		leaks_holder(&info);
	}
}
