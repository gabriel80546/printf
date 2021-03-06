/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 08:29:20 by gabriel           #+#    #+#             */
/*   Updated: 2021/03/06 10:25:49 by gabriel          ###   ########.fr       */
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

int		ft_printf(const char *str, ...)
{
	char	*output;
	int		i;

	i = 0;
	output = ft_calloc(1, 1);
	while (str[i] != '\0')
	{
		if(str[i] != '%')
			output = ft_append(output, str[i]);
		else
			output = ft_append(output, '@');
		i++;
	}
	ft_putstr_fd(output, 1);
	free(output);
	return (0);
}
