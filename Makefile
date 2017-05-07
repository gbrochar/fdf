# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gbrochar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/27 19:26:17 by gbrochar          #+#    #+#              #
#    Updated: 2016/05/09 11:50:29 by gbrochar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC =	srcs/main.c \
		srcs/fdf.c \
		srcs/mlx_draw_line.c \
		srcs/key_hook.c \
		srcs/fdf_parsing.c \
		srcs/get_map.c \
		get_next_line/get_next_line.c \
		libft/libft.a

OBJ =	main.o \
		fdf.o \
		mlx_draw_line.o \
		key_hook.o \
		fdf_parsing.o \
		get_map.o \
		get_next_line.o

CC = gcc

FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	make -C get_next_line/libft
	make -C libft
	$(CC) $(FLAGS) -I./includes/ $(SRC) -o $(NAME) -lmlx -framework \
	AppKit -framework OpenGL

clean:
	make -C get_next_line/libft clean
	make -C libft clean
	rm -f $(OBJ)

fclean: clean
	make -C get_next_line/libft fclean
	make -C libft fclean
	rm -f $(NAME)

re: fclean all
