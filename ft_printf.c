/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 08:29:20 by gabriel           #+#    #+#             */
/*   Updated: 2021/03/06 09:56:16 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *str, ...)
{
	char	*output;
	int		i;
	int		len;

	len = ft_strlen(str);
	output = (char *)malloc(len + 1);
	i = 0;
	while (i < len)
	{
		if(*(str + i) != '%')
			*(output + i) = *(str + i);
		else
			*(output + i) = '@';
		i++;
	}
	ft_putstr_fd(output, 1);
	return (0);
}
