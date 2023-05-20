/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 13:25:51 by momihamm          #+#    #+#             */
/*   Updated: 2023/05/18 23:56:15 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_msg(void)
{
	write (1, "somthing wrong in the map!!\n", 28);
}

int	how_many_char_in_the_str(char *str, char c)
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

int	check_borders(char *s, char c)
{
	int	indx;

	indx = 0;
	while (s[indx])
	{
		if (s[indx] != c)
			return (1);
		indx++;
	}
	return (0);
}

int	is_thef_and_thel_is_true(char *str, char c)
{
	int	lent;

	lent = ft_strlen (str) - 1;
	if (str[0] == c && str[lent] == c)
		return (0);
	return (1);
}

int	check_if(char *str, char c)
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
