# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gpassos- <gpassos-@student.42sp.org>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/19 22:23:31 by gpassos-          #+#    #+#              #
#    Updated: 2021/03/19 22:23:33 by gpassos-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Werror -Wextra
CC = clang
NAME = libftprintf.a
LIBFT = make -C libft re
SOURCES = ft_itoa.c ft_itoa_ui.c ft_itoa_x_ul.c ft_itoa_x.c \
			ft_printf.c ft_put.c ft_append.c ft_init.c \
			until_percent.c get_char.c get_hex.c get_hex_utils.c \
			get_hex_upper.c get_hex_upper_utils.c get_int.c \
			get_int_utils.c get_percent.c get_pointer.c get_str.c \
			get_uint.c get_uint_utils.c ft_itoa_x_upper.c \
			parse_flags.c parse_flags_num.c

OBJS = $(SOURCES:.c=.o)

%.o: %.c
	$(CC) -c $(CFLAGS) $^

$(NAME): $(OBJS)
	$(LIBFT)
	ar -rc $(NAME) $^ libft/*.o

all: $(NAME)

re: fclean all

clean:
	rm -f -- *.o

fclean: clean
	rm -f -- libftprintf.a

bonus:
	echo ""
