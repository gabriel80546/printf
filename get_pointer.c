/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pointer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpassos- <gpassos-@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 07:35:02 by gpassos-          #+#    #+#             */
/*   Updated: 2021/03/19 07:35:03 by gpassos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_print	get_pointer(t_print print, int *counter, va_list args)
{
	t_print			saida;
	char			*temp;
	int				tamanho;
	unsigned long	n;
	int				i;

	saida = print;
	n = va_arg(args, unsigned long);
	if (saida.flags.n_left >= 0 && saida.flags.minus == 0)
	{
		i = 0;
		if (n == 0 && saida.flags.precision == 1)
			tamanho = ft_itoa_x_ul_log(n) - 2 + 2;
		else
			tamanho = ft_itoa_x_ul_log(n) - 1 + 2;
		if ((tamanho - saida.flags.n_right) < 0)
			tamanho -= (tamanho - saida.flags.n_right);
		while (i < (saida.flags.n_left - tamanho))
		{
			if (saida.flags.pad_zeros == 1)
				if (saida.flags.precision == 1)
					ft_pchar(' ', counter);
				else
					ft_pchar('0', counter);
			else
				ft_pchar(' ', counter);
			i++;
		}
	}
	ft_pstr("0x", counter);
	if (saida.flags.precision == 1 && saida.flags.n_right >= 0)
	{
		i = 0;
		tamanho = ft_itoa_x_ul_log(n) - 1 + 0;
		while (i < (saida.flags.n_right - tamanho))
		{
			ft_pchar('0', counter);
			i++;
		}
	}

	temp = ft_itoa_x_ul(n);
	if (!(saida.flags.precision == 1 && saida.flags.n_right <= 0 && n == 0))
		ft_pstr(temp, counter);
	if (saida.flags.n_left >= 0 && saida.flags.minus == 1)
	{
		i = 0;
		if (n == 0 && saida.flags.precision == 1)
			tamanho = ft_itoa_x_ul_log(n) - 2 + 2;
		else
			tamanho = ft_itoa_x_ul_log(n) - 1 + 2;
		if ((tamanho - saida.flags.n_right) < 0)
			tamanho -= (tamanho - saida.flags.n_right);
		while (i < (saida.flags.n_left - tamanho))
		{
			if (saida.flags.pad_zeros == 1)
				ft_pchar(' ', counter);
			else
				ft_pchar(' ', counter);
			i++;
		}
	}
	free(temp);
	saida.estado = UNTIL_PERCENT;
	return (saida);
}
