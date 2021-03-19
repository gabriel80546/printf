/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpassos- <gpassos-@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 07:34:04 by gpassos-          #+#    #+#             */
/*   Updated: 2021/03/19 07:34:06 by gpassos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_itoa_log(long n)
{
	int	contador;
	int	temp;

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
