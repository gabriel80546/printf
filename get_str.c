/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_str.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpassos- <gpassos-@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 22:23:00 by gpassos-          #+#    #+#             */
/*   Updated: 2021/03/19 22:23:02 by gpassos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_cn	get_str_first_pad(t_cn input, int *counter)
{
	t_cn conv;

	conv = input;
	if (conv.saida.flags.n_left >= 0 && conv.saida.flags.minus == 0)
	{
		conv.i = 0;
		conv.tam = ft_strlen(conv.temp);
		while (conv.i < (conv.saida.flags.n_left - conv.tam))
		{
			if (conv.saida.flags.pad_zeros == 1)
				ft_pchar('0', counter);
			else
				ft_pchar(' ', counter);
			conv.i++;
		}
	}
	return (conv);
}

t_cn	get_str_last_pad(t_cn input, int *counter)
{
	t_cn conv;

	conv = input;
	if (conv.saida.flags.n_left >= 0 && conv.saida.flags.minus == 1)
	{
		conv.i = 0;
		conv.tam = ft_strlen(conv.temp);
		while (conv.i < (conv.saida.flags.n_left - conv.tam))
		{
			ft_pchar(' ', counter);
			conv.i++;
		}
	}
	return (conv);
}

t_print	get_str(t_print print, int *counter, va_list args)
{
	t_cn	conv;

	conv.saida = print;
	conv.temp = va_arg(args, char*);
	if (conv.temp == NULL)
		conv.temp = "(null)";
	if (conv.saida.flags.precision == 1 && conv.saida.flags.n_right >= 0)
		conv.temp = ft_substr(conv.temp, 0, conv.saida.flags.n_right);
	else if (conv.saida.flags.precision == 1 && conv.saida.flags.n_right < 0)
		conv.temp = ft_substr(conv.temp, 0, ft_strlen(conv.temp));
	else if (conv.saida.flags.precision == 1)
		conv.temp = "";
	conv = get_str_first_pad(conv, counter);
	ft_pstr(conv.temp, counter);
	conv = get_str_last_pad(conv, counter);
	if (conv.saida.flags.precision == 1)
		free(conv.temp);
	conv.saida.estado = UNTIL_PERCENT;
	return (conv.saida);
}
