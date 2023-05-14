/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   excution1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:57:13 by momihamm          #+#    #+#             */
/*   Updated: 2023/05/14 22:02:41 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    ft_draw(t_struct_of_maps *maps)
{
    maps->ptr_of_call->row = -1;
    maps->ptr_of_call->img_coll = mlx_xpm_file_to_image (maps->ptr_of_call->mlx, "./xpmfiles/AnyConv.com__mamaresized.xpm", &maps->ptr_of_call->a ,&maps->ptr_of_call->b);
    maps->ptr_of_call->img_exit = mlx_xpm_file_to_image (maps->ptr_of_call->mlx, "./xpmfiles/AnyConv.com__lock.xpm", &maps->ptr_of_call->a ,&maps->ptr_of_call->b);
    maps->ptr_of_call->img_wall = mlx_xpm_file_to_image(maps->ptr_of_call->mlx, "./xpmfiles/god_of_war.xpm", &maps->ptr_of_call->a, &maps->ptr_of_call->b);
    maps->ptr_of_call->img_ply = mlx_xpm_file_to_image (maps->ptr_of_call->mlx, "./xpmfiles/__char00012 (1).xpm", &maps->ptr_of_call->a ,&maps->ptr_of_call->b);
    if (maps->ptr_of_call->count_of_coll == maps->ptr_of_call->coll_of_exit)
    {
        ft_draw_exit(maps);
        return;
    }
while (maps->cp_maphya[++maps->ptr_of_call->row])
        {
            maps->ptr_of_call->clm = -1;
            while (maps->cp_maphya[maps->ptr_of_call->row][++maps->ptr_of_call->clm])
            {
                if (maps->cp_maphya[maps->ptr_of_call->row][maps->ptr_of_call->clm] == '1')
                    mlx_put_image_to_window (maps->ptr_of_call->mlx , maps->ptr_of_call->mlx_win ,maps->ptr_of_call->img_wall,(maps->ptr_of_call->clm * maps->ptr_of_call->a),(maps->ptr_of_call->row * maps->ptr_of_call->a));
                else if (maps->cp_maphya[maps->ptr_of_call->row][maps->ptr_of_call->clm] == 'C')
                    mlx_put_image_to_window (maps->ptr_of_call->mlx , maps->ptr_of_call->mlx_win ,maps->ptr_of_call->img_coll,(maps->ptr_of_call->clm * maps->ptr_of_call->a),(maps->ptr_of_call->row * maps->ptr_of_call->a));
                else if (maps->cp_maphya[maps->ptr_of_call->row][maps->ptr_of_call->clm] == 'E')
                    mlx_put_image_to_window (maps->ptr_of_call->mlx , maps->ptr_of_call->mlx_win ,maps->ptr_of_call->img_exit,(maps->ptr_of_call->clm * maps->ptr_of_call->a),(maps->ptr_of_call->row * maps->ptr_of_call->a));
                else if (maps->cp_maphya[maps->ptr_of_call->row][maps->ptr_of_call->clm] == 'P')
                    mlx_put_image_to_window (maps->ptr_of_call->mlx , maps->ptr_of_call->mlx_win ,maps->ptr_of_call->img_ply,(maps->ptr_of_call->clm * maps->ptr_of_call->a),(maps->ptr_of_call->row * maps->ptr_of_call->a));
                else if (maps->cp_maphya[maps->ptr_of_call->row][maps->ptr_of_call->clm] == 'X')
                    mlx_put_image_to_window (maps->ptr_of_call->mlx , maps->ptr_of_call->mlx_win ,maps->ptr_of_call->img_exit_open,(maps->ptr_of_call->clm * maps->ptr_of_call->a),(maps->ptr_of_call->row * maps->ptr_of_call->a));
                // maps->ptr_of_call->clm++;
            }
            // maps->ptr_of_call->row++;
        }
}

void    check_if_the_map_has_wrong_char(char **map)
{
    int row;
    int clm;

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

void    ft_draw_exit(t_struct_of_maps *maps)
{
    maps->ptr_of_call->row = -1;
    maps->ptr_of_call->img_coll = mlx_xpm_file_to_image (maps->ptr_of_call->mlx, "./xpmfiles/AnyConv.com__mamaresized.xpm", &maps->ptr_of_call->a ,&maps->ptr_of_call->b);
    maps->ptr_of_call->img_exit_open = mlx_xpm_file_to_image (maps->ptr_of_call->mlx, "./xpmfiles/mimi.xpm", &maps->ptr_of_call->a ,&maps->ptr_of_call->b);
    maps->ptr_of_call->img_wall = mlx_xpm_file_to_image(maps->ptr_of_call->mlx, "./xpmfiles/god_of_war.xpm", &maps->ptr_of_call->a, &maps->ptr_of_call->b);
    maps->ptr_of_call->img_ply = mlx_xpm_file_to_image (maps->ptr_of_call->mlx, "./xpmfiles/__char00012 (1).xpm", &maps->ptr_of_call->a ,&maps->ptr_of_call->b);
while (maps->cp_maphya[++maps->ptr_of_call->row])
        {
            maps->ptr_of_call->clm = 0;
            while (maps->cp_maphya[maps->ptr_of_call->row][maps->ptr_of_call->clm])
            {
                if (maps->cp_maphya[maps->ptr_of_call->row][maps->ptr_of_call->clm] == '1')
                    mlx_put_image_to_window (maps->ptr_of_call->mlx , maps->ptr_of_call->mlx_win ,maps->ptr_of_call->img_wall,(maps->ptr_of_call->clm * maps->ptr_of_call->a),(maps->ptr_of_call->row * maps->ptr_of_call->a));
                else if (maps->cp_maphya[maps->ptr_of_call->row][maps->ptr_of_call->clm] == 'C')
                    mlx_put_image_to_window (maps->ptr_of_call->mlx , maps->ptr_of_call->mlx_win ,maps->ptr_of_call->img_coll,(maps->ptr_of_call->clm * maps->ptr_of_call->a),(maps->ptr_of_call->row * maps->ptr_of_call->a));
                else if (maps->cp_maphya[maps->ptr_of_call->row][maps->ptr_of_call->clm] == 'E')
                    mlx_put_image_to_window (maps->ptr_of_call->mlx , maps->ptr_of_call->mlx_win ,maps->ptr_of_call->img_exit_open,(maps->ptr_of_call->clm * maps->ptr_of_call->a),(maps->ptr_of_call->row * maps->ptr_of_call->a));
                else if (maps->cp_maphya[maps->ptr_of_call->row][maps->ptr_of_call->clm] == 'P')
                    mlx_put_image_to_window (maps->ptr_of_call->mlx , maps->ptr_of_call->mlx_win ,maps->ptr_of_call->img_ply,(maps->ptr_of_call->clm * maps->ptr_of_call->a),(maps->ptr_of_call->row * maps->ptr_of_call->a));
                else if (maps->cp_maphya[maps->ptr_of_call->row][maps->ptr_of_call->clm] == 'X')
                    mlx_put_image_to_window (maps->ptr_of_call->mlx , maps->ptr_of_call->mlx_win ,maps->ptr_of_call->img_exit_open,(maps->ptr_of_call->clm * maps->ptr_of_call->a),(maps->ptr_of_call->row * maps->ptr_of_call->a));
                maps->ptr_of_call->clm++;
            }
            // maps->ptr_of_call->row++;
        }
}
