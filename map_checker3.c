/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 21:09:50 by momihamm          #+#    #+#             */
/*   Updated: 2023/05/19 00:22:08 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	num_of_lines(char **arr)
{
	int	lines;

	lines = 0;
	while (arr[lines])
		lines++;
	return (lines);
}

int	flodfill(int i, int j, char **arr)
{
	int	m;
	int	l;

	m = (int) ft_strlen (arr[0]);
	l = num_of_lines(arr);
	if (i < 0 || i >= l || j < 0 || j >= m)
		return (0);
	if (arr[i][j] == 'V' || arr[i][j] == '1')
		return (0);
	arr[i][j] = 'V';
	flodfill(i + 1, j, arr);
	flodfill(i - 1, j, arr);
	flodfill(i, j + 1, arr);
	flodfill(i, j - 1, arr);
	return (5);
}

int	check_the_path(char **arr)
{
	int	row;
	int	clm;

	row = 0;
	while (arr[row])
	{
		clm = 0;
		while (arr[row][clm])
		{
			if (arr[row][clm] == 'C' || arr[row][clm] == 'P'
					|| arr[row][clm] == 'E' || arr[row][clm] == '0')
				return (1);
			clm++;
		}
		row++;
	}
	return (0);
}
