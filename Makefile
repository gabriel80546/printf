# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/05 10:05:36 by gabriel           #+#    #+#              #
#    Updated: 2021/03/05 10:25:35 by gabriel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#CFLAGS = -g -Wall -Werror -Wextra
CFLAGS = -g -Wall -Werror
CC = gcc

SOURCES = ft_printf.c

LIBFT = make -C libft re

all: 
	$(LIBFT)
	$(CC) -c $(CFLAGS) $(SOURCES)
