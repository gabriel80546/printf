/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 08:29:20 by gabriel           #+#    #+#             */
/*   Updated: 2021/03/06 11:05:49 by gabriel          ###   ########.fr       */
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

int		ft_printf(const char *str, ...)
{
	char	*output;
	int		i;

    va_list arguments;
    va_start(arguments, str);
	// printf("va_arg(arguments, int) = %d\n", va_arg(arguments, int));

	i = 0;
	output = ft_calloc(1, 1);
	while (str[i] != '\0')
	{
		// printf("output = '%s'\n", output);
		if (str[i] != '%')
			output = ft_append(output, str[i]);
		else
		{
			output = ft_strappend(output, ft_itoa(va_arg(arguments, int)));
			i++;
		}
		i++;
	}
	ft_putstr_fd(output, 1);
	free(output);

    va_end(arguments);
	return (0);
}
