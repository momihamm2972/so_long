/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 10:48:34 by momihamm          #+#    #+#             */
/*   Updated: 2023/05/12 19:43:17 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main (int ac, char **av)
{
    int m;
    if (ac == 2)
    {
        if (ft_strlen (ft_strstr (av[1], ".ber")) == 4 && ft_strlen (av[1]) > 4)
            m = 0;
        else
        {
            print_msg();
            return (0);
        }
        int fd = open (av[1], O_RDONLY);
        if (fd == -1)
            return (0);
        t_struct_of_maps    *maps;
        maps =  ft_calloc (1, sizeof (t_struct_of_maps));
        maps->lines = 0;
        maps->newlines = 0;
        /*-----------------------------------------------while of reding the map--------------------------------------------*/
        maps->map = ft_of_reding_the_map(fd);
        maps->cp_map = maps->map;
        //printf ("$$%s$$\n",maps->cp_map);
        /*------------------------------------------------------------------------------------------------------------------*/
        maps->newlines = how_many_char_in_the_str(maps->map,'\n');
        maps->maphya = ft_split (maps->map, '\n');
        maps->cp_maphya = maps->maphya;
        /*-----------------while to know how many char splited by ('\n') and hoany linw mes--------------------------------*/
        maps->lines = strlines (maps->maphya);
        check_missing_a_newline(maps->lines, maps->newlines);
        check_is_count_of_lines_is_gr_than_new_lines(maps->maphya);
        //printf ("hna4\n");
        /*----------------------------------------------------------------------------------------------------------------*/
        /*----------------------------------------------------check the borders of the map(s9f and lard)------------------------------------------*/
        check_the_walls (maps->maphya);
        /*---------------------------------------------------------------------------------------------------------------------------------------*/
        /*---------------------------------------------check how many PLAYRS in the map------------------------------------------------------*/
        check_P_E_C(maps->maphya);
        /*-----------------------------------------------------------------------------------------------------------------------------------*/
        /*##############################################foold fill algo##################################################################*/
        
        /*###############################################################################################################################*/
        /*------------------------------------------------print the map------------------------------------------*/
        // int i=0;
        // while (maps.maphya[i])
        //     printf ("%s\n",maps.maphya[i++]);
        /*-------------------------------------------------------------------------------------------------------*/
        /*###############################################################MLX PART######################################################################*/
        // void *mlx;
        // int a = 64;
        // int b = 64;
        // mlx = mlx_init();
        // void *mlx_win = mlx_new_window(mlx, 1919, 1404, "lo3ba");
        // void *img_god = mlx_xpm_file_to_image(mlx, "./xpmfiles/god_of_war.xpm", &a, &b);
        // int row=0;
        // int clm=0;
        // t_struct_of_excu    *excu;
        maps->ptr_of_call = ft_calloc (1,sizeof (t_struct_of_excu));
        maps->ptr_of_call->a = 64;
        maps->ptr_of_call->b = 64;
        maps->ptr_of_call->row = 0;
        maps->ptr_of_call->mlx = mlx_init();
        maps->ptr_of_call->mlx_win = mlx_new_window(maps->ptr_of_call->mlx ,1919, 1404, "lo3ba");
        // maps->ptr_of_call->img_ply = mlx_xpm_file_to_image(maps->ptr_of_call->mlx, "./xpmfiles/god_of_war.xpm", &maps->ptr_of_call->a, &maps->ptr_of_call->b);
        mlx_hook (maps->ptr_of_call->mlx_win, 17, 0, &close_red_button, maps->ptr_of_call);
        // printf ("$$$$$$%d",j); 
        // while (maps->cp_maphya[maps->ptr_of_call->row])
        // {
        //     maps->ptr_of_call->clm = 0;
        //     while (maps->cp_maphya[maps->ptr_of_call->row][maps->ptr_of_call->clm])
        //     {
        //         if (maps->cp_maphya[maps->ptr_of_call->row][maps->ptr_of_call->clm] == '1')
        //         {
        //             maps->ptr_of_call->img_ply = mlx_xpm_file_to_image(maps->ptr_of_call->mlx, "./xpmfiles/god_of_war.xpm", &maps->ptr_of_call->a, &maps->ptr_of_call->b);
        //             mlx_put_image_to_window (maps->ptr_of_call->mlx , maps->ptr_of_call->mlx_win ,maps->ptr_of_call->img_ply,(maps->ptr_of_call->clm * maps->ptr_of_call->a),(maps->ptr_of_call->row * maps->ptr_of_call->a));
        //         }
        //         if (maps->cp_maphya[maps->ptr_of_call->row][maps->ptr_of_call->clm] == 'C')
        //         {
        //             maps->ptr_of_call->img_ply = mlx_xpm_file_to_image (maps->ptr_of_call->mlx, "./xpmfiles/AnyConv.com__mamaresized.xpm", &maps->ptr_of_call->a ,&maps->ptr_of_call->b);
        //             mlx_put_image_to_window (maps->ptr_of_call->mlx , maps->ptr_of_call->mlx_win ,maps->ptr_of_call->img_ply,(maps->ptr_of_call->clm * maps->ptr_of_call->a),(maps->ptr_of_call->row * maps->ptr_of_call->a));
        //         }
        //         if (maps->cp_maphya[maps->ptr_of_call->row][maps->ptr_of_call->clm] == 'E')
        //         {
        //             maps->ptr_of_call->img_ply = mlx_xpm_file_to_image (maps->ptr_of_call->mlx, "./xpmfiles/AnyConv.com__lock.xpm", &maps->ptr_of_call->a ,&maps->ptr_of_call->b);
        //             mlx_put_image_to_window (maps->ptr_of_call->mlx , maps->ptr_of_call->mlx_win ,maps->ptr_of_call->img_ply,(maps->ptr_of_call->clm * maps->ptr_of_call->a),(maps->ptr_of_call->row * maps->ptr_of_call->a));
        //         }
        //         if (maps->cp_maphya[maps->ptr_of_call->row][maps->ptr_of_call->clm] == 'P')
        //         {
        //             maps->ptr_of_call->img_ply = mlx_xpm_file_to_image (maps->ptr_of_call->mlx, "./xpmfiles/__char00012 (1).xpm", &maps->ptr_of_call->a ,&maps->ptr_of_call->b);
        //             mlx_put_image_to_window (maps->ptr_of_call->mlx , maps->ptr_of_call->mlx_win ,maps->ptr_of_call->img_ply,(maps->ptr_of_call->clm * maps->ptr_of_call->a),(maps->ptr_of_call->row * maps->ptr_of_call->a));
        //         }
                
        //         maps->ptr_of_call->clm++;
        //     }
        //     mlx_hook (maps->ptr_of_call->mlx_win, 2, 0, ft_move, maps);
        //     maps->ptr_of_call->row++;
        // }
        ft_draw(maps);
        mlx_hook (maps->ptr_of_call->mlx_win, 2, 0, ft_move, maps);
        // maps->ptr_of_call->row =0;
        // maps->ptr_of_call->clm =0;
        // while (maps->cp_maphya[maps->ptr_of_call->row])
        // {
        //     maps->ptr_of_call->clm = 0;
        //     while (maps->cp_maphya[maps->ptr_of_call->row][maps->ptr_of_call->clm])
        //     {
        //         if (maps->cp_maphya[maps->ptr_of_call->row][maps->ptr_of_call->clm] == '1')
        //         {
        //             maps->ptr_of_call->img_ply = mlx_xpm_file_to_image(maps->ptr_of_call->mlx, "./xpmfiles/god_of_war.xpm", &maps->ptr_of_call->a, &maps->ptr_of_call->b);
        //             mlx_put_image_to_window (maps->ptr_of_call->mlx , maps->ptr_of_call->mlx_win ,maps->ptr_of_call->img_ply,(maps->ptr_of_call->clm * maps->ptr_of_call->a),(maps->ptr_of_call->row * maps->ptr_of_call->a));
        //             printf ("00000\n");
        //         }
        //         if (maps->cp_maphya[maps->ptr_of_call->row][maps->ptr_of_call->clm] == 'C')
        //         {
        //             maps->ptr_of_call->img_ply = mlx_xpm_file_to_image (maps->ptr_of_call->mlx, "./xpmfiles/AnyConv.com__mamaresized.xpm", &maps->ptr_of_call->a ,&maps->ptr_of_call->b);
        //             mlx_put_image_to_window (maps->ptr_of_call->mlx , maps->ptr_of_call->mlx_win ,maps->ptr_of_call->img_ply,(maps->ptr_of_call->clm * maps->ptr_of_call->a),(maps->ptr_of_call->row * maps->ptr_of_call->a));
        //             printf ("11111\n");
        //         }
        //         if (maps->cp_maphya[maps->ptr_of_call->row][maps->ptr_of_call->clm] == 'E')
        //         {
        //             maps->ptr_of_call->img_ply = mlx_xpm_file_to_image (maps->ptr_of_call->mlx, "./xpmfiles/AnyConv.com__lock.xpm", &maps->ptr_of_call->a ,&maps->ptr_of_call->b);
        //             mlx_put_image_to_window (maps->ptr_of_call->mlx , maps->ptr_of_call->mlx_win ,maps->ptr_of_call->img_ply,(maps->ptr_of_call->clm * maps->ptr_of_call->a),(maps->ptr_of_call->row * maps->ptr_of_call->a));
        //             printf ("22222\n");
        //         }
        //         if (maps->cp_maphya[maps->ptr_of_call->row][maps->ptr_of_call->clm] == 'P')
        //         {
        //             maps->ptr_of_call->img_ply = mlx_xpm_file_to_image (maps->ptr_of_call->mlx, "./xpmfiles/__char00012 (1).xpm", &maps->ptr_of_call->a ,&maps->ptr_of_call->b);
        //             mlx_put_image_to_window (maps->ptr_of_call->mlx , maps->ptr_of_call->mlx_win ,maps->ptr_of_call->img_ply,(maps->ptr_of_call->clm * maps->ptr_of_call->a),(maps->ptr_of_call->row * maps->ptr_of_call->a));
        //             printf ("33333\n");
        //         }
        //         maps->ptr_of_call->clm++;
        //     }
        //     mlx_hook (maps->ptr_of_call->mlx_win, 2, 0, ft_move, maps);
        //     maps->ptr_of_call->row++;
        // }
        // ft_draw(maps);
        // mlx_put_image_to_window(mlx, mlx_win, img_god, 0, 0);
        // mlx_put_image_to_window(mlx, mlx_win, img_god, 64, 0);
        // mlx_put_image_to_window(mlx, mlx_win, img_god, 128, 0);
        // mlx_put_image_to_window(mlx, mlx_win, img_god, 192, 0);
        // mlx_put_image_to_window(mlx, mlx_win, img_god, 256, 0);
        // mlx_put_image_to_window(mlx, mlx_win, img_god, 320, 0);
        // mlx_put_image_to_window(mlx, mlx_win, img_god, 384, 0);


        /*############################################################################################################################################*/
        mlx_loop(maps->ptr_of_call->mlx);
    }
    else
    {
        printf ("ONLY ONE ARGUMENT MUST BE TAKEN\n");
        return (0);
    }
}

