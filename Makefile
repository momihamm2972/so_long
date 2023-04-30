# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/29 09:54:22 by momihamm          #+#    #+#              #
#    Updated: 2023/04/30 15:48:26 by momihamm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = cc
FLAGS = -Wall -Werror -Wextra -g
FILES = so_long.c\
		utils.c\
		get_next_line_utils.c\
		get_next_line.c\
		map_checker.c

OBJ = $(FILES:.c=.o)

all : $(NAME)               

%.o : %.c so_long.h
	$(CC) $(FLAGS) -c $<

$(NAME) : $(OBJ)
	$(CC) $(FLAGS) $(FILES) -o $(NAME)

clean :
		@rm -f $(OBJ)

fclean :
		@rm -f $(NAME)

re : fclean all