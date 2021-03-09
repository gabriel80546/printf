/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 08:29:20 by gabriel           #+#    #+#             */
/*   Updated: 2021/03/09 14:30:52 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int debug = 0;
int *seg = NULL;

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

	if (debug > 1) { printf("52: to_append = %p\n", to_append); }
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
	temp = ft_itoa(va_arg(args, int));
	if (debug > 1) { printf("75: temp = %p\n", temp); }
	if (debug > 1) { printf("76: temp = '%s'\n", temp); }
	// if(debug > -1) { printf("saida.flags.pad_zeros = %d\n", saida.flags.pad_zeros); }
	*output = ft_strappend(*output, temp);
	if (debug > 1) { printf("78: temp = '%s'\n", temp); }
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

	saida = print;
	if (debug > 0) { printf("98: saida.atual_char = '%c'; saida.choose.n_auxiliar = %d; saida.choose.estado = %d\n", saida.atual_char, saida.choose.n_auxiliar, saida.choose.estado); }
	if (saida.choose.estado == 1)
	{
		if (debug > 0) { printf("101: saida.atual_char = '%c'; saida.choose.n_auxiliar = %d; saida.choose.estado = %d\n", saida.atual_char, saida.choose.n_auxiliar, saida.choose.estado); }
		if (saida.atual_char == 'd')
			saida.estado = GET_NUMBER;
		else if (saida.atual_char == 'i')
			saida.estado = GET_NUMBER;
		else if (saida.atual_char == 's')
			saida.estado = GET_STR;
		else if (saida.atual_char == '0' && saida.flags.pad_zeros != 1)
		{
			saida.flags.pad_zeros = 1;
			saida.choose.estado = 2;
			saida.choose.auxiliar = ft_calloc(1, 1);
		}
		else
		{
			saida.estado = UNTIL_PERCENT;
		}
	}
	else if (saida.choose.estado == 2)
	{
		if (debug > 0) { printf("122: saida.choose.auxiliar = '%s'\n", saida.choose.auxiliar); }
		if(saida.atual_char >= '0' && saida.atual_char <= '9')
		{
			saida.choose.auxiliar = ft_append(saida.choose.auxiliar, saida.atual_char);
		}
		else
		{
			// printf("saida.choose.auxiliar = '%s'\n", saida.choose.auxiliar);
			saida.choose.n_auxiliar = ft_atoi(saida.choose.auxiliar);
			free(saida.choose.auxiliar);
			saida.flags.pad_zeros = saida.choose.n_auxiliar;
			saida.choose.estado = 1;
			saida.i -= 1;
		}
	}
	if (debug > 0) { printf("135: saida.estado = %d\n", saida.estado); }
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
		saida.choose.auxiliar = NULL;
		saida.choose.n_auxiliar = 0;
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
	if (debug > 0) { printf("161: str = '%s'\n", str); }
	while (str[print.i] != '\0')
	{
		print.atual_char = str[print.i];
		if (debug > 1) { printf("165: *output = '%s'(%ld); print.estado = %d; print.choose.estado = %d\n", *output, ft_strlen(*output), print.estado, print.choose.estado); }
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
	if (debug > 0) { printf("178: *output = '%s'(%ld); print.estado = %d\n", *output, ft_strlen(*output), print.estado); }
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
