/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 21:14:56 by momihamm          #+#    #+#             */
/*   Updated: 2023/05/05 12:02:52 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
 #include "so_long.h"

// int rows_of_matrix (char **str)
// {
//     int row;

//     row = 0;
//     while (str[row])
//         row++;
//     return (row);
// }

void  flood_fill(char **str)
{
  int row =0;
  int indx=0;
  while (str[row])
  {
    indx =0;
    while (str[row][indx])
    {
      if (str[row][indx] == 'C' || str[row][indx] == '0')
        str[row][indx] = 'P';
    }
  }
}

int main ()
{
  char be_map[]= "1111111111\n100P00C001\n100000C001\n100000C001\n100000C001\n1000000001\n100C000001\n1C00000001\n10000000C1\n1000000E01\n1111111111";
  char **map = ft_split (be_map, '\n');
  char **flood = ft_split(be_map, '\n');
  int i= 0;
  while (map[i])
  {
    printf ("%s\n",map[i]);
    i++;
  }
  printf ("#######################\n");
  i =0;
  while (flood[i])
  {
    printf ("%s\n",flood[i]);
    i++;
  }
}