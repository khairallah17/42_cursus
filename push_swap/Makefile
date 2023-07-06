# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkhairal <mkhairal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/02 09:30:47 by mkhairal          #+#    #+#              #
#    Updated: 2023/07/06 22:51:32 by mkhairal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
CFLAGS = -Wall -Werror -Wextra -g -fsanitize=address
RM = rm -f

SRC = push_swap_main.c \
	./utils/convert.c \
	./utils/linked_list.c \
	./utils/init.c \
	./utils/parser.c \
	./utils/instructions.c \
	./helper_functions/ft_atoi.c \
	./helper_functions/ft_putnbr.c \
	./helper_functions/ft_putstr.c \
	./helper_functions/ft_split.c 

OBJS = $(SRC:.c=.o)

all:$(NAME)

$(NAME):$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o:%.c push_swap.h
	$(CC) -c $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean:clean
	$(RM) $(NAME)

re:fclean all

.PHONY: re all clean fclean bonus
