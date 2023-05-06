/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 13:25:51 by momihamm          #+#    #+#             */
/*   Updated: 2023/05/02 19:31:18 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    print_msg(void)
{
    write (1, "somthing wrong in the map\n", 26);
}

int how_many_char_in_the_str(char *str, char c)
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

int check_borders(char *s, char c)
{
    int indx;
    
    indx = 0;
    while (s[indx])
    {
        if (s[indx] != c)
            return (1);
        indx++;
    }
    return (0);
}

int is_thef_and_thel_is_true(char *str, char c)
{
    int lent;
    
    lent = ft_strlen (str) - 1;
    if (str[0] == c && str[lent] == c)
        return (0);
    return (1);
}

int check_IF(char *str, char c)
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

// char    *ft_of_reding_the_map(int fd)
// {
//     //int indx;
//     char *str;
//     char *all;

//     //indx = 0;
//     all = ft_strdup ("");
//     str = (char *) ft_calloc (BUFFER_SIZE + 1, sizeof (char));
//     while (1)
//     {
//         str = get_next_line (fd);
//         if (str == NULL)
//             break ;
//         all = ft_strjoin (all, str);
//         free (str);
//     }
//     return (all);
// }
// void     check_is_count_of_lines_is_gr_than_new_lines(char **str)
// {
//     unsigned int row;
//     unsigned int fristline;
    
//     row = 0;
//     fristline = ft_strlen (str[0]);
//     while (str[row])
//     {
//         if (ft_strlen (str[row]) == fristline && str[row] != NULL)
//             row++;   
//         else
//         {
//             print_msg();
//             exit (0);
//         }
//     } 
// }

// int strlines(char **str)
// {
//     int row;

//     row = 0;
//     while (str[row])
//         row++;
//     return (row);
// }

// void    check_missing_a_newline(int value_a, int value_b)
// {
//    if (value_a - value_b != 1)
//    {
//         print_msg();
//         exit (0);
//    } 
// }

// void    check_the_walls(char **str)
// {
//     int row;

//     row = 0;
//     while (str[row])
//     {
//         if (is_thef_and_thel_is_true(str[row], '1') == 0)
//             row++;
//         else
//         {
//             print_msg ();
//             exit (0);
//         }
//     }
//     if (check_borders(str[0], '1') == 0 && check_borders (str[row - 1], '1') == 0)
//         return ;
//     else
//     {
//         print_msg ();
//         exit (0);
//     }
// } 
