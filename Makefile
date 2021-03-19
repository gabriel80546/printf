# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/05 10:05:36 by gabriel           #+#    #+#              #
#    Updated: 2021/03/12 08:05:54 by gabriel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#CFLAGS = -Wall -Werror -Wextra
CFLAGS = -g -Wall -Werror -Wextra
CC = clang
NAME = libftprintf.a
LIBFT = make -C libft re
SOURCES = ft_itoa.c ft_itoa_ui.c ft_itoa_x_ul.c ft_itoa_x.c \
			ft_printf.c ft_itoa_X.c ft_put.c ft_append.c \
			ft_init.c until_percent.c get_char.c get_hex.c \
			get_hex_upper.c get_int.c get_percent.c get_pointer.c \
			get_str.c get_uint.c

OBJS = $(SOURCES:.c=.o)

%.o: %.c
	$(CC) -c $(CFLAGS) $^

all: $(OBJS)
	$(LIBFT)
	ar -rc $(NAME) $^ libft/*.o

re: fclean all

fclean:
	rm -f -- *.o
	rm -f -- libftprintf.a
