# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkhairal <mkhairal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/26 16:20:07 by mkhairal          #+#    #+#              #
#    Updated: 2023/07/01 14:41:34 by mkhairal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

MLX_FLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit

CC = cc
FLAGS = -Wall -Wextra -Werror
RM = rm -f

SRC = ./mandatory/ft_split.c \
	./mandatory/so_long_moves.c \
	./mandatory/so_long_utils.c \
	./mandatory/so_long.c \
	./mandatory/str_utils.c \
	./mandatory/map_checker.c \
	./mandatory/parser_main.c \
	./mandatory/parser_utils.c  \
	./mandatory/get_next_line.c \
	./mandatory/get_next_line_utils.c \
	./mandatory/so_long_init.c \
	./mandatory/so_long_init_assets.c

OBJS = $(SRC:.c=.o)

all: $(NAME)

$(NAME):$(OBJS)
	$(CC) $(CFLAGS) $(MLX_FLAGS) $(OBJS) -o $(NAME)

%.o:%.c so_long.h mandatory/get_next_line.h
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	$(RM) $(OBJS)

fclean:clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all re fclean
