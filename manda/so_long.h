/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 13:56:23 by momihamm          #+#    #+#             */
/*   Updated: 2023/05/20 22:01:29 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <mlx.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
/*###################################struct###################################*/
typedef struct excu
{
	int		a;
	int		b;
	int		len;
	int		lin;
	int		row;
	int		clm;
	int		count_of_coll;
	int		coll_of_exit;
	int		moves;
	void	*mlx;
	void	*x_w;
	void	*i_p;
	void	*i_w;
	void	*i_c;
	void	*i_e;
	void	*i_eo;
}	t_struct_of_excu;
/*###########################################################################*/
/*-------------------------------structs-------------------------------------*/
typedef struct maps
{
	unsigned int			newlines;
	unsigned int			lines;
	unsigned int			first_line;
	unsigned int			rest_of_lines;
	char					*c;
	char					*map;
	char					*cp_map;
	char					**cp_maphya;
	char					**floodfill_map;
	char					**maphya;
	t_struct_of_excu		*pc;
}	t_struct_of_maps;

/*---------------------------------------------------------------------*/

int				ft_lenofstr(char *str, char c);
int				isthereanewline(char *str);
int				num_of_word(char *s, char c);
int				how_many_char_in_the_str(char *str, char c);
int				check_borders(char *s, char c);
int				is_thef_and_thel_is_true(char *str, char c);
int				check_if(char *str, char c);
int				counts(char *str, char c);
int				counts_zero(char **str, char c);
int				close_red_button(void);
int				ft_move(int key_hook, t_struct_of_maps *structt);
int				count_of_coll(char **arr);
int				check_is_thepath_is_v(char **arr);
int				flodfill(int i, int j, char **arr);
int				num_of_lines(char **arr);
int				clm_of_p(char **map);
int				row_of_p(char **map);
int				check_the_path(char **arr);
int				check_the_dot(char *str);
int				strlines(char **str);
unsigned int	ft_strlen(const char *s);
char			*ft_strstr(char *big, char *little);
char			*get_next_line(int fd);
char			*reading(int fd, char *buff_read);
char			*therestofline(char *str);
char			*ft_strdup(char *s1);
char			*ft_strjoin(char *s1, char *s2);
char			**ft_split(char const *s, char c);
char			*ft_of_reding_the_map(int fd);
char			*ft_substr(char const *s, unsigned int start, unsigned int len);
char			**open_file(t_struct_of_maps *i_think_it_is, char *str);
void			*ft_calloc(size_t count, size_t size);
void			free_all(char **s, int ptrs);
void			print_msg(void);
void			check_is_count_of_lines_is_gr_than_new_lines(char **str);
void			check_missing_a_newline(int value_a, int value_b);
void			check_the_walls(char **str);
void			check_p_e_c(char **str);
void			plyer(char **map, int parm, t_struct_of_maps *structt);
void			plyer_to_down(char **map);
void			swap(int row, int indx, char **map, t_struct_of_maps *structt);
void			swad(int row, int indx, char **map, t_struct_of_maps *structt);
void			swal(int row, int indx, char **map, t_struct_of_maps *structt);
void			swar(int row, int indx, char **map, t_struct_of_maps *structt);
void			ft_draw(t_struct_of_maps *structt);
void			check_if_the_map_has_wrong_char(char **map);
void			ft_draw_exit(t_struct_of_maps *maps);
void			ft_putchar(char c);
void			ft_putnbr(int nb);
void			check_the_of_file(char *str);
void			intai_var(t_struct_of_maps *my_struct);
void			msg_xpmfiles(void);
void			start_mlx(t_struct_of_maps *is_a_stc);

#endif
