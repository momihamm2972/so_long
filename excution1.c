/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   excution1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:57:13 by momihamm          #+#    #+#             */
/*   Updated: 2023/05/19 23:31:56 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_draw(t_struct_of_maps *maps)
{
	maps->p_o_c->row = -1;
	maps->p_o_c->img_coll = mlx_xpm_file_to_image (maps->p_o_c->mlx, "./xpm/zd.xpm", &maps->p_o_c->a, &maps->p_o_c->b);
	maps->p_o_c->img_exit = mlx_xpm_file_to_image (maps->p_o_c->mlx, "./xpm/k.xpm", &maps->p_o_c->a, &maps->p_o_c->b);
	maps->p_o_c->img_wall = mlx_xpm_file_to_image(maps->p_o_c->mlx, "./xpm/w.xpm", &maps->p_o_c->a, &maps->p_o_c->b);
	maps->p_o_c->img_ply = mlx_xpm_file_to_image (maps->p_o_c->mlx, "./xpm/c.xpm", &maps->p_o_c->a, &maps->p_o_c->b);
	if (maps->p_o_c->count_of_coll == maps->p_o_c->coll_of_exit)
		return (ft_draw_exit(maps));
	while (maps->cp_maphya[++maps->p_o_c->row])
	{
		maps->p_o_c->clm = -1;
		while (maps->cp_maphya[maps->p_o_c->row][++maps->p_o_c->clm])
		{
			if (maps->cp_maphya[maps->p_o_c->row][maps->p_o_c->clm] == '1')
				mlx_put_image_to_window (maps->p_o_c->mlx, maps->p_o_c->mlx_win, maps->p_o_c->img_wall, (maps->p_o_c->clm * maps->p_o_c->a), (maps->p_o_c->row * maps->p_o_c->a));
			else if (maps->cp_maphya[maps->p_o_c->row][maps->p_o_c->clm] == 'C')
				mlx_put_image_to_window (maps->p_o_c->mlx, maps->p_o_c->mlx_win, maps->p_o_c->img_coll, (maps->p_o_c->clm * maps->p_o_c->a), (maps->p_o_c->row * maps->p_o_c->a));
			else if (maps->cp_maphya[maps->p_o_c->row][maps->p_o_c->clm] == 'E')
				mlx_put_image_to_window (maps->p_o_c->mlx, maps->p_o_c->mlx_win, maps->p_o_c->img_exit, (maps->p_o_c->clm * maps->p_o_c->a), (maps->p_o_c->row * maps->p_o_c->a));
			else if (maps->cp_maphya[maps->p_o_c->row][maps->p_o_c->clm] == 'P')
				mlx_put_image_to_window (maps->p_o_c->mlx, maps->p_o_c->mlx_win, maps->p_o_c->img_ply, (maps->p_o_c->clm * maps->p_o_c->a), (maps->p_o_c->row * maps->p_o_c->a));
			else if (maps->cp_maphya[maps->p_o_c->row][maps->p_o_c->clm] == 'X')
				mlx_put_image_to_window (maps->p_o_c->mlx, maps->p_o_c->mlx_win, maps->p_o_c->img_exit_open, (maps->p_o_c->clm * maps->p_o_c->a), (maps->p_o_c->row * maps->p_o_c->a));
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
			if (map[row][clm] != 'C' && map[row][clm] != 'P' && map[row][clm] != 'E' && map[row][clm] != '0' && map[row][clm] != '1')
			{
				print_msg();
				exit(0);
			}
			clm++;
		}
		row++;
	}
}

void	ft_draw_exit(t_struct_of_maps *maps)
{
	maps->p_o_c->row = -1;
	maps->p_o_c->img_coll = mlx_xpm_file_to_image (maps->p_o_c->mlx, "./xpm/zd.xpm", &maps->p_o_c->a, &maps->p_o_c->b);
	maps->p_o_c->img_exit_open = mlx_xpm_file_to_image (maps->p_o_c->mlx, "./xpm/i.xpm", &maps->p_o_c->a, &maps->p_o_c->b);
	maps->p_o_c->img_wall = mlx_xpm_file_to_image(maps->p_o_c->mlx, "./xpm/w.xpm", &maps->p_o_c->a, &maps->p_o_c->b);
	maps->p_o_c->img_ply = mlx_xpm_file_to_image (maps->p_o_c->mlx, "./xpm/c.xpm", &maps->p_o_c->a, &maps->p_o_c->b);
	while (maps->cp_maphya[++maps->p_o_c->row])
	{
		maps->p_o_c->clm = 0;
		while (maps->cp_maphya[maps->p_o_c->row][maps->p_o_c->clm])
		{
			if (maps->cp_maphya[maps->p_o_c->row][maps->p_o_c->clm] == '1')
				mlx_put_image_to_window (maps->p_o_c->mlx, maps->p_o_c->mlx_win, maps->p_o_c->img_wall, (maps->p_o_c->clm * maps->p_o_c->a), (maps->p_o_c->row * maps->p_o_c->a));
			else if (maps->cp_maphya[maps->p_o_c->row][maps->p_o_c->clm] == 'C')
				mlx_put_image_to_window (maps->p_o_c->mlx, maps->p_o_c->mlx_win, maps->p_o_c->img_coll, (maps->p_o_c->clm * maps->p_o_c->a), (maps->p_o_c->row * maps->p_o_c->a));
			else if (maps->cp_maphya[maps->p_o_c->row][maps->p_o_c->clm] == 'E')
				mlx_put_image_to_window (maps->p_o_c->mlx, maps->p_o_c->mlx_win, maps->p_o_c->img_exit_open, (maps->p_o_c->clm * maps->p_o_c->a), (maps->p_o_c->row * maps->p_o_c->a));
			else if (maps->cp_maphya[maps->p_o_c->row][maps->p_o_c->clm] == 'P')
				mlx_put_image_to_window (maps->p_o_c->mlx, maps->p_o_c->mlx_win, maps->p_o_c->img_ply, (maps->p_o_c->clm * maps->p_o_c->a), (maps->p_o_c->row * maps->p_o_c->a));
			else if (maps->cp_maphya[maps->p_o_c->row][maps->p_o_c->clm] == 'X')
				mlx_put_image_to_window (maps->p_o_c->mlx, maps->p_o_c->mlx_win, maps->p_o_c->img_exit_open, (maps->p_o_c->clm * maps->p_o_c->a), (maps->p_o_c->row * maps->p_o_c->a));
			maps->p_o_c->clm++;
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
				swap_dwn(row, indx, map, structt);
				return ;
			}
			else if (map[row][indx] == 'P' && parm == 2)
			{
				swap_rh(row, indx, map, structt);
				return ;
			}
			else if (map[row][indx] == 'P' && parm == 3)
				swap_lf (row, indx, map, structt);
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
	mlx_clear_window (structt->p_o_c->mlx, structt->p_o_c->mlx_win);
	mlx_destroy_image (structt->p_o_c->mlx, structt->p_o_c->img_ply);
	mlx_destroy_image (structt->p_o_c->mlx, structt->p_o_c->img_coll);
	mlx_destroy_image (structt->p_o_c->mlx, structt->p_o_c->img_wall);
	mlx_destroy_image (structt->p_o_c->mlx, structt->p_o_c->img_exit);
	ft_draw(structt);
	return (0);
}
