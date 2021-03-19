/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_ui.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpassos- <gpassos-@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 07:34:18 by gpassos-          #+#    #+#             */
/*   Updated: 2021/03/19 07:34:19 by gpassos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	ft_itoa_ui_log(unsigned long n)
{
	unsigned int	contador;
	unsigned int	temp;

	contador = 0;
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

char			*ft_itoa_ui(unsigned int n)
{
	char			*saida;
	unsigned int	contador;

	saida = (char *)malloc(sizeof(char) * ft_itoa_ui_log(n));
	if (saida == NULL)
		return (NULL);
	*(saida + 0) = '-';
	contador = (ft_itoa_ui_log(n) - 1);
	*(saida + contador) = '\0';
	while (n > 9)
	{
		*(saida + contador - 1) = (n % 10) + '0';
		n = (n / 10);
		contador--;
	}
	*(saida + contador - 1) = (n % 10) + '0';
	return (saida);
}
