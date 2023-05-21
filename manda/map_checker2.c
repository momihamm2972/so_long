/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 19:30:21 by momihamm          #+#    #+#             */
/*   Updated: 2023/05/21 17:26:59 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	counts(char *str, char c)
{
	int	indx;
	int	cont;

	indx = 0;
	cont = 0;
	while (str[indx])
	{
		if (str[indx] == c)
			cont++;
		indx++;
	}
	return (cont);
}

int	counts_zero(char **str, char c)
{
	int	row;
	int	cnt;

	row = 0;
	cnt = 0;
	while (str[row])
	{
		cnt += counts (str[row], c);
		row++;
	}
	return (cnt);
}

void	check_p_e_c(char **str)
{
	if (counts_zero(str, 'P') != 1)
	{
		print_msg();
		exit (0);
	}
	if (counts_zero(str, 'E') != 1)
	{
		print_msg();
		exit (0);
	}
	if (counts_zero(str, 'C') < 1)
	{
		print_msg();
		exit (0);
	}
}

int	count_of_coll(char **arr)
{
	int	row;
	int	ind;
	int	cnt;

	row = 0;
	cnt = 0;
	while (arr[row])
	{
		ind = 0;
		while (arr[row][ind])
		{
			if (arr[row][ind] == 'C')
				cnt++;
			ind++;
		}
		row++;
	}
	return (cnt);
}

// void	if_we_had_a_problem(t_struct_of_maps	*stc_pro, char **map, int drct)
// {
// 	if (drct = 0 && map[])
// }
