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

CFLAGS = -g -Wall -Werror -Wextra
#CFLAGS = -g -Wall -Werror
CC = gcc

P = $(dir $(realpath $(lastword $(MAKEFILE_LIST))))

NAME	= libftprintf.a

SOURCES = ft_printf.c

LIBFT = make -C libft re

all: fclean
	printf "" > saida
	$(LIBFT)
	$(CC) -c -D CAMINHO_SAIDA="\"$(P)saida\"" $(CFLAGS) $(SOURCES)
	ar -rc $(NAME) ft_printf.o libft/*.o

#CAMINHO_SAIDA="$(P)saida"
fclean:
	rm -f -- *.o
	rm -f -- libftprintf.a
