# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkhairal <mkhairal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/28 16:05:44 by mkhairal          #+#    #+#              #
#    Updated: 2023/08/06 15:13:47 by mkhairal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
NAME_BONUS = philo_bonus

CC = cc
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror -g -fsanitize=thread

SRC = 	philo_main.c \
		philo_routine.c \
		philo_utils.c \
		threads_mutexes_handler.c

OBJS = $(SRC:%.c=%.o)

all: $(NAME)

%.o: %.c philosophers.h
	$(CC) $(CFLAGS) -c $<

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean:
	$(RM) $(OBJS) $(NAME)

re: fclean all

.PHONY: all re clean fclean
