/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   excution1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:57:13 by momihamm          #+#    #+#             */
/*   Updated: 2023/05/18 23:35:01 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_draw(t_struct_of_maps *maps)
{
	maps->ptr_of_call->row = -1;
	maps->ptr_of_call->img_coll = mlx_xpm_file_to_image (maps->ptr_of_call->mlx, "./xpmfiles/AnyConv.com__mamaresized.xpm", &maps->ptr_of_call->a, &maps->ptr_of_call->b);
	maps->ptr_of_call->img_exit = mlx_xpm_file_to_image (maps->ptr_of_call->mlx, "./xpmfiles/AnyConv.com__lock.xpm", &maps->ptr_of_call->a, &maps->ptr_of_call->b);
	maps->ptr_of_call->img_wall = mlx_xpm_file_to_image(maps->ptr_of_call->mlx, "./xpmfiles/god_of_war.xpm", &maps->ptr_of_call->a, &maps->ptr_of_call->b);
	maps->ptr_of_call->img_ply = mlx_xpm_file_to_image (maps->ptr_of_call->mlx, "./xpmfiles/__char00012 (1).xpm", &maps->ptr_of_call->a, &maps->ptr_of_call->b);
	if (maps->ptr_of_call->count_of_coll == maps->ptr_of_call->coll_of_exit)
		return (ft_draw_exit(maps));
	while (maps->cp_maphya[++maps->ptr_of_call->row])
	{
		maps->ptr_of_call->clm = -1;
		while (maps->cp_maphya[maps->ptr_of_call->row][++maps->ptr_of_call->clm])
		{
			if (maps->cp_maphya[maps->ptr_of_call->row][maps->ptr_of_call->clm] == '1')
				mlx_put_image_to_window (maps->ptr_of_call->mlx, maps->ptr_of_call->mlx_win, maps->ptr_of_call->img_wall, (maps->ptr_of_call->clm * maps->ptr_of_call->a), (maps->ptr_of_call->row * maps->ptr_of_call->a));
			else if (maps->cp_maphya[maps->ptr_of_call->row][maps->ptr_of_call->clm] == 'C')
				mlx_put_image_to_window (maps->ptr_of_call->mlx, maps->ptr_of_call->mlx_win, maps->ptr_of_call->img_coll, (maps->ptr_of_call->clm * maps->ptr_of_call->a), (maps->ptr_of_call->row * maps->ptr_of_call->a));
			else if (maps->cp_maphya[maps->ptr_of_call->row][maps->ptr_of_call->clm] == 'E')
				mlx_put_image_to_window (maps->ptr_of_call->mlx, maps->ptr_of_call->mlx_win, maps->ptr_of_call->img_exit, (maps->ptr_of_call->clm * maps->ptr_of_call->a), (maps->ptr_of_call->row * maps->ptr_of_call->a));
			else if (maps->cp_maphya[maps->ptr_of_call->row][maps->ptr_of_call->clm] == 'P')
				mlx_put_image_to_window (maps->ptr_of_call->mlx, maps->ptr_of_call->mlx_win, maps->ptr_of_call->img_ply, (maps->ptr_of_call->clm * maps->ptr_of_call->a), (maps->ptr_of_call->row * maps->ptr_of_call->a));
			else if (maps->cp_maphya[maps->ptr_of_call->row][maps->ptr_of_call->clm] == 'X')
				mlx_put_image_to_window (maps->ptr_of_call->mlx, maps->ptr_of_call->mlx_win, maps->ptr_of_call->img_exit_open, (maps->ptr_of_call->clm * maps->ptr_of_call->a), (maps->ptr_of_call->row * maps->ptr_of_call->a));
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
	maps->ptr_of_call->row = -1;
	maps->ptr_of_call->img_coll = mlx_xpm_file_to_image (maps->ptr_of_call->mlx, "./xpmfiles/AnyConv.com__mamaresized.xpm", &maps->ptr_of_call->a, &maps->ptr_of_call->b);
	maps->ptr_of_call->img_exit_open = mlx_xpm_file_to_image (maps->ptr_of_call->mlx, "./xpmfiles/mimi.xpm", &maps->ptr_of_call->a, &maps->ptr_of_call->b);
	maps->ptr_of_call->img_wall = mlx_xpm_file_to_image(maps->ptr_of_call->mlx, "./xpmfiles/god_of_war.xpm", &maps->ptr_of_call->a, &maps->ptr_of_call->b);
	maps->ptr_of_call->img_ply = mlx_xpm_file_to_image (maps->ptr_of_call->mlx, "./xpmfiles/__char00012 (1).xpm", &maps->ptr_of_call->a, &maps->ptr_of_call->b);
	while (maps->cp_maphya[++maps->ptr_of_call->row])
	{
		maps->ptr_of_call->clm = 0;
		while (maps->cp_maphya[maps->ptr_of_call->row][maps->ptr_of_call->clm])
		{
			if (maps->cp_maphya[maps->ptr_of_call->row][maps->ptr_of_call->clm] == '1')
				mlx_put_image_to_window (maps->ptr_of_call->mlx, maps->ptr_of_call->mlx_win, maps->ptr_of_call->img_wall, (maps->ptr_of_call->clm * maps->ptr_of_call->a), (maps->ptr_of_call->row * maps->ptr_of_call->a));
			else if (maps->cp_maphya[maps->ptr_of_call->row][maps->ptr_of_call->clm] == 'C')
				mlx_put_image_to_window (maps->ptr_of_call->mlx, maps->ptr_of_call->mlx_win, maps->ptr_of_call->img_coll, (maps->ptr_of_call->clm * maps->ptr_of_call->a), (maps->ptr_of_call->row * maps->ptr_of_call->a));
			else if (maps->cp_maphya[maps->ptr_of_call->row][maps->ptr_of_call->clm] == 'E')
				mlx_put_image_to_window (maps->ptr_of_call->mlx, maps->ptr_of_call->mlx_win, maps->ptr_of_call->img_exit_open, (maps->ptr_of_call->clm * maps->ptr_of_call->a), (maps->ptr_of_call->row * maps->ptr_of_call->a));
			else if (maps->cp_maphya[maps->ptr_of_call->row][maps->ptr_of_call->clm] == 'P')
				mlx_put_image_to_window (maps->ptr_of_call->mlx, maps->ptr_of_call->mlx_win, maps->ptr_of_call->img_ply, (maps->ptr_of_call->clm * maps->ptr_of_call->a), (maps->ptr_of_call->row * maps->ptr_of_call->a));
			else if (maps->cp_maphya[maps->ptr_of_call->row][maps->ptr_of_call->clm] == 'X')
				mlx_put_image_to_window (maps->ptr_of_call->mlx, maps->ptr_of_call->mlx_win, maps->ptr_of_call->img_exit_open, (maps->ptr_of_call->clm * maps->ptr_of_call->a), (maps->ptr_of_call->row * maps->ptr_of_call->a));
			maps->ptr_of_call->clm++;
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
	mlx_clear_window (structt->ptr_of_call->mlx, structt->ptr_of_call->mlx_win);
	mlx_destroy_image (structt->ptr_of_call->mlx, structt->ptr_of_call->img_ply);
	mlx_destroy_image (structt->ptr_of_call->mlx, structt->ptr_of_call->img_coll);
	mlx_destroy_image (structt->ptr_of_call->mlx, structt->ptr_of_call->img_wall);
	mlx_destroy_image (structt->ptr_of_call->mlx, structt->ptr_of_call->img_exit);
	ft_draw(structt);
	return (0);
}
