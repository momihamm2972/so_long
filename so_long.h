/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 13:56:23 by momihamm          #+#    #+#             */
/*   Updated: 2023/05/03 19:17:18 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
/*---------------------------------------------------------structs----------------------------------------------------------*/
typedef struct maps
{
    char *c;
    char *map;
    char *cp_map;
    char **cp_maphya;
    char **maphya;
    unsigned int  newlines;
    unsigned int  lines;
    unsigned int  first_line;
    unsigned int  rest_of_lines;
}   t_struct_of_maps;
/*--------------------------------------------------------------------------------------------------------------------------*/

char    *ft_strstr(char *big, char *little);
unsigned int ft_strlen(const char *s);
char	*get_next_line(int fd);
char	*reading(int fd, char *buff_read);
char	*therestofline(char *str);
int	ft_lenofstr(char *str, char c);
int	isthereanewline(char *str);
char	*ft_strdup(char *s1);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char const *s, unsigned int start, unsigned int len);
void	*ft_calloc(size_t count, size_t size);
void	free_all(char **s, int ptrs);
int	num_of_word(char *s, char c);
char	**ft_split(char const *s, char c);
int how_many_char_in_the_str(char *str, char c);
int check_borders(char *s, char c);
int is_thef_and_thel_is_true(char *str, char c);
int check_IF(char *str, char c);
void    print_msg(void);
char    *ft_of_reding_the_map(int fd);
void    check_is_count_of_lines_is_gr_than_new_lines(char **str);
int strlines(char **str);
void    check_missing_a_newline(int value_a, int value_b);
void    check_the_walls(char **str);
int counts (char *str, char c);
int counts_0 (char **str, char c);
void    check_P_E_C(char **str);
// void    ft_colorbynew(char old_color, char new_color);
// void    flood_fill(char **str, int afassil, int arratib, char new_char, char old_char);

#endif