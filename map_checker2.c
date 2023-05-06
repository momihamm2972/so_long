/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 19:30:21 by momihamm          #+#    #+#             */
/*   Updated: 2023/05/03 19:17:57 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int counts (char *str, char c)
{
    int indx;
    int cont;

    indx = 0;
    cont = 0;
    while (str[indx])
    {
        if (str[indx] == c)
            cont++;
        indx++;
    }
    return (cont);
}

int counts_0 (char **str, char c)
{
    int row;
    int cnt;

    row = 0;
    cnt = 0;
    while (str[row])
    {
        cnt += counts (str[row], c);
        row++;
    }
    return (cnt);
}

void    check_P_E_C(char **str)
{
     if (counts_0(str, 'P') != 1)
        {
            printf ("$$$%d\n",counts_0(str, 'P'));
            exit (0);
        }
        if (counts_0(str, 'E') != 1)
        {
            printf ("***%d\n",counts_0(str, 'E'));
            exit (0);
        }
        if (counts_0(str, 'C') < 1)
        {
            printf ("&&&%d\n",counts_0(str, 'C'));
            exit (0);
        }
}

// void    ft_colorbynew(char old_color, char new_color)
// {
//     old_color = new_color;
// }

// void    flood_fill(char **str, int afassil, int arratib, char new_char, char old_char)
// {
//     int lenofstr;
//     int lenofmtx;

//     lenofstr = ft_strlen (str[0]);
//     lenofmtx = strlines (str);
//     if (lenofstr >= afassil || afassil < 0  || arratib < 0 || lenofmtx >= arratib || str[afassil][arratib] == new_char)
//         return ;
//     else
//     {
//         ft_colorbynew (old_char, new_char);
//         flood_fill (str, afassil + 1, arratib, new_char);
//         flood_fill (str, afassil - 1, arratib, new_char);
//         flood_fill (str, afassil, arratib + 1, new_char);
//         flood_fill (str, afassil, arratib - 1, new_char);
//     }
// }
