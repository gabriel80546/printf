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

int			get_int_neg(int *n)
{
	if (*n < 0 && *n != -2147483648)
	{
		*n = -*n;
		return (1);
	}
	return (0);
}

t_print		get_int_change_f(t_print print, int *t)
{
	t_print		saida;

	saida = print;
	*t = 0;
	if (saida.flags.n_right < 0)
	{
		if ((saida.flags.pad_zeros == 1 && saida.flags.minus != 1) &&
			saida.flags.n_left_indf == 0)
		{
			*t = 1;
			saida.flags.n_right = saida.flags.n_left;
		}
	}
	return (saida);
}

t_conv_num	get_int_pzero_t(t_conv_num in, t_print saida, int *counter, int n)
{
	t_conv_num conv;

	conv = in;
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
	return (conv);
}

t_conv_num	get_int_pzero(t_conv_num input, t_print saida, int *counter, int n)
{
	t_conv_num conv;

	conv = input;
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
		conv = get_int_pzero_t(conv, saida, counter, n);
	return (conv);
}

t_conv_num	get_int_pad(t_conv_num in, t_print saida, int *c, int n, int neg)
{
	t_conv_num conv;

	conv = in;
	conv.i = 0;
	conv.tam = ft_printf_itoa_log((long)n) - 1;
	if ((conv.tam - saida.flags.n_right) < 0)
		conv.tam -= (conv.tam - saida.flags.n_right);
	while (conv.i < (saida.flags.n_left - conv.tam - neg))
	{
		if ((saida.flags.pad_zeros == 1 && saida.flags.minus != 1))
			if (saida.flags.precision == 1)
				ft_pchar(' ', c);
			else
				ft_pchar('0', c);
		else
			ft_pchar(' ', c);
		conv.i += 1;
	}
	return (conv);
}

t_conv_num	get_int_pad_t(t_conv_num in, t_print saida, int *c, int n, int t, int neg)
{
	t_conv_num conv;

	conv = in;
	conv.i = 0;
	conv.tam = ft_printf_itoa_log((long)n) - 1;
	if (t == 1)
		conv.tam += neg;
	ft_pnchar('0', saida.flags.n_right - conv.tam, c);
	return (conv);
}

t_conv_num	get_int_end(t_conv_num in, t_print saida, int *c, int n, int neg)
{
	t_conv_num conv;

	conv = in;
	conv.i = 0;
	conv.tam = ft_printf_itoa_log((long)n) - 1;
	if ((conv.tam - saida.flags.n_right) < 0)
		conv.tam -= (conv.tam - saida.flags.n_right);
	ft_pnchar(' ', saida.flags.n_left - conv.tam - neg, c);
	return (conv);
}

t_print		get_int(t_print print, int *counter, va_list args)
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
	saida = get_int_change_f(saida, &troca);
	neg = get_int_neg(&n);
	if (neg == 1 && ((saida.flags.pad_zeros == 1 && saida.flags.minus != 1) &&
		saida.flags.precision == 0))
		ft_pchar('-', counter);
	if (saida.flags.n_left >= 0 && saida.flags.minus == 0)
		conv = get_int_pad(conv, saida, counter, n, neg);
	if (neg == 1 && !((saida.flags.pad_zeros == 1 && saida.flags.minus != 1) &&
		saida.flags.precision == 0))
		ft_pchar('-', counter);
	if (saida.flags.precision == 1 && saida.flags.n_right >= 0)
		conv = get_int_pad_t(conv, saida, counter, n, troca, neg);
	if (conv.tt == 1)
		conv.temp = ft_calloc(1, 1);
	else
		conv = get_int_pzero(conv, saida, counter, n);
	if (saida.flags.n_left >= 0 && saida.flags.minus == 1)
		conv = get_int_end(conv, saida, counter, n, neg);
	free(conv.temp);
	saida.estado = UNTIL_PERCENT;
	return (saida);
}
