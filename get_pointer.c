/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pointer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpassos- <gpassos-@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 22:22:56 by gpassos-          #+#    #+#             */
/*   Updated: 2021/03/19 22:22:57 by gpassos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_cn	get_pointer_first_pad(t_cn input, int *counter)
{
	t_cn conv;

	conv = input;
	if (conv.saida.flags.n_left >= 0 && conv.saida.flags.minus == 0)
	{
		conv.i = 0;
		if (conv.n_ul == 0 && conv.saida.flags.precision == 1)
			conv.tam = ft_itoa_x_ul_log(conv.n_ul) - 2 + 2;
		else
			conv.tam = ft_itoa_x_ul_log(conv.n_ul) - 1 + 2;
		if ((conv.tam - conv.saida.flags.n_right) < 0)
			conv.tam -= (conv.tam - conv.saida.flags.n_right);
		while (conv.i < (conv.saida.flags.n_left - conv.tam))
		{
			if (conv.saida.flags.pad_zeros == 1)
				if (conv.saida.flags.precision == 1)
					ft_pchar(' ', counter);
				else
					ft_pchar('0', counter);
			else
				ft_pchar(' ', counter);
			conv.i++;
		}
	}
	return (conv);
}

t_cn	get_pointer_sec_pad(t_cn input, int *counter)
{
	t_cn conv;

	conv = input;
	if (conv.saida.flags.precision == 1 && conv.saida.flags.n_right >= 0)
	{
		conv.i = 0;
		conv.tam = ft_itoa_x_ul_log(conv.n_ul) - 1 + 0;
		while (conv.i < (conv.saida.flags.n_right - conv.tam))
		{
			ft_pchar('0', counter);
			conv.i++;
		}
	}
	return (conv);
}

t_cn	get_pointer_pnumber(t_cn input, int *counter)
{
	t_cn conv;

	conv = input;
	conv.temp = ft_itoa_x_ul(conv.n_ul);
	if (!(conv.saida.flags.precision == 1 && conv.saida.flags.n_right <= 0 &&
		conv.n_ul == 0))
		ft_pstr(conv.temp, counter);
	return (conv);
}

t_cn	get_pointer_last_pad(t_cn input, int *counter)
{
	t_cn conv;

	conv = input;
	if (conv.saida.flags.n_left >= 0 && conv.saida.flags.minus == 1)
	{
		conv.i = 0;
		if (conv.n_ul == 0 && conv.saida.flags.precision == 1)
			conv.tam = ft_itoa_x_ul_log(conv.n_ul) - 2 + 2;
		else
			conv.tam = ft_itoa_x_ul_log(conv.n_ul) - 1 + 2;
		if ((conv.tam - conv.saida.flags.n_right) < 0)
			conv.tam -= (conv.tam - conv.saida.flags.n_right);
		while (conv.i < (conv.saida.flags.n_left - conv.tam))
		{
			if (conv.saida.flags.pad_zeros == 1)
				ft_pchar(' ', counter);
			else
				ft_pchar(' ', counter);
			conv.i++;
		}
	}
	return (conv);
}

t_print	get_pointer(t_print print, int *counter, va_list args)
{
	t_cn	conv;

	conv.saida = print;
	conv.n_ul = va_arg(args, unsigned long);
	conv = get_pointer_first_pad(conv, counter);
	ft_pstr("0x", counter);
	conv = get_pointer_sec_pad(conv, counter);
	conv = get_pointer_pnumber(conv, counter);
	conv = get_pointer_last_pad(conv, counter);
	free(conv.temp);
	conv.saida.estado = UNTIL_PERCENT;
	return (conv.saida);
}
