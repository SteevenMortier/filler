///HEADER
///HEADER
///HEADER
///HEADER
///HEADER
///HEADER
///HEADER
///HEADER

#include "filler.h"

int		create_piece(t_informations *info)
{
	int		index;
	char	*line;

	info->piece = ft_memalloc(sizeof(char *) * info->map_height);
	index = -1;
	while (++index < info->p_height)
	{
		info->piece[index] = ft_strnew(info->p_widht);
		if (get_next_line(0, &line) == -1)
		{
			ft_putstr_fd("Error with get_next_line", 2);
			return (-1);
		}
		ft_strcpy(info->piece[index], line);
		ft_strdel(&line);
	}
	return (42);
}

int		get_piece(t_informations *info)
{
	char	*line;
	int		index;

	if (get_next_line(0, &line) == -1)
	{
		ft_putstr_fd("Error with get_next_line", 2);
		return (-1);
	}
//	dprintf(2, "\e[31m line[%s]\n\e[0m", line);
	if (!ft_strstr(line, "Piece "))
	{
		ft_putstr_fd("Error with VM input", 2);
		return (1);
	}
	info->p_height = ft_atoi(line + 6);
	index = 6;
	while (ft_isdigit(line[index]))
		index++;
	info->p_widht = ft_atoi(line + index);
//	dprintf(2, "\e[32m taille de la piece x = [%d] y = [%d]\n\e[0m", info->p_widht, info->p_height);
	ft_strdel(&line);
	if (create_piece(info) == -1)
		return (-1);
	return (42);
}