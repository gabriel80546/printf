/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 08:29:20 by gabriel           #+#    #+#             */
/*   Updated: 2021/03/08 07:27:38 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

t_flags	ft_init_flags(void)
{
	t_flags saida;

	saida.min_width = -1;
	saida.max_width = -1;
	saida.minus = -1;
	saida.asteristc = -1;
	saida.pad_zeros = -1;
	return (saida);
}

char	*ft_append(char *str, char caracter)
{
	char	*saida;
	int		len;

	len = ft_strlen(str);
	saida = (char *)malloc(len + 2);
	ft_strlcpy(saida, str, len + 1);
	saida[len + 0] = caracter;
	saida[len + 1] = '\0';
	free(str);
	return (saida);
}

char	*ft_strappend(char *str, char *to_append)
{
	char	*saida;
	int		i;
	int		len_str;
	int		len_append;

	len_str = ft_strlen(str);
	len_append = ft_strlen(to_append);
	saida = (char *)malloc(len_str + len_append + 2);
	ft_strlcpy(saida, str, len_str + 1);
	i = 0;
	while (to_append[i] != '\0')
	{
		saida[len_str + i] = to_append[i];
		i++;
	}
	saida[len_str + i] = '\0';
	free(str);
	return (saida);
}

t_print	get_number(t_print print, char **output, va_list args)
{
	t_print	saida;
	char	*temp;

	saida = print;
	// printf("saida.flags.min_width = %d\n", saida.flags.min_width);
	temp = ft_itoa(va_arg(args, int));
	*output = ft_strappend(*output, temp);
	free(temp);
	saida.i -= 1;
	saida.estado = UNTIL_PERCENT;
	return (saida);
}

t_print	get_str(t_print print, char **output, va_list args)
{
	t_print	saida;

	saida = print;
	*output = ft_strappend(*output, va_arg(args, char*));
	saida.i -= 1;
	saida.estado = UNTIL_PERCENT;
	return (saida);
}

t_print	choose_action(t_print print, char **output, va_list args)
{
	t_print	saida;
	int		*seg;

	seg = 0;
	saida = print;
	if (saida.choose.estado == 1)
	{
		if (saida.atual_char == 'd')
			saida.estado = GET_NUMBER;
		else if (saida.atual_char == 'i')
			saida.estado = GET_NUMBER;
		else if (saida.atual_char == 's')
			saida.estado = GET_STR;
		else if (saida.atual_char == '0' && saida.flags.pad_zeros == -1)
			saida.flags.pad_zeros = 1;
		else if (saida.atual_char >= '1' && saida.atual_char <= '9')
		{
			saida.choose.estado = 2;
			saida.i -= 1;
		}
		else
		{
			*output = ft_append(*output, '%');
			saida.i = saida.choose.pos_inicial;
			saida.estado = UNTIL_PERCENT;
			saida.choose.estado = 1;
		}
	}
	else if (saida.choose.estado == 2)
	{
		printf("antes do segfault\n");
		printf("saida.atual_char = '%c'\n", saida.atual_char);
		*seg = 123;
		printf("depois do segfault\n");
	}
	return (saida);
}

t_print	until_percent(t_print print, char **output, va_list args)
{
	t_print	saida;

	saida = print;
	if (saida.atual_char != '%')
		*output = ft_append(*output, saida.atual_char);
	else
	{
		saida.flags = ft_init_flags();
		saida.choose.pos_inicial = saida.i;
		saida.estado = CHOOSE_ACTION;
		saida.choose.estado = 1;
	}
	return (saida);
}

int		ft_printf_parse(const char *str, char **output, va_list args)
{
	t_print	print;

	print.i = 0;
	print.estado = UNTIL_PERCENT;
	while (str[print.i] != '\0')
	{
		print.atual_char = str[print.i];
		// printf("*output = '%s'(%ld); print.estado = %d\n", *output, ft_strlen(*output), print.estado);
		if (print.estado == UNTIL_PERCENT)
			print = until_percent(print, output, args);
		else if (print.estado == CHOOSE_ACTION)
			print = choose_action(print, output, args);
		else if (print.estado == GET_NUMBER)
			print = get_number(print, output, args);
		else if (print.estado == GET_STR)
			print = get_str(print, output, args);
		else
			return (-1);
		print.i += 1;
	}
	// printf("*output = '%s'(%ld); print.estado = %d\n", *output, ft_strlen(*output), print.estado);
	return (0);
}

int		ft_printf(const char *str, ...)
{
	char	*output;
	int		saida;
	va_list	args;

	va_start(args, str);
	output = ft_calloc(1, 1);
	saida = ft_printf_parse(str, &output, args);
	ft_putstr_fd(output, 1);
	free(output);
	va_end(args);
	return (saida);
}

/*
**	int		printf_original(const char *format, ...)
**	{
**		va_list	arg;
**		int		done;
**
**		va_start(arg, format);
**		done = vfprintf_internal_originial (stdout, format, arg, 0);
**		va_end(arg);
**		return (done);
**	}
*/
