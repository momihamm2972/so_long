/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   excution0.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 16:54:16 by momihamm          #+#    #+#             */
/*   Updated: 2023/05/21 22:52:43 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_red_button(void)
{
	exit (0);
}

void	swap(int row, int indx, char **map, t_struct_of_maps *stc)
{
	if (map[row - 1][indx] == '0' || map[row - 1][indx] == 'C')
	{
		if (map[row - 1][indx] == 'C')
			stc->pc->coll_of_exit++;
		map[row - 1][indx] = 'P';
		map[row][indx] = '0';
		stc->pc->moves++;
		write (1, "MOVE NUMBER =>", 14);
		ft_putnbr (stc->pc->moves);
		write (1, "\n", 1);
	}
	if (stc->pc->count_of_coll == stc->pc->coll_of_exit
		&& map[row - 1][indx] == 'E')
	{
		map[row - 1][indx] = 'P';
		map[row][indx] = '0';
		write (1, "YOU DID IT!!\n", 13);
		exit(0);
	}
}

void	swad(int row, int indx, char **map, t_struct_of_maps *structt)
{
	if (map[row + 1][indx] == '0' || map[row + 1][indx] == 'C')
	{
		if (map[row + 1][indx] == 'C')
			structt->pc->coll_of_exit++;
		map[row + 1][indx] = 'P';
		map[row][indx] = '0';
		structt->pc->moves++;
		write (1, "MOVE NUMBER =>", 14);
		ft_putnbr (structt->pc->moves);
		write (1, "\n", 1);
	}
	if (structt->pc->count_of_coll == structt->pc->coll_of_exit
		&& map[row + 1][indx] == 'E')
	{
		map[row + 1][indx] = 'P';
		map[row][indx] = '0';
		write (1, "YOU DID IT!!\n", 13);
		exit(0);
	}
}

void	swar(int row, int indx, char **map, t_struct_of_maps *stc)
{
	if (map[row][indx + 1] == '0' || map[row][indx + 1] == 'C')
	{
		if (map[row][indx + 1] == 'C')
			stc->pc->coll_of_exit++;
		map[row][indx + 1] = 'P';
		map[row][indx] = '0';
		stc->pc->moves++;
		write (1, "MOVE NUMBER =>", 14);
		ft_putnbr (stc->pc->moves);
		write (1, "\n", 1);
	}
	if (stc->pc->count_of_coll == stc->pc->coll_of_exit
		&& map[row][indx + 1] == 'E')
	{
		map[row][indx + 1] = 'P';
		map[row][indx] = '0';
		write (1, "YOU DID IT!!\n", 13);
		exit(0);
	}
}

void	swal(int row, int indx, char **map, t_struct_of_maps *stc)
{
	if (map[row][indx - 1] == '0' || map[row][indx - 1] == 'C')
	{
		if (map[row][indx - 1] == 'C')
			stc->pc->coll_of_exit++;
		map[row][indx - 1] = 'P';
		map[row][indx] = '0';
		stc->pc->moves++;
		write (1, "MOVE NUMBER =>", 14);
		ft_putnbr (stc->pc->moves);
		write (1, "\n", 1);
	}
	if (stc->pc->count_of_coll == stc->pc->coll_of_exit
		&& map[row][indx - 1] == 'E')
	{
		map[row][indx - 1] = 'P';
		map[row][indx] = '0';
		write (1, "YOU DID IT!!\n", 13);
		exit(0);
	}
}
