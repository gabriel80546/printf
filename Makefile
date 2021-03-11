# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/05 10:05:36 by gabriel           #+#    #+#              #
#    Updated: 2021/03/11 08:46:38 by gabriel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#CFLAGS = -g -Wall -Werror -Wextra
CFLAGS = -g -Wall -Werror
CC = gcc

NAME	= libftprintf.a

SOURCES = ft_printf.c

LIBFT = make -C libft re

all: fclean
	$(LIBFT)
	$(CC) -c $(CFLAGS) $(SOURCES)
	ar -rc $(NAME) ft_printf.o libft/*.o

fclean:
	rm -f -- *.o