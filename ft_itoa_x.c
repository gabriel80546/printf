/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpassos- <gpassos-@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 22:21:52 by gpassos-          #+#    #+#             */
/*   Updated: 2021/03/19 22:21:54 by gpassos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_itoa_x_log(unsigned long n)
{
	int	contador;
	int	temp;

	contador = 0;
	temp = n;
	while (n > 15)
	{
		n = n / 16;
		contador++;
	}
	n = temp;
	contador++;
	return (contador + 1);
}

char		*ft_itoa_x(unsigned int n)
{
	char	*saida;
	int		contador;
	char	temp;

	saida = (char *)malloc(sizeof(char) * ft_itoa_x_log(n));
	if (saida == NULL)
		return (NULL);
	*(saida + 0) = '-';
	contador = (ft_itoa_x_log(n) - 1);
	*(saida + contador) = '\0';
	while (n > 15)
	{
		temp = (n % 16) + '0';
		if (temp > '9')
			temp += ('a' - ('9' + 1));
		*(saida + contador - 1) = temp;
		n = (n / 16);
		contador--;
	}
	temp = (n % 16) + '0';
	if (temp > '9')
		temp += ('a' - ('9' + 1));
	*(saida + contador - 1) = temp;
	return (saida);
}
