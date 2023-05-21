/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 19:07:26 by momihamm          #+#    #+#             */
/*   Updated: 2023/05/21 01:35:52 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb >= 0 && nb < 10)
		ft_putchar (nb + '0');
	if (nb > 9)
	{
		ft_putnbr (nb / 10);
		ft_putnbr (nb % 10);
	}
	if (nb < 0 && nb > -2147483648)
	{
		write (1, "-", 1);
		nb *= -1;
		ft_putnbr (nb);
	}
	if (nb == -2147483648)
		write (1, "-2147483648", 11);
}

int	check_is_thepath_is_v(char **arr)
{
	int	roww;
	int	indx;

	roww = 0;
	while (arr[roww])
	{
		indx = 0;
		while (arr[roww][indx])
		{
			if (arr[roww][indx] == 'P' || arr[roww][indx] == 'C'
					|| arr[roww][indx] == 'E' || arr[roww][indx] == '0')
				return (1);
			indx++;
		}
		roww++;
	}
	return (0);
}

int	row_of_p(char **map)
{
	int	row;
	int	clm;

	row = 0;
	while (map[row])
	{
		clm = 0;
		while (map[row][clm])
		{
			if (map[row][clm] == 'P')
				return (row);
			clm++;
		}
		row++;
	}
	return (-1);
}

int	clm_of_p(char **map)
{
	int	row;
	int	clm;

	row = 0;
	while (map[row])
	{
		clm = 0;
		while (map[row][clm])
		{
			if (map[row][clm] == 'P')
				return (clm);
			clm++;
		}
		row++;
	}
	return (-1);
}
