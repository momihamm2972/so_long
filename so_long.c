/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 10:48:34 by momihamm          #+#    #+#             */
/*   Updated: 2023/05/19 23:36:11 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int check_the_dot(char *str)
{
    int indx;
    int ndot;
    
    indx = 0;
    ndot = 0;
    while (str[indx])
    {
        if (str[indx] == '.')
            ndot++;
        if (ndot > 1)
            return (1);
        indx++;
    }
    return (0);
}

void    check_the_of_file(char *str)
{
    int indx;
    int no;

    indx = 0;
    no=0;
    if (str[0] == '.' || check_the_dot(str) == 1)
    {
        print_msg();
        exit(0);
    }
    if (!(ft_strlen (ft_strstr (str, ".ber")) == 4 &&  ft_strlen (str) > 4))
    {
        print_msg();
        exit(0);
    }
    return ;
}

char    **open_and_read_the_file(t_struct_of_maps *i_think_it_is, char *str)
{
    int fd;

    fd = open (str, O_RDONLY);
    if (fd == -1)
        exit(0);
    i_think_it_is->map = ft_of_reding_the_map(fd);
    i_think_it_is->maphya = ft_split (i_think_it_is->map, '\n');
    i_think_it_is->lines = strlines (i_think_it_is->maphya);
    i_think_it_is->newlines = how_many_char_in_the_str (i_think_it_is->map, '\n');
    check_missing_a_newline (i_think_it_is->lines, i_think_it_is->newlines);
    check_is_count_of_lines_is_gr_than_new_lines (i_think_it_is->maphya);
    check_the_walls (i_think_it_is->maphya);
    check_p_e_c (i_think_it_is->maphya);
    check_if_the_map_has_wrong_char (i_think_it_is->maphya);
    i_think_it_is->floodfill_map = ft_split(i_think_it_is->map, '\n');
    flodfill (row_of_p(i_think_it_is->floodfill_map), clm_of_p(i_think_it_is->floodfill_map), i_think_it_is->floodfill_map);
    if (check_the_path(i_think_it_is->floodfill_map) == 1)
    {
        print_msg();
        exit(0);
    }
    return (i_think_it_is->maphya);
}

void    intai_var(t_struct_of_maps *my_struct)
{
    my_struct->p_o_c->img_coll = mlx_xpm_file_to_image (maps->p_o_c->mlx, "./xpm/zd.xpm", &maps->p_o_c->a, &maps->p_o_c->b);
    my_struct->p_o_c->img_exit = mlx_xpm_file_to_image (maps->p_o_c->mlx, "./xpm/k.xpm", &maps->p_o_c->a, &maps->p_o_c->b);
    my_struct->p_o_c->img_wall = mlx_xpm_file_to_image (maps->p_o_c->mlx, "./xpm/w.xpm", &maps->p_o_c->a, &maps->p_o_c->b);
    my_struct->p_o_c->img_ply = mlx_xpm_file_to_image (maps->p_o_c->mlx, "./xpm/c.xpm", &maps->p_o_c->a, &maps->p_o_c->b);
    my_struct->p_o_c->img_exit_open = mlx_xpm_file_to_image (maps->p_o_c->mlx, "./xpm/i.xpm", &maps->p_o_c->a, &maps->p_o_c->b);
}

int main (int ac, char **av)
{
    if (ac == 2)
    {
        check_the_of_file (av[1]);
        t_struct_of_maps    *maps;
        maps =  ft_calloc (1, sizeof (t_struct_of_maps));
        maps->maphya = open_and_read_the_file(maps, av[1]);
        maps->cp_maphya = maps->maphya;
        /*###############################################################MLX PART######################################################################*/
    
        maps->p_o_c = ft_calloc (1,sizeof (t_struct_of_excu));
        int len = (int) ft_strlen(maps->cp_maphya[0]);
        int lin = num_of_lines(maps->cp_maphya);
        maps->p_o_c->a = 64;
        maps->p_o_c->b = 64;
        maps->p_o_c->row = 0;
        maps->p_o_c->count_of_coll = count_of_coll (maps->cp_maphya);
        maps->p_o_c->coll_of_exit = 0;
        maps->p_o_c->moves = 0;
        maps->p_o_c->mlx = mlx_init();
        if (!maps->p_o_c->mlx)
        {
            printf ("wowi\n");
            exit(0);
        }
        maps->p_o_c->mlx_win = mlx_new_window(maps->p_o_c->mlx ,len * 64, lin * 64, "so_long");
        ft_draw(maps);
        mlx_hook (maps->p_o_c->mlx_win, 2, 0, ft_move, maps);
        mlx_hook (maps->p_o_c->mlx_win, 17, 0, &close_red_button, maps->p_o_c);
        /*############################################################################################################################################*/
        mlx_loop(maps->p_o_c->mlx);
        // close (fd);
    }
    else
    {
        write (1, "ONLY ONE ARGUMENT MUST BE TAKEN!!\n", 34);
        exit(0);
    }
}

// int smi(void)
// {
    
// }
