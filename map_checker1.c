/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 19:30:12 by momihamm          #+#    #+#             */
/*   Updated: 2023/05/14 23:06:18 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char    *ft_of_reding_the_map(int fd)
{
    //int indx;
    char *str;
    char *all;

    all = ft_strdup ("");
    while (1)
    {
        str = get_next_line (fd);
        if (str == NULL)
            break ;
        all = ft_strjoin (all, str);
        free (str);
    }
    return (all);
}
void     check_is_count_of_lines_is_gr_than_new_lines(char **str)
{
    unsigned int row;
    unsigned int fristline;
    
    row = 0;
    fristline = ft_strlen (str[0]);
    while (str[row])
    {
        if (ft_strlen (str[row]) == fristline && str[row] != NULL)
            row++;   
        else
        {
            print_msg();
            exit (0);
        }
    } 
}

int strlines(char **str)
{
    int row;

    row = 0;
    while (str[row])
        row++;
    return (row);
}

void    check_missing_a_newline(int value_a, int value_b)
{
   if (value_a - value_b != 1)
   {
        print_msg();
        exit (0);
   } 
}

void    check_the_walls(char **str)
{
    int row;

    row = 0;
    while (str[row])
    {
        if (is_thef_and_thel_is_true(str[row], '1') == 0)
            row++;
        else
        {
            print_msg ();
            exit (0);
        }
    }
    if (check_borders(str[0], '1') == 0 && check_borders (str[row - 1], '1') == 0)
        return ;
    else
    {
        print_msg ();
        exit (0);
    }
} 
