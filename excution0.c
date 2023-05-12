/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   excution0.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 16:54:16 by momihamm          #+#    #+#             */
/*   Updated: 2023/05/12 21:39:50 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// int swip_up(int row)
// {
//     return (row - 1);
// }

int close_red_button()
{
    // void (param);
    exit (0);
}

// int key_press(int key, void *param)
// {
//     if (key == 126)
//         swip_up(param);   
// }

void swap(int row, int indx, char **map)
{
    //char c;

    if (map[row - 1][indx] == '0')
    {
        map[row - 1][indx] = 'P';
        map[row][indx] = '0';
    }
    // int i=0;
    // while (map[i])
    //     printf ("%s\n",map[i++]);
}

void swap_dwn(int row, int indx, char **map)
{
    //char c;

    if (map[row + 1][indx] == '0')
    {
        map[row + 1][indx] = 'P';
        map[row][indx] = '0';
    }
    // int i=0;
    // while (map[i])
    //     printf ("%s\n",map[i++]);
}

void swap_rh(int row, int indx, char **map)
{
     if (map[row][indx + 1] == '0')
    {
        map[row][indx + 1] = 'P';
        map[row][indx] = '0';
    }
}

void swap_lf(int row, int indx, char **map)
{
     if (map[row][indx - 1] == '0')
    {
        map[row][indx - 1] = 'P';
        map[row][indx] = '0';
    }
}

void plyer(char **map, int parm)
{
    int indx;
    int row;
    row = 0;
    // printf ("$$$");
    // printf ("%s$$\n",map[0]);
    while (map[row])
    {
        indx = 0;
        while (map[row][indx])
        {
            if (map[row][indx] == 'P' && parm == 0)
                swap (row, indx, map);
            else if (map[row][indx] == 'P' && parm == 1)
                swap_dwn(row, indx, map);
            else if (map[row][indx] == 'P' && parm == 2)
                swap_rh(row, indx, map);
            else
                swap_lf (row, indx, map);
            indx++;
        }
        row++;
    }
    // return (0);
}

void plyer_to_down(char **map)
{
    int indx;
    int row;
    row = 0;
    // printf ("$$$");
    // printf ("%s$$\n",map[0]);
    while (map[row])
    {
        indx = 0;
        while (map[row][indx])
        {
            if (map[row][indx] == 'P')
                swap_dwn (row, indx, map);
            indx++;
        }
        row++;
    }
    // return (0);
}

int ft_move(int key_hook, t_struct_of_maps *structt)
{
    // int affasil;
    // int arratib;
    if (key_hook == 53)
    {
        // afassil =-1;
        close_red_button();
        // return (afassil);
    }
    else if (key_hook == 126 || key_hook == 13)
    {
        // printf ("afklssd\n");
        plyer(structt->maphya,0);
    }
    else if (key_hook == 125 || key_hook == 1)
    {
        plyer(structt->maphya,1);
    }
    else if (key_hook == 123 || key_hook == 0)
    {
        plyer(structt->maphya,2);
    }
    else if (key_hook == 124 || key_hook == 2)
    {
        plyer(structt->maphya, 3);
    }
    mlx_clear_window(structt->ptr_of_call->mlx, structt->ptr_of_call->mlx_win );
    ft_draw(structt);
        // int i=0;
        // while (structt->maphya[i])
        //     printf ("%s\n",structt->maphya[i++]);
    
    // printf ("wiwi\n");
    // printf ("mimi\n");
    return (0);
}