# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkhairal <mkhairal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/02 09:30:47 by mkhairal          #+#    #+#              #
#    Updated: 2023/07/15 19:35:29 by mkhairal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAME_BONUS = checker

CC = cc
CFLAGS = -Wall -Werror -Wextra -g #-fsanitize=address -g
RM = rm -f

SRC = push_swap_main.c \
	./utils/convert.c \
	./utils/linked_list.c \
	./utils/linked_list2.c \
	./utils/init.c \
	./utils/parser.c \
	./utils/parser2.c \
	./utils/instructions.c \
	./utils/instructions2.c \
	./utils/instructions3.c \
	./utils/instructions4.c \
	./utils/bucket_sort.c \
	./utils/bucket_sort2.c \
	./utils/bucket_sort3.c \
	./helper_functions/ft_atoi.c \
	./helper_functions/ft_putstr.c \
	./helper_functions/ft_split.c \
	./helper_functions/ft_abs.c \
	./helper_functions/ft_strjoin.c \
	./helper_functions/ft_strcmp.c \
	./helper_functions/ft_strdup.c \
	./helper_functions/ft_strlen.c \

SRC_BONUS = ./bonus/checker.c \
	./bonus/checker_convert.c \
	./bonus/checker_linked_list.c \
	./bonus/checker_linked_list2.c \
	./bonus/checker_init.c \
	./bonus/checker_parser.c \
	./bonus/checker_parser2.c \
	./bonus/checker_instructions.c \
	./bonus/checker_instructions2.c \
	./bonus/checker_instructions3.c \
	./bonus/checker_instructions4.c \
	./bonus/ft_atoi.c \
	./bonus/ft_putnbr.c \
	./bonus/ft_putstr.c \
	./bonus/ft_split.c \
	./bonus/ft_strjoin.c \
	./bonus/ft_strcmp.c \
	./bonus/ft_strdup.c \
	./bonus/ft_strlen.c \
	./bonus/get_next_line.c \
	./bonus/get_next_line_utils.c \
	./bonus/checker_utils.c \

OBJS = $(SRC:.c=.o)
BONUS_OBJS = $(SRC_BONUS:.c=.o)

all:$(NAME)

$(NAME):$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o:%.c push_swap.h push_swap_bonus.h
	$(CC) -c $(CFLAGS) $< -o $@

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(BONUS_OBJS) -o $(NAME_BONUS)

clean:
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean:clean
	$(RM) $(NAME) $(NAME_BONUS)

re:fclean all

.PHONY: re all clean fclean bonus
