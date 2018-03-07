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
	dprintf(2, "\e[34m line[%s]\n\e[0m", line);
	if (ft_strncmp(line, "    0", 5))
	{
		ft_putstr_fd("Error with VM input", 2);
		return (-1);
	}
	ft_strdel(&line);
	i = -1;
	while (++i < info->map_height)
	{
		if (get_next_line(0, &line) == -1)
		{
			ft_putstr_fd("Error with get_next_line", 2);
			return (-1);
		}
		dprintf(2, "\e[34m line[%d] = [%s]\n\e[0m", i % 10, line);
//		info->map[i] = ft_strsub(line, 4, (size_t)info->map_widht);
		ft_strcpy(info->map[i], line + 4);
		ft_strdel(&line);
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
	ft_strdel(&line);
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
	ft_strdel(&line);
	return (42);
}

int		main()
{
	t_informations	info;
	int				index;
	char			*line;

	if (init_info(&info) == -1)
		return (0);
	dprintf(2, "\e[33m im the [%c]\n\e[0m", info.me);
	dprintf(2, "\e[33m map_max = [%d][%d]\n\e[0m", info.map_widht, info.map_height);
	if (!(info.map = ft_memalloc(sizeof(char *) * info.map_height)))
		return (0);
	index = -1;
	while (++index < info.map_height)
		if (!(info.map[index] = ft_strnew((size_t)info.map_widht)))
			return (0);
	info.pos_reached = 0;
	////// CA COMMENCE A BOUCLER ICI
	while (42)
	{
		index = -1;
		if (refresh_map(&info) == -1)
			return (0);
		while (++index < info.map_height)
			dprintf(2, "\e[33mmap[%d] = [%s]\n\e[0m",index % 10, info.map[index]);
		get_piece(&info);
		place_piece(&info);
		if (get_next_line(0, &line) == -1)
		{
			ft_putstr_fd("Error with get_next_line", 2);
			return (-1);
		}
		ft_strdel(&line);
		//place piece avec algo demain fini ?? (lol)(.....) =)
		//(+ visu ??) apres demain inchalla ??
	}
	return (0);
}