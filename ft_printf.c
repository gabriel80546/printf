/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 08:29:20 by gabriel           #+#    #+#             */
/*   Updated: 2021/03/14 11:29:31 by gpassos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

t_print	parse_flags(t_print print, va_list args)
{
	t_print	saida;

	saida = print;
	if (saida.p_flags.estado == 1)
	{
		if (saida.atual_char == '-')
			saida.flags.minus = 1;
		else if (saida.atual_char == '.')
			saida.flags.precision = 1;
		else if (saida.atual_char == '*')
		{
			if (saida.flags.precision == 0)
			{
				saida.flags.left_asteristic  = 1;
				saida.flags.n_left = va_arg(args, int);
				saida.flags.n_left_indf = 0;
				if (saida.flags.n_left < 0)
				{
					saida.flags.minus = 1;
					saida.flags.n_left = -saida.flags.n_left;
				}
			}
			else if (saida.flags.precision == 1 && saida.flags.n_right_indf == 1)
			{
				saida.flags.right_asteristic = 1;
				saida.flags.n_right = va_arg(args, int);
				saida.flags.n_right_indf = 0;
			}
		}
		else if (saida.atual_char == '0' && saida.flags.pad_zeros != 1 &&
				saida.flags.precision == 0)
			saida.flags.pad_zeros = 1;
		else if (saida.atual_char >= '0' && saida.atual_char <= '9')
		{
			saida.p_flags.estado = 2;
			saida.p_flags.auxiliar = ft_calloc(1, 1);
			if (saida.flags.precision == 0)
				saida.p_flags.left_or_right = 1;
			else if (saida.flags.precision == 1 && saida.flags.n_right_indf == 1)
				saida.p_flags.left_or_right = 2;
			else
				saida.p_flags.left_or_right = 3;
			saida.i -= 1;
		}
		else
		{
			if (saida.flags.pad_zeros == 1 && saida.flags.n_left_indf == 1)
			{
				saida.flags.pad_zeros = 0;
				saida.flags.n_left = 0;
				saida.flags.n_left_indf = 0;
			}
			saida.estado = CHOOSE_ACTION;
			saida.i -= 1;
		}
	}
	else if (saida.p_flags.estado == 2)
	{
		if (saida.atual_char >= '0' && saida.atual_char <= '9')
		{
			saida.p_flags.auxiliar = ft_append(saida.p_flags.auxiliar, saida.atual_char);
			saida.leak = 1;
		}
		else
		{
			saida.p_flags.n_auxiliar = ft_atoi(saida.p_flags.auxiliar);
			free(saida.p_flags.auxiliar);
			saida.leak = 0;
			if (saida.p_flags.left_or_right == 1)
			{
				saida.flags.n_left = saida.p_flags.n_auxiliar;
				saida.flags.n_left_indf = 0;
			}
			else if (saida.p_flags.left_or_right == 2)
			{
				saida.flags.n_right = saida.p_flags.n_auxiliar;
				saida.flags.n_right_indf = 0;
			}
			saida.p_flags.estado = 1;
			saida.i -= 1;
		}
	}
 	return (saida);
}

t_print	choose_action(t_print print)
{
	t_print	saida;

	saida = print;
	if (saida.atual_char == 'd')
		saida.estado = GET_INT;
	else if (saida.atual_char == 'i')
		saida.estado = GET_INT;
	else if (saida.atual_char == 'u')
		saida.estado = GET_UINT;
	else if (saida.atual_char == 'x')
		saida.estado = GET_hex;
	else if (saida.atual_char == 'X')
		saida.estado = GET_HEX;
	else if (saida.atual_char == 'c')
		saida.estado = GET_CHAR;
	else if (saida.atual_char == 's')
		saida.estado = GET_STR;
	else if (saida.atual_char == 'p')
		saida.estado = GET_POINTER;
	else if (saida.atual_char == '%')
		saida.estado = GET_PERCENT;
	else
		saida.estado = UNTIL_PERCENT;
	saida.i -= 1;
 	return (saida);
}

int		ft_printf_parse(const char *str, int *counter, va_list args)
{
	t_print	print;

	print.i = 0;
	print.estado = UNTIL_PERCENT;
	print.leak = 0;
	while (str[print.i] != '\0')
	{
		print.atual_char = str[print.i];
		if (print.estado == UNTIL_PERCENT)
			print = until_percent(print, counter);
		else if (print.estado == PARSE_FLAGS)
			print = parse_flags(print, args);
		else if (print.estado == CHOOSE_ACTION)
			print = choose_action(print);
		else if (print.estado == GET_INT)
			print = get_int(print, counter, args);
		else if (print.estado == GET_UINT)
			print = get_uint(print, counter, args);
		else if (print.estado == GET_hex)
			print = get_hex(print, counter, args);
		else if (print.estado == GET_HEX)
			print = get_HEX(print, counter, args);
		else if (print.estado == GET_CHAR)
			print = get_char(print, counter, args);
		else if (print.estado == GET_STR)
			print = get_str(print, counter, args);
		else if (print.estado == GET_POINTER)
			print = get_pointer(print, counter, args);
		else if (print.estado == GET_PERCENT)
			print = get_percent(print, counter, args);
		else if (print.estado == END)
			break;
		else
			return (-1);
		print.i += 1;
	}
	if (print.leak == 1)
		free(print.p_flags.auxiliar);
	return (0);
}

int		ft_printf(const char *str, ...)
{
	char	*output;
	int		counter;
	va_list	args;

	counter = 0;
	va_start(args, str);
	output = ft_calloc(1, 1);
	ft_printf_parse(str, &counter, args);
	free(output);
	va_end(args);

	return (counter);
}
