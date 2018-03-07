/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smortier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 16:22:27 by smortier          #+#    #+#             */
/*   Updated: 2017/11/14 17:18:26 by smortier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_putnbr_fd(int nb, int fd)
{
	unsigned int	nbr;

	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		nbr = -nb;
	}
	else
		nbr = nb;
	if (nbr != 0)
	{
		while (nbr > 9)
		{
			ft_putnbr_fd(nbr / 10, fd);
			nbr = nbr % 10;
		}
	}
	ft_putchar_fd(nbr % 10 + '0', fd);
}
