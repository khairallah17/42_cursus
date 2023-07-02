# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkhairal <mkhairal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/31 11:47:03 by mkhairal          #+#    #+#              #
#    Updated: 2023/05/31 22:19:09 by mkhairal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER_NAME = server
CLIENT_NAME = client
SERVER_BONUS_NAME = server_bonus
CLIENT_BONUS_NAME = client_bonus

SERVER_SRC = server.c minitalk_utils.c
CLIENT_SRC = client.c minitalk_utils.c
SERVER_BONUS_SRC = server_bonus.c minitalk_utils.c
CLIENT_BONUS_SRC = client_bonus.c minitalk_utils.c

CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

SERVER_OBJ = $(SERVER_SRC:%.c=%.o)
CLIENT_OBJ = $(CLIENT_SRC:%.c=%.o)
SERVER_BONUS_OBJ = $(SERVER_BONUS_SRC:%.c=%.o)
CLIENT_BONUS_OBJ = $(CLIENT_BONUS_SRC:%.c=%.o)

all: $(SERVER_NAME) $(CLIENT_NAME)

%.o: %.c minitalk.h
	$(CC) $(CFLAGS) -c $<

$(SERVER_NAME): $(SERVER_OBJ)
	$(CC) $(FLAGS) $(SERVER_OBJ) -o $(SERVER_NAME)

$(CLIENT_NAME): $(CLIENT_OBJ)
	$(CC) $(FLAGS) $(CLIENT_OBJ) -o $(CLIENT_NAME)

$(SERVER_BONUS_NAME): $(SERVER_BONUS_OBJ)
	$(CC) $(FLAGS) $(SERVER_BONUS_OBJ) -o $(SERVER_BONUS_NAME)

$(CLIENT_BONUS_NAME): $(CLIENT_BONUS_OBJ)
	$(CC) $(FLAGS) $(CLIENT_BONUS_OBJ) -o $(CLIENT_BONUS_NAME)

clean:
	$(RM) $(SERVER_OBJ) $(CLIENT_OBJ) $(SERVER_BONUS_OBJ) $(CLIENT_BONUS_OBJ)

fclean: clean
	$(RM) $(SERVER_NAME) $(CLIENT_NAME) $(SERVER_BONUS_NAME) $(CLIENT_BONUS_NAME)

re: fclean all

bonus: $(SERVER_BONUS_NAME) $(CLIENT_BONUS_NAME)

.PHONY: all clean fclean re bonus
