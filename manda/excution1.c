/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   excution1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:57:13 by momihamm          #+#    #+#             */
/*   Updated: 2023/05/20 19:25:45 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_draw(t_struct_of_maps *mp)
{
	mp->pc->row = -1;
	intai_var(mp);
	if (mp->pc->count_of_coll == mp->pc->coll_of_exit)
		return (ft_draw_exit(mp));
	while (mp->cp_maphya[++mp->pc->row])
	{
		mp->pc->clm = -1;
		while (mp->cp_maphya[mp->pc->row][++mp->pc->clm])
		{
			if (mp->cp_maphya[mp->pc->row][mp->pc->clm] == '1')
				mlx_put_image_to_window (mp->pc->mlx, mp->pc->x_w, mp->pc->i_w,
					(mp->pc->clm * mp->pc->a), (mp->pc->row * mp->pc->a));
			else if (mp->cp_maphya[mp->pc->row][mp->pc->clm] == 'C')
				mlx_put_image_to_window (mp->pc->mlx, mp->pc->x_w, mp->pc->i_c,
					(mp->pc->clm * mp->pc->a), (mp->pc->row * mp->pc->a));
			else if (mp->cp_maphya[mp->pc->row][mp->pc->clm] == 'E')
				mlx_put_image_to_window (mp->pc->mlx, mp->pc->x_w, mp->pc->i_e,
					(mp->pc->clm * mp->pc->a), (mp->pc->row * mp->pc->a));
			else if (mp->cp_maphya[mp->pc->row][mp->pc->clm] == 'P')
				mlx_put_image_to_window (mp->pc->mlx, mp->pc->x_w, mp->pc->i_p,
					(mp->pc->clm * mp->pc->a), (mp->pc->row * mp->pc->a));
		}
	}
}

void	check_if_the_map_has_wrong_char(char **map)
{
	int	row;
	int	clm;

	row = 0;
	while (map[row])
	{
		clm = 0;
		while (map[row][clm])
		{
			if (map[row][clm] != 'C' && map[row][clm] != 'P'
				&& map[row][clm] != 'E' && map[row][clm] != '0'
					&& map[row][clm] != '1')
			{
				print_msg();
				exit(0);
			}
			clm++;
		}
		row++;
	}
}

void	ft_draw_exit(t_struct_of_maps *mp)
{
	mp->pc->row = -1;
	intai_var(mp);
	while (mp->cp_maphya[++mp->pc->row])
	{
		mp->pc->clm = -1;
		while (mp->cp_maphya[mp->pc->row][++mp->pc->clm])
		{
			if (mp->cp_maphya[mp->pc->row][mp->pc->clm] == '1')
				mlx_put_image_to_window (mp->pc->mlx, mp->pc->x_w, mp->pc->i_w,
					(mp->pc->clm * mp->pc->a), (mp->pc->row * mp->pc->a));
			else if (mp->cp_maphya[mp->pc->row][mp->pc->clm] == 'C')
				mlx_put_image_to_window (mp->pc->mlx, mp->pc->x_w, mp->pc->i_c,
					(mp->pc->clm * mp->pc->a), (mp->pc->row * mp->pc->a));
			else if (mp->cp_maphya[mp->pc->row][mp->pc->clm] == 'E')
				mlx_put_image_to_window (mp->pc->mlx, mp->pc->x_w, mp->pc->i_eo,
					(mp->pc->clm * mp->pc->a), (mp->pc->row * mp->pc->a));
			else if (mp->cp_maphya[mp->pc->row][mp->pc->clm] == 'P')
				mlx_put_image_to_window (mp->pc->mlx, mp->pc->x_w, mp->pc->i_p,
					(mp->pc->clm * mp->pc->a), (mp->pc->row * mp->pc->a));
		}
	}
}

void	plyer(char **map, int parm, t_struct_of_maps *structt)
{
	int	indx;
	int	row;

	row = -1;
	while (map[++row])
	{
		indx = -1;
		while (map[row][++indx])
		{
			if (map[row][indx] == 'P' && parm == 0)
				swap (row, indx, map, structt);
			else if (map[row][indx] == 'P' && parm == 1)
			{
				swad(row, indx, map, structt);
				return ;
			}
			else if (map[row][indx] == 'P' && parm == 2)
			{
				swar(row, indx, map, structt);
				return ;
			}
			else if (map[row][indx] == 'P' && parm == 3)
				swal (row, indx, map, structt);
		}
	}
}

int	ft_move(int key_hook, t_struct_of_maps *structt)
{
	if (key_hook == 53)
		close_red_button();
	else if (key_hook == 126 || key_hook == 13)
		plyer(structt->maphya, 0, structt);
	else if (key_hook == 125 || key_hook == 1)
		plyer(structt->maphya, 1, structt);
	else if (key_hook == 124 || key_hook == 2)
		plyer(structt->maphya, 2, structt);
	else if (key_hook == 123 || key_hook == 0)
		plyer(structt->maphya, 3, structt);
	mlx_clear_window (structt->pc->mlx, structt->pc->x_w);
	mlx_destroy_image (structt->pc->mlx, structt->pc->i_p);
	mlx_destroy_image (structt->pc->mlx, structt->pc->i_c);
	mlx_destroy_image (structt->pc->mlx, structt->pc->i_w);
	mlx_destroy_image (structt->pc->mlx, structt->pc->i_e);
	ft_draw(structt);
	return (0);
}
