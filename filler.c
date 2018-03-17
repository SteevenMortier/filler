///HEADER
///HEADER
///HEADER
///HEADER
///HEADER
///HEADER
///HEADER

#include "filler.h"

int		refresh_map(t_informations		*info)
{
	char	*line;
	int		i;

	if (get_next_line(0, &line) == -1)
	{
		ft_putstr_fd("Error with get_next_line", 2);
		return (-1);
	}
//	dprintf(2, "\e[34m line[%s]\n\e[0m", line);
	if (ft_strncmp(line, "    0", 5))
	{
		//ft_putstr_fd("Error with VM input", 2);
		return (-1);
	}
//	ft_strdel(&line);
	i = -1;
	while (++i < info->map_height)
	{
		if (get_next_line(0, &line) == -1)
		{
			ft_putstr_fd("Error with get_next_line", 2);
			return (-1);
		}
//		dprintf(2, "\e[34m line[%d] = [%s]\n\e[0m", i % 10, line);
//		info->map[i] = ft_strsub(line, 4, (size_t)info->map_widht);
		ft_strcpy(info->map[i], line + 4);
//		ft_strdel(&line);
	}
	return (42);
}

int		init_info(t_informations	*info)
{
	char	*line;
	int		identifier;

	if (get_next_line(0, &line) == -1)
	{
		ft_putstr_fd("Error with get_next_line", 2);
		return (-1);
	}
	identifier = (int)(line[10]) - 48;
	info->me = (identifier == 1) ? 'o' : 'x';
	info->him = (identifier == 1) ? 'x' : 'o';
//	ft_strdel(&line);
	if (get_next_line(0, &line) == -1)
	{
		ft_putstr_fd("Error with get_next_line", 2);
		return (-1);
	}
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
//	ft_strdel(&line);
	return (42);
}

void	leaks_holder(t_informations *info)
{
	int		index;

	index = -1;
	while (++index < info->map_height)
		ft_memdel((void **)&(info->map[index]));
	ft_memdel((void **)&(info->map));
//	ft_memdel((void **)&(info));
}

int		main()
{
	t_informations	info;
	int				index;
	char			*line;

	if (init_info(&info) == -1)
		return (0);
	if (!(info.map = ft_memalloc(sizeof(char *) * info.map_height)))
		return (0);
	index = -1;
	while (++index < info.map_height)
		if (!(info.map[index] = ft_strnew((size_t)info.map_widht)))
			return (0);
	info.pos_reached = 0;
	while (42)
	{
		index = -1;
		if (refresh_map(&info) == -1)
			return (0);
		if (get_piece(&info) == -1)
			return (0);
		place_piece(&info);
		if (get_next_line(0, &line) == -1)
		{
			ft_putstr_fd("Error with get_next_line", 2);
			return (-1);
		}
//		dprintf(2, "\e[32m Line = [%s]\n\e[0m", line);
		if (!line)
		{
//			dprintf(2, "\e[32m We are in\n\e[0m");
			leaks_holder(&info);
//			sleep(10);
			exit(1);
		}
		if (info.piece)
		{
			index = -1;
			while (++index < info.p_height)
				ft_memdel((void **)&(info.piece[index]));
			ft_memdel((void **)&(info.piece));
		}
//		ft_strdel(&line);
	}
}
