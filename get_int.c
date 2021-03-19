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

t_cn	get_int_pnumber_t(t_cn input, int *counter)
{
	t_cn conv;

	conv = input;
	if (conv.n_i == 0 && conv.saida.flags.n_left_indf == 0 &&
		conv.saida.flags.n_right_indf == 0 &&
		conv.saida.flags.n_left != 0 &&
		conv.saida.flags.n_right == 0)
	{
		conv.temp = ft_calloc(1, 1);
		ft_pchar(' ', counter);
	}
	else
	{
		conv.temp = ft_itoa(conv.n_i);
		ft_pstr(conv.temp, counter);
	}
	return (conv);
}

t_cn	get_int_pnumber(t_cn input, int *counter)
{
	t_cn conv;

	conv = input;
	if (conv.tt == 1)
		conv.temp = ft_calloc(1, 1);
	else
	{
		if (conv.n_i == 0 && conv.saida.flags.precision == 1 &&
			(conv.saida.flags.pad_zeros == 0 || conv.saida.flags.minus == 1))
		{
			conv.temp = ft_calloc(1, 2);
			if (conv.saida.flags.n_right > 0 || conv.saida.flags.n_right < 0)
				conv.temp[0] = '0';
			else if (conv.saida.flags.n_left > 0)
				conv.temp[0] = ' ';
			ft_pstr(conv.temp, counter);
		}
		else
			conv = get_int_pnumber_t(conv, counter);
	}
	return (conv);
}

t_cn	get_int_last_pad(t_cn input, int *counter)
{
	t_cn conv;

	conv = input;
	if (conv.saida.flags.n_left >= 0 && conv.saida.flags.minus == 1)
	{
		conv.i = 0;
		conv.tam = ft_printf_itoa_log((long)conv.n_i) - 1;
		if ((conv.tam - conv.saida.flags.n_right) < 0)
			conv.tam -= (conv.tam - conv.saida.flags.n_right);
		ft_pnchar(' ', conv.saida.flags.n_left - conv.tam - conv.neg, counter);
	}
	return (conv);
}

t_print	get_int(t_print print, int *counter, va_list args)
{
	t_cn	conv;

	conv.saida = print;
	conv.n_i = va_arg(args, int);
	conv.tt = 0;
	if (conv.saida.flags.n_right == 0 && conv.saida.flags.n_left == 0 &&
		conv.saida.flags.right_asteristic == 1 && conv.n_i == 0)
		conv.tt = 1;
	conv = get_int_change_flag(conv);
	conv = get_int_neg(conv);
	if (conv.neg == 1 &&
		((conv.saida.flags.pad_zeros == 1 && conv.saida.flags.minus != 1) &&
			conv.saida.flags.precision == 0))
		ft_pchar('-', counter);
	conv = get_int_first_pad(conv, counter);
	if (conv.neg == 1 && !((conv.saida.flags.pad_zeros == 1
		&& conv.saida.flags.minus != 1) && conv.saida.flags.precision == 0))
		ft_pchar('-', counter);
	conv = get_int_sec_pad(conv, counter);
	conv = get_int_pnumber(conv, counter);
	conv = get_int_last_pad(conv, counter);
	free(conv.temp);
	conv.saida.estado = UNTIL_PERCENT;
	return (conv.saida);
}
