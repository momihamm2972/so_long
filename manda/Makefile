# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/29 09:54:22 by momihamm          #+#    #+#              #
#    Updated: 2023/05/22 00:19:10 by momihamm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = cc
FLAGS = -Wall -Werror -Wextra
FILES = so_long.c\
		utils.c\
		utils1.c\
		get_next_line_utils.c\
		get_next_line.c\
		map_checker.c\
		map_checker1.c\
		map_checker2.c\
		map_checker3.c\
		excution0.c\
		excution1.c

OBJ = $(FILES:.c=.o)

all : $(NAME)               

%.o : %.c so_long.h
	$(CC) $(FLAGS) -Imlx -c $<

$(NAME) : $(OBJ)
	$(CC) $(FLAGS) $(FILES) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean :
		@rm -rf $(OBJ)

fclean : clean
		@rm -rf $(NAME)

re : fclean all
