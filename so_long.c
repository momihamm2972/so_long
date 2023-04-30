/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 10:48:34 by momihamm          #+#    #+#             */
/*   Updated: 2023/04/30 21:44:19 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main (int ac, char **av)
{
    //(void) av;
    int m;
    if (ac == 2)
    {
        if (ft_strlen (ft_strstr (av[1], ".ber")) == 4 && ft_strlen (av[1]) > 4)
            m = 0;
        else
        {
            printf ("Eror 404\n");
            return (0);
        }
        int fd = open (av[1], O_RDONLY);
        if (fd == -1)
            return (0);
        t_struct_of_maps    maps;
        maps.lines = 0;
        maps.newlines = 0;
        // maps.first_line = 0;
        // maps.rest_of_lines = 0;
        /*-----------------------------------------------while of reding the map--------------------------------------------*/
        //printf ("hna\n");
        maps.c = get_next_line(fd);
        if (maps.c == NULL)
        {
            printf ("empty\n");
            return (0);
        }
        else
        {
            maps.map = ft_strjoin(maps.map, maps.c);
        }
        while (1)
        {
            maps.c = get_next_line(fd);
            if (maps.c == NULL)
                break;
            maps.map = ft_strjoin(maps.map, maps.c);
        }
        //printf ("mimimimi\n");
        /*------------------------------------------------------------------------------------------------------------------*/
        maps.newlines = how_many_char_in_the_str(maps.map,'\n');
        maps.maphya = ft_split (maps.map, '\n');
        /*-----------------while to know how many char splited by ('\n') and hoany linw mes--------------------------------*/
        while (maps.maphya[maps.lines])
            maps.lines++;
        /*------------------------------------------------------------------------------------------------------------------*/    
        if (maps.lines - maps.newlines != 1)
        {
            printf ("lines>%d\nnewlines>%d\n",maps.lines,maps.newlines);
            printf ("something wrong in the map\n");
            return (0);
        }
        /*-------------------------------while to check is the length of all lines are equal------------------------------*/
        int zero = 0;
        while (maps.maphya[zero++])
        {
            maps.first_line = ft_strlen (maps.maphya[0]);
            if (ft_strlen (maps.maphya[zero]) != maps.first_line && maps.maphya[zero] != NULL)
                return (0);
        }
        /*----------------------------------------------------------------------------------------------------------------*/
        /*----------------------------------------------------check the borders of the map(s9f and lard)------------------------------------------*/
        int row=0;
        while (maps.maphya[row])
        {
            //printf ("%s\n",maps.maphya[row]);
            if (is_thef_and_thel_is_true (maps.maphya[row], '1') == 0)
            {
                printf ("fra3 drssat\n");
                //continue;
            }
            else
            {
                printf ("0-day\n");
                return (0);
            }
            row++;
        }
        if (check_borders(maps.maphya[0], '1') == 0 && check_borders(maps.maphya[row - 1], '1') == 0)
            printf ("all is good\n");
        /*---------------------------------------------------------------------------------------------------------------------------------------*/
        /*------------------------------------------------print the map------------------------------------------*/
        int i=0;
        while (maps.maphya[i])
            printf ("%s\n",maps.maphya[i++]);
        /*-------------------------------------------------------------------------------------------------------*/
    }
    else
    {
        printf ("ONLY ONE ARGUMENT MUST BE TAKEN\n");
        return (0);
    }
}



/*l7awaf mazal mamrigling*/
/**/