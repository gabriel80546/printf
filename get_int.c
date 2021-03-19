/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_int.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpassos- <gpassos-@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 07:34:54 by gpassos-          #+#    #+#             */
/*   Updated: 2021/03/19 07:34:55 by gpassos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_print	get_int(t_print print, int *counter, va_list args)
{
	t_print		saida;
	t_conv_num	conv;
	int			n;
	int			neg;
	int			troca;

	saida = print;
	conv = (t_conv_num) {0};
	n = va_arg(args, int);
	conv.tt = 0;
	if (saida.flags.n_right == 0 && saida.flags.n_left == 0 &&
		saida.flags.right_asteristic == 1 && n == 0)
		conv.tt = 1;
	troca = 0;
	if (saida.flags.n_right < 0)
	{
		if ((saida.flags.pad_zeros == 1 && saida.flags.minus != 1) &&
			saida.flags.n_left_indf == 0)
		{
			troca = 1;
			saida.flags.n_right = saida.flags.n_left;
		}
	}
	neg = 0;
	if (n < 0 && n != -2147483648)
	{
		n = -n;
		neg = 1;
	}
	if (neg == 1 && ((saida.flags.pad_zeros == 1 && saida.flags.minus != 1) &&
		saida.flags.precision == 0))
		ft_pchar('-', counter);
	if (saida.flags.n_left >= 0 && saida.flags.minus == 0)
	{
		conv.i = 0;
		conv.tam = ft_printf_itoa_log((long)n) - 1;
		if ((conv.tam - saida.flags.n_right) < 0)
			conv.tam -= (conv.tam - saida.flags.n_right);
		while (conv.i < (saida.flags.n_left - conv.tam - neg))
		{
			if ((saida.flags.pad_zeros == 1 && saida.flags.minus != 1))
				if (saida.flags.precision == 1)
					ft_pchar(' ', counter);
				else
					ft_pchar('0', counter);
			else
				ft_pchar(' ', counter);
			conv.i += 1;
		}
	}
	if (neg == 1 && !((saida.flags.pad_zeros == 1 && saida.flags.minus != 1) &&
		saida.flags.precision == 0))
		ft_pchar('-', counter);
	if (saida.flags.precision == 1 && saida.flags.n_right >= 0)
	{
		conv.i = 0;
		conv.tam = ft_printf_itoa_log((long)n) - 1;
		if (troca == 1)
			conv.tam += neg;
		ft_pnchar('0', saida.flags.n_right - conv.tam, counter);
	}
	if (conv.tt == 1)
		conv.temp = ft_calloc(1, 1);
	else
	{
		if (n == 0 && saida.flags.precision == 1 &&
			(saida.flags.pad_zeros == 0 || saida.flags.minus == 1))
		{
			conv.temp = ft_calloc(1, 2);
			if (saida.flags.n_right > 0 || saida.flags.n_right < 0)
				conv.temp[0] = '0';
			else if (saida.flags.n_left > 0)
				conv.temp[0] = ' ';
			ft_pstr(conv.temp, counter);
		}
		else
		{
			if (n == 0 && saida.flags.n_left_indf == 0 &&
				saida.flags.n_right_indf == 0 && saida.flags.n_left != 0 &&
				saida.flags.n_right == 0)
			{
				conv.temp = ft_calloc(1, 1);
				ft_pchar(' ', counter);
			}
			else
			{
				conv.temp = ft_itoa(n);
				ft_pstr(conv.temp, counter);
			}
		}
	}
	if (saida.flags.n_left >= 0 && saida.flags.minus == 1)
	{
		conv.i = 0;
		conv.tam = ft_printf_itoa_log((long)n) - 1;
		if ((conv.tam - saida.flags.n_right) < 0)
			conv.tam -= (conv.tam - saida.flags.n_right);
		ft_pnchar(' ', saida.flags.n_left - conv.tam - neg, counter);
	}
	free(conv.temp);
	saida.estado = UNTIL_PERCENT;
	return (saida);
}
