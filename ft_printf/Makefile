SRC = ft_printf.c \
	ft_handle_number.c \
	ft_itoa.c \
	  ft_puts.c \
	ft_print_address.c \
	ft_print_hex.c \
	ft_handle_char.c \
	ft_strcpy.c \
	ft_strlen.c

CC = cc
NAME = libftprintf.a
AR = ar -rcs
RM = rm -rf
OBJS = $(SRC:.c=.o)


all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o: %.c libftprintf.h
		gcc $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all re clean fclean