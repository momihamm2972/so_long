/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 10:48:34 by momihamm          #+#    #+#             */
/*   Updated: 2023/05/19 00:34:12 by momihamm         ###   ########.fr       */
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
        // system("leaks so_long");
        maps->map = ft_of_reding_the_map(fd);
        // maps->cp_map = maps->map;
        //printf ("$$%s$$\n",maps->cp_map);
        /*------------------------------------------------------------------------------------------------------------------*/
        maps->newlines = how_many_char_in_the_str(maps->map,'\n');
        maps->maphya = ft_split (maps->map, '\n');
        // free(maps->map);
        maps->floodfill_map = ft_split(maps->map, '\n');
        int i=0;
        while (maps->floodfill_map[i])
            printf ("%s\n",maps->floodfill_map[i++]);
        int m= row_of_p(maps->floodfill_map);
        int n= clm_of_p(maps->floodfill_map);
        printf ("9abl\n");
        flodfill(m,n,maps->floodfill_map);
        printf ("ba3ed\n");
        i=0;
        while (maps->floodfill_map[i])
            printf ("%s\n",maps->floodfill_map[i++]);
        if (check_the_path(maps->floodfill_map) == 1)
        {
            printf ("jabou f lkass\n");
            exit(0);
        }
        // if (flodfill (0,0, maps->floodfill_map) != 0)
        //     printf ("kmi o tkma\n");
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
        check_p_e_c(maps->maphya);
        check_if_the_map_has_wrong_char(maps->maphya);
        // maps->ptr_of_call->count_of_coll = 0;        
        // printf ("%d",maps->ptr_of_call->count_of_coll);
        /*-----------------------------------------------------------------------------------------------------------------------------------*/
        /*##############################################foold fill algo##################################################################*/
        
        /*###############################################################################################################################*/
        /*------------------------------------------------print the map------------------------------------------*/
        // int i=0;
        // while (maps->cp_maphya[i])
        //     printf ("%s\n",maps->cp_maphya[i++]);
        /*-------------------------------------------------------------------------------------------------------*/
        /*###############################################################MLX PART######################################################################*/
    
        maps->ptr_of_call = ft_calloc (1,sizeof (t_struct_of_excu));
        int len = (int) ft_strlen(maps->cp_maphya[0]);
        int lin = num_of_lines(maps->cp_maphya);
        maps->ptr_of_call->a = 64;
        maps->ptr_of_call->b = 64;
        maps->ptr_of_call->row = 0;
        maps->ptr_of_call->count_of_coll = count_of_coll (maps->cp_maphya);
        maps->ptr_of_call->coll_of_exit = 0;
        maps->ptr_of_call->moves = 0;
        maps->ptr_of_call->mlx = mlx_init();
        maps->ptr_of_call->mlx_win = mlx_new_window(maps->ptr_of_call->mlx ,len * 64, lin * 64, "lo3ba");
        // maps->ptr_of_call->img_ply = mlx_xpm_file_to_image(maps->ptr_of_call->mlx, "./xpmfiles/god_of_war.xpm", &maps->ptr_of_call->a, &maps->ptr_of_call->b);
        ft_draw(maps);
        mlx_hook (maps->ptr_of_call->mlx_win, 2, 0, ft_move, maps);
        mlx_hook (maps->ptr_of_call->mlx_win, 17, 0, &close_red_button, maps->ptr_of_call);
        /*############################################################################################################################################*/
        mlx_loop(maps->ptr_of_call->mlx);
        close (fd);
        free(maps->ptr_of_call);
        free(maps);
    }
    else
    {
        printf ("ONLY ONE ARGUMENT MUST BE TAKEN\n");
        return (0);
    }
}

