/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   excution1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:57:13 by momihamm          #+#    #+#             */
/*   Updated: 2023/05/12 20:52:43 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    ft_draw(t_struct_of_maps *maps)
{
    // int row;

    // row = 0;
    maps->ptr_of_call->row = 0;
    // printf("HERE IM DRAWING \n");
while (maps->cp_maphya[maps->ptr_of_call->row])
        {
            // printf("IAM HEREEREREER$$%s\n",maps->cp_maphya[maps->ptr_of_call->row]);
            maps->ptr_of_call->clm = 0;
            while (maps->cp_maphya[maps->ptr_of_call->row][maps->ptr_of_call->clm])
            {
                if (maps->cp_maphya[maps->ptr_of_call->row][maps->ptr_of_call->clm] == '1')
                {
                    maps->ptr_of_call->img_ply = mlx_xpm_file_to_image(maps->ptr_of_call->mlx, "./xpmfiles/god_of_war.xpm", &maps->ptr_of_call->a, &maps->ptr_of_call->b);
                    mlx_put_image_to_window (maps->ptr_of_call->mlx , maps->ptr_of_call->mlx_win ,maps->ptr_of_call->img_ply,(maps->ptr_of_call->clm * maps->ptr_of_call->a),(maps->ptr_of_call->row * maps->ptr_of_call->a));
                }
                if (maps->cp_maphya[maps->ptr_of_call->row][maps->ptr_of_call->clm] == 'C')
                {
                    maps->ptr_of_call->img_ply = mlx_xpm_file_to_image (maps->ptr_of_call->mlx, "./xpmfiles/AnyConv.com__mamaresized.xpm", &maps->ptr_of_call->a ,&maps->ptr_of_call->b);
                    mlx_put_image_to_window (maps->ptr_of_call->mlx , maps->ptr_of_call->mlx_win ,maps->ptr_of_call->img_ply,(maps->ptr_of_call->clm * maps->ptr_of_call->a),(maps->ptr_of_call->row * maps->ptr_of_call->a));
                }
                if (maps->cp_maphya[maps->ptr_of_call->row][maps->ptr_of_call->clm] == 'E')
                {
                    maps->ptr_of_call->img_ply = mlx_xpm_file_to_image (maps->ptr_of_call->mlx, "./xpmfiles/AnyConv.com__lock.xpm", &maps->ptr_of_call->a ,&maps->ptr_of_call->b);
                    mlx_put_image_to_window (maps->ptr_of_call->mlx , maps->ptr_of_call->mlx_win ,maps->ptr_of_call->img_ply,(maps->ptr_of_call->clm * maps->ptr_of_call->a),(maps->ptr_of_call->row * maps->ptr_of_call->a));
                }
                if (maps->cp_maphya[maps->ptr_of_call->row][maps->ptr_of_call->clm] == 'P')
                {
                    maps->ptr_of_call->img_ply = mlx_xpm_file_to_image (maps->ptr_of_call->mlx, "./xpmfiles/__char00012 (1).xpm", &maps->ptr_of_call->a ,&maps->ptr_of_call->b);
                    mlx_put_image_to_window (maps->ptr_of_call->mlx , maps->ptr_of_call->mlx_win ,maps->ptr_of_call->img_ply,(maps->ptr_of_call->clm * maps->ptr_of_call->a),(maps->ptr_of_call->row * maps->ptr_of_call->a));
                }
                maps->ptr_of_call->clm++;
            }
            // mlx_hook (maps->ptr_of_call->mlx_win, 2, 0, &ft_move, maps);
            maps->ptr_of_call->row++;
        }
    // printf("HERE finishded DRAWING \n");
}