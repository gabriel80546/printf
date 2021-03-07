/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 08:29:20 by gabriel           #+#    #+#             */
/*   Updated: 2021/03/07 09:58:30 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

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
	temp = ft_itoa(va_arg(args, int));
	*output = ft_strappend(*output, temp);
	free(temp);
	saida.i -= 1;
	saida.estado = 1;
	return (saida);
}

t_print	choose_action(t_print print, char **output, va_list args)
{
	t_print	saida;

	saida = print;
	if(saida.atual_char == 'd')
		saida.estado = 3;
	return (saida);
}

t_print	until_percent(t_print print, char **output, va_list args)
{
	t_print	saida;

	saida = print;
	if (saida.atual_char != '%')
		*output = ft_append(*output, saida.atual_char);
	else
		saida.estado = 2;
	return (saida);
}

int		ft_printf_parse(const char *str, char **output, va_list args)
{
	t_print	print;

	print.i = 0;
	print.estado = 1;
	while (str[print.i] != '\0')
	{
		print.atual_char = str[print.i];
		// printf("*output = '%s'(%ld); print.estado = %d\n", *output, ft_strlen(*output), print.estado);
		if (print.estado == 1)
			print = until_percent(print, output, args);
		else if (print.estado == 2)
			print = choose_action(print, output, args);
		else if (print.estado == 3)
			print = get_number(print, output, args);
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
**	"no lugar de 'done = 1;' estaria essa linha"
**	done = vfprintf_internal_originial (stdout, format, arg, 0);
*/

int		printf_original(const char *format, ...)
{
	va_list	arg;
	int		done;

	va_start(arg, format);
	done = 1;
	va_end(arg);
	return (done);
}
