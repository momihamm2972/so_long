/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   excution0.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 16:54:16 by momihamm          #+#    #+#             */
/*   Updated: 2023/05/13 23:28:02 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int close_red_button()
{
    exit (0);
}

void swap(int row, int indx, char **map)
{
    if (map[row - 1][indx] == '0')
    {
        map[row - 1][indx] = 'P';
        map[row][indx] = '0';
    }
    if (map[row -1][indx] == 'C')
    {
        map[row - 1][indx] = 'P';
        map[row][indx] = '0';
    }
}

void swap_dwn(int row, int indx, char **map)
{
    if (map[row + 1][indx] == '0' || map[row + 1][indx] == 'C')
    {
        map[row + 1][indx] = 'P';
        map[row][indx] = '0';
    }
}

void swap_rh(int row, int indx, char **map)
{
     if (map[row][indx + 1] == '0' || map[row][indx + 1] == 'C')
    {
        map[row][indx + 1] = 'P';
        map[row][indx] = '0';
    }
}

void swap_lf(int row, int indx, char **map)
{
     if (map[row][indx - 1] == '0' || map[row][indx - 1] == 'C')
    {
        map[row][indx - 1] = 'P';
        map[row][indx] = '0';
    }
}

void plyer(char **map, int parm)
{
    int indx;
    int row;
    row = -1;

    while (map[++row])
    {
        indx = -1;
        while (map[row][++indx])
        {
            if (map[row][indx] == 'P' && parm == 0)
            swap (row, indx, map);
            else if (map[row][indx] == 'P' && parm == 1)
            {
                swap_dwn(row, indx, map);
                return ;
            }
            else if (map[row][indx] == 'P' && parm == 2)
            {
                swap_rh(row, indx, map);
                return ;
            }
            else if (map[row][indx] == 'P' && parm == 3)
                swap_lf (row, indx, map);
        }
    }
}

int ft_move(int key_hook, t_struct_of_maps *structt)
{
    if (key_hook == 53)
        close_red_button();
    else if (key_hook == 126 || key_hook == 13)
        plyer(structt->maphya,0);
    else if (key_hook == 125 || key_hook == 1)
        plyer(structt->maphya,1);
    else if (key_hook == 124 || key_hook == 2)
        plyer(structt->maphya, 2);
    else if (key_hook == 123 || key_hook == 0)
        plyer(structt->maphya,3);
    mlx_clear_window(structt->ptr_of_call->mlx, structt->ptr_of_call->mlx_win );
    mlx_destroy_image (structt->ptr_of_call->mlx,structt->ptr_of_call->img_ply);
    mlx_destroy_image (structt->ptr_of_call->mlx,structt->ptr_of_call->img_coll);
    mlx_destroy_image (structt->ptr_of_call->mlx,structt->ptr_of_call->img_wall);
    mlx_destroy_image (structt->ptr_of_call->mlx,structt->ptr_of_call->img_exit);
    ft_draw(structt);
    return (0);
}