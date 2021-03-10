/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 08:29:20 by gabriel           #+#    #+#             */
/*   Updated: 2021/03/10 09:39:23 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int debug = 2;
int *seg = NULL;

t_flags	ft_init_flags(void)
{
	t_flags saida;

	saida.n_left      = 0;
	saida.n_right     = 0;
	saida.pad_zeros   = 0;
	saida.minus       = 0;
	saida.precision   = 0;
	saida.asteristc_l = 0;
	saida.asteristc_r = 0;
	return (saida);
}

void	ft_print_flags(char *append, t_flags flags)
{
	printf("%sflags.asteristc_l = %d\n", append, flags.asteristc_l);
	printf("%sflags.asteristc_r = %d\n", append, flags.asteristc_r);
	printf("%sflags.minus       = %d\n", append, flags.minus);
	printf("%sflags.n_left      = %d\n", append, flags.n_left);
	printf("%sflags.n_right     = %d\n", append, flags.n_right);
	printf("%sflags.pad_zeros   = %d\n", append, flags.pad_zeros);
	printf("%sflags.precision   = %d\n", append, flags.precision);
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

	if (debug > 2) { printf("54: to_append = %p\n", to_append); }
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
	if (debug > 1) { ft_print_flags("87: saida.", saida.flags); }
	temp = ft_itoa(va_arg(args, int));
	if (debug > 2) { printf("77: temp = %p\n", temp); }
	if (debug > 2) { printf("78: temp = '%s'\n", temp); }
	// if(debug > -1) { printf("saida.flags.pad_zeros = %d\n", saida.flags.pad_zeros); }
	*output = ft_strappend(*output, temp);
	if (debug > 2) { printf("81: temp = '%s'\n", temp); }
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
	if (debug > 0) { printf("104: saida.atual_char = '%c'; saida.choose.n_auxiliar = %d; saida.choose.estado = %d\n", saida.atual_char, saida.choose.n_auxiliar, saida.choose.estado); }
	if (saida.choose.estado == 1)
	{
		if (debug > 0) { printf("107: saida.atual_char = '%c'; saida.choose.n_auxiliar = %d; saida.choose.estado = %d\n", saida.atual_char, saida.choose.n_auxiliar, saida.choose.estado); }
		if (saida.atual_char == 'd')
			saida.estado = GET_NUMBER;
		else if (saida.atual_char == 'i')
			saida.estado = GET_NUMBER;
		else if (saida.atual_char == 's')
			saida.estado = GET_STR;
		else if (saida.atual_char == '-')
			saida.flags.minus = 1;
		else if (saida.atual_char == '.')
			saida.flags.precision = 1;
		else if (saida.atual_char == '*')
		{
			if (saida.flags.precision == 0)
				saida.flags.n_left = -1;
			else if (saida.flags.precision == 1 && saida.flags.n_right == 0)
				saida.flags.n_right = -1;
		}
		else if (saida.atual_char == '0' && saida.flags.pad_zeros != 1)
		{
			saida.flags.pad_zeros = 1;
		}
		else if (saida.atual_char >= '0' && saida.atual_char <= '9')
		{
			saida.choose.estado = 2;
			saida.choose.auxiliar = ft_calloc(1, 1);
			if (saida.flags.precision == 0)
				saida.choose.left_or_right = 1;
			else if (saida.flags.precision == 1 && saida.flags.n_right == 0)
				saida.choose.left_or_right = 2;
			else
				saida.choose.left_or_right = 3;
			saida.i -= 1;
		}
		else
		{
			saida.estado = UNTIL_PERCENT;
			saida.i -= 1;
		}
	}
	else if (saida.choose.estado == 2)
	{
		if (debug > 0) { printf("149: saida.choose.auxiliar = '%s'\n", saida.choose.auxiliar); }
		if(saida.atual_char >= '0' && saida.atual_char <= '9')
		{
			saida.choose.auxiliar = ft_append(saida.choose.auxiliar, saida.atual_char);
		}
		else
		{
			// printf("saida.choose.auxiliar = '%s'\n", saida.choose.auxiliar);
			saida.choose.n_auxiliar = ft_atoi(saida.choose.auxiliar);
			free(saida.choose.auxiliar);
			if (saida.choose.left_or_right == 1)
				saida.flags.n_left  = saida.choose.n_auxiliar;
			else if (saida.choose.left_or_right == 2)
				saida.flags.n_right = saida.choose.n_auxiliar;
			saida.choose.estado = 1;
			saida.i -= 1;
		}
	}
	if (debug > 0) { printf("167: saida.estado = %d\n", saida.estado); }
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
	if (debug > 0) { printf("196: str = '%s'\n", str); }
	while (str[print.i] != '\0')
	{
		print.atual_char = str[print.i];
		if (debug > 1) { printf("200: *output = '%s'(%ld); print.estado = %d; print.choose.estado = %d\n", *output, ft_strlen(*output), print.estado, print.choose.estado); }
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
	if (debug > 0) { printf("213: *output = '%s'(%ld); print.estado = %d\n", *output, ft_strlen(*output), print.estado); }
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
