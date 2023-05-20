/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 10:48:34 by momihamm          #+#    #+#             */
/*   Updated: 2023/05/20 19:42:27 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_the_of_file(char *str)
{
	int	indx;
	int	no;

	indx = 0;
	no = 0;
	if (str[0] == '.' || check_the_dot(str) == 1)
	{
		print_msg();
		exit(0);
	}
	if (!(ft_strlen(ft_strstr(str, ".ber")) == 4 && ft_strlen(str) > 4))
	{
		print_msg();
		exit(0);
	}
	return ;
}

char	**open_file(t_struct_of_maps *i_think_it_is, char *str)
{
	int	fd;

	fd = open (str, O_RDONLY);
	if (fd == -1)
		exit(0);
	i_think_it_is->map = ft_of_reding_the_map(fd);
	i_think_it_is->maphya = ft_split (i_think_it_is->map, '\n');
	i_think_it_is->lines = strlines (i_think_it_is->maphya);
	i_think_it_is->newlines = how_many_char_in_the_str
		(i_think_it_is->map, '\n');
	check_missing_a_newline (i_think_it_is->lines, i_think_it_is->newlines);
	check_is_count_of_lines_is_gr_than_new_lines (i_think_it_is->maphya);
	check_the_walls (i_think_it_is->maphya);
	check_p_e_c (i_think_it_is->maphya);
	check_if_the_map_has_wrong_char (i_think_it_is->maphya);
	i_think_it_is->floodfill_map = ft_split(i_think_it_is->map, '\n');
	flodfill (row_of_p(i_think_it_is->floodfill_map),
		clm_of_p(i_think_it_is->floodfill_map),
		i_think_it_is->floodfill_map);
	if (check_the_path(i_think_it_is->floodfill_map) == 1)
	{
		print_msg();
		exit(0);
	}
	return (i_think_it_is->maphya);
}

void	intai_var(t_struct_of_maps *my_struct)
{
	my_struct->pc->i_c = mlx_xpm_file_to_image(my_struct->pc->mlx,
			"./xpm/zd.xpm", &my_struct->pc->a, &my_struct->pc->b);
	my_struct->pc->i_e = mlx_xpm_file_to_image(my_struct->pc->mlx,
			"./xpm/k.xpm", &my_struct->pc->a, &my_struct->pc->b);
	my_struct->pc->i_w = mlx_xpm_file_to_image(my_struct->pc->mlx,
			"./xpm/w.xpm", &my_struct->pc->a, &my_struct->pc->b);
	my_struct->pc->i_p = mlx_xpm_file_to_image(my_struct->pc->mlx,
			"./xpm/c.xpm", &my_struct->pc->a, &my_struct->pc->b);
	my_struct->pc->i_eo = mlx_xpm_file_to_image(my_struct->pc->mlx,
			"./xpm/i.xpm", &my_struct->pc->a, &my_struct->pc->b);
	if (my_struct->pc->i_c == NULL || my_struct->pc->i_e == NULL
		||my_struct->pc->i_w == NULL || my_struct->pc->i_p == NULL
		|| my_struct->pc->i_eo == NULL)
	{
		msg_xpmfiles();
		exit(0);
	}
}

void	start_mlx(t_struct_of_maps *is_a_stc)
{
	is_a_stc->pc->a = 64;
	is_a_stc->pc->mlx = mlx_init();
	is_a_stc->pc->len = (int) ft_strlen(is_a_stc->cp_maphya[0]);
	is_a_stc->pc->lin = num_of_lines(is_a_stc->cp_maphya);
	is_a_stc->pc->count_of_coll = count_of_coll (is_a_stc->cp_maphya);
	is_a_stc->pc->coll_of_exit = 0;
	is_a_stc->pc->moves = 0;
	if (!is_a_stc->pc->mlx)
	{
		msg_xpmfiles();
		exit(0);
	}
	is_a_stc->pc->x_w = mlx_new_window (is_a_stc->pc->mlx,
			is_a_stc->pc->len * is_a_stc->pc->a,
			is_a_stc->pc->lin * is_a_stc->pc->a, "so_long");
	ft_draw(is_a_stc);
	mlx_hook(is_a_stc->pc->x_w, 2, 0, ft_move, is_a_stc);
	mlx_hook(is_a_stc->pc->x_w, 17, 0, close_red_button, is_a_stc->pc);
	mlx_loop(is_a_stc->pc->mlx);
}

int	main(int ac, char **av)
{
	t_struct_of_maps	*maps;

	if (ac == 2)
	{
		check_the_of_file (av[1]);
		maps = ft_calloc (1, sizeof(t_struct_of_maps));
		maps->maphya = open_file(maps, av[1]);
		maps->cp_maphya = maps->maphya;
		maps->pc = ft_calloc (1, sizeof(t_struct_of_excu));
		start_mlx (maps);
	}
	else
	{
		write (1, "ONLY ONE ARGUMENT MUST BE TAKEN!!\n", 34);
		exit(0);
	}
}
