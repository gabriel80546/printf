/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 08:29:20 by gabriel           #+#    #+#             */
/*   Updated: 2021/03/10 11:21:10 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int debug = -1;
int *seg = NULL;

t_flags	ft_init_flags(void)
{
	t_flags saida;

	saida.n_left      = -2;
	saida.n_right     = -2;
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

int	ft_printf_itoa_log(long n)
{
	int contador;
	int temp;

	contador = 0;
	if (n < 0)
	{
		contador++;
		n = -n;
	}
	temp = n;
	while (n > 9)
	{
		n = n / 10;
		contador++;
	}
	n = temp;
	contador++;
	return (contador + 1);
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

	if (debug > 2) { printf("87: to_append = %p\n", to_append); }
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
	int		n;
	int		log;
	int		i;

	saida = print;
	if (debug > 2) { ft_print_flags("109: saida.", saida.flags); }

	if (debug > -1) { printf("saida.flags.pad_zeros = %d; ", saida.flags.pad_zeros); }
	if (debug > -1) { printf("saida.flags.n_left = %d\n",    saida.flags.n_left); }
	n = va_arg(args, int);
	if (saida.flags.pad_zeros != 0 && saida.flags.n_left)
	{
		log = ft_printf_itoa_log((long)n);
		i = 0;
		while ((i + log - 1) < saida.flags.n_left)
		{
			*output = ft_append(*output, '0');
			i++;
		}
	}
	// else
	// {
	temp = ft_itoa(n);
	if (debug > 2) { printf("111: temp = %p\n", temp); }
	if (debug > 2) { printf("112: temp = '%s'\n", temp); }
	// if(debug > -1) { printf("saida.flags.pad_zeros = %d\n", saida.flags.pad_zeros); }
	*output = ft_strappend(*output, temp);
	// }
	if (debug > 2) { printf("115: temp = '%s'\n", temp); }
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

t_print	parse_flags(t_print print, char **output, va_list args)
{
		t_print	saida;

	saida = print;
	if (debug > 0) { printf("138: saida.atual_char = '%c'; saida.p_flags.n_auxiliar = %d; saida.p_flags.estado = %d\n", saida.atual_char, saida.p_flags.n_auxiliar, saida.p_flags.estado); }
	if (saida.p_flags.estado == 1)
	{
		if (debug > 0) { printf("141: saida.atual_char = '%c'; saida.p_flags.n_auxiliar = %d; saida.p_flags.estado = %d\n", saida.atual_char, saida.p_flags.n_auxiliar, saida.p_flags.estado); }
		if (saida.atual_char == '-')
			saida.flags.minus = 1;
		else if (saida.atual_char == '.')
			saida.flags.precision = 1;
		else if (saida.atual_char == '*')
		{
			if (saida.flags.precision == 0)
				saida.flags.n_left = -1;
			else if (saida.flags.precision == 1 && saida.flags.n_right == -2)
				saida.flags.n_right = -1;
		}
		else if (saida.atual_char == '0' && saida.flags.pad_zeros != 1)
			saida.flags.pad_zeros = 1;
		else if (saida.atual_char >= '0' && saida.atual_char <= '9')
		{
			saida.p_flags.estado = 2;
			saida.p_flags.auxiliar = ft_calloc(1, 1);
			if (saida.flags.precision == 0)
				saida.p_flags.left_or_right = 1;
			else if (saida.flags.precision == 1 && saida.flags.n_right == -2)
				saida.p_flags.left_or_right = 2;
			else
				saida.p_flags.left_or_right = 3;
			saida.i -= 1;
		}
		else
		{
			saida.estado = CHOOSE_ACTION;
			saida.i -= 1;
		}
	}
	else if (saida.p_flags.estado == 2)
	{
		if (debug > 0) { printf("177: saida.p_flags.auxiliar = '%s'\n", saida.p_flags.auxiliar); }
		if(saida.atual_char >= '0' && saida.atual_char <= '9')
			saida.p_flags.auxiliar = ft_append(saida.p_flags.auxiliar, saida.atual_char);
		else
		{
			// printf("saida.p_flags.auxiliar = '%s'\n", saida.p_flags.auxiliar);
			saida.p_flags.n_auxiliar = ft_atoi(saida.p_flags.auxiliar);
			free(saida.p_flags.auxiliar);
			if (saida.p_flags.left_or_right == 1)
				saida.flags.n_left  = saida.p_flags.n_auxiliar;
			else if (saida.p_flags.left_or_right == 2)
				saida.flags.n_right = saida.p_flags.n_auxiliar;
			saida.p_flags.estado = 1;
			saida.i -= 1;
		}
	}
	if (debug > 0) { printf("195: saida.estado = %d\n", saida.estado); }
 	return (saida);
}

t_print	choose_action(t_print print, char **output, va_list args)
{
	t_print	saida;

	saida = print;
	if (debug > 0) { printf("204: saida.atual_char = '%c'; saida.p_flags.n_auxiliar = %d; saida.p_flags.estado = %d\n", saida.atual_char, saida.p_flags.n_auxiliar, saida.p_flags.estado); }
	if (saida.atual_char == 'd')
		saida.estado = GET_NUMBER;
	else if (saida.atual_char == 'i')
		saida.estado = GET_NUMBER;
	else if (saida.atual_char == 's')
		saida.estado = GET_STR;
	else
	{
		saida.i -= 1;
		saida.estado = UNTIL_PERCENT;
	}
	if (debug > 0) { printf("216: saida.estado = %d\n", saida.estado); }
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
		saida.p_flags.pos_inicial = saida.i;
		saida.p_flags.auxiliar = NULL;
		saida.p_flags.n_auxiliar = 0;
		saida.p_flags.estado = 1;
		saida.estado = PARSE_FLAGS;
	}
	return (saida);
}

int		ft_printf_parse(const char *str, char **output, va_list args)
{
	t_print	print;

	print.i = 0;
	print.estado = UNTIL_PERCENT;
	if (debug > 0) { printf("245: str = '%s'\n", str); }
	while (str[print.i] != '\0')
	{
		print.atual_char = str[print.i];
		if (debug > 1) { printf("249: *output = '%s'(%ld); print.estado = %d; print.p_flags.estado = %d\n", *output, ft_strlen(*output), print.estado, print.p_flags.estado); }
		if (print.estado == UNTIL_PERCENT)
			print = until_percent(print, output, args);
		else if (print.estado == PARSE_FLAGS)
			print = parse_flags(print, output, args);
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
	if (debug > 0) { printf("264: *output = '%s'(%ld); print.estado = %d\n", *output, ft_strlen(*output), print.estado); }
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
