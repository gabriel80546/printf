/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_hex_upper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpassos- <gpassos-@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 22:22:31 by gpassos-          #+#    #+#             */
/*   Updated: 2021/03/19 22:22:32 by gpassos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_cn	get_hex_up_pnumber_t(t_cn input, int *counter)
{
	t_cn conv;

	conv = input;
	if (conv.n_ui == 0 && conv.saida.flags.n_left_indf == 0 &&
		conv.saida.flags.n_right_indf == 0 &&
		conv.saida.flags.n_left != 0 && conv.saida.flags.n_right == 0)
	{
		conv.temp = ft_calloc(1, 1);
		ft_pchar(' ', counter);
	}
	else
	{
		conv.temp = ft_itoa_x_upper(conv.n_ui);
		ft_pstr(conv.temp, counter);
	}
	return (conv);
}

t_cn	get_hex_up_pnumber(t_cn input, int *counter)
{
	t_cn conv;

	conv = input;
	if (conv.tt == 1)
		conv.temp = ft_calloc(1, 1);
	else
	{
		if (conv.n_ui == 0 && conv.saida.flags.precision == 1 &&
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
			conv = get_hex_up_pnumber_t(conv, counter);
	}
	return (conv);
}

t_cn	get_hex_up_last_pad(t_cn input, int *counter)
{
	t_cn conv;

	conv = input;
	if (conv.saida.flags.n_left >= 0 && conv.saida.flags.minus == 1)
	{
		conv.i = 0;
		conv.tam = ft_itoa_x_upper_log((long)conv.n_ui) - 1;
		if ((conv.tam - conv.saida.flags.n_right) < 0)
			conv.tam -= (conv.tam - conv.saida.flags.n_right);
		ft_pnchar(' ', conv.saida.flags.n_left - conv.tam, counter);
	}
	return (conv);
}

t_print	get_hex_up(t_print print, int *counter, va_list args)
{
	t_cn	conv;

	conv.saida = print;
	conv.n_ui = va_arg(args, unsigned int);
	conv = get_hex_up_init(conv);
	conv = get_hex_up_change_flag(conv);
	conv = get_hex_up_first_pad(conv, counter);
	conv = get_hex_up_sec_pad(conv, counter);
	conv = get_hex_up_pnumber(conv, counter);
	conv = get_hex_up_last_pad(conv, counter);
	free(conv.temp);
	conv.saida.estado = UNTIL_PERCENT;
	return (conv.saida);
}
