/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 19:07:26 by momihamm          #+#    #+#             */
/*   Updated: 2023/05/15 20:15:37 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    ft_putchar (char c)
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
