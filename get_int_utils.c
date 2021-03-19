

#include "ft_printf.h"

t_cn	get_int_change_flag(t_cn input)
{
	t_cn conv;

	conv = input;
	conv.troca = 0;
	if (conv.saida.flags.n_right < 0)
	{
		if ((conv.saida.flags.pad_zeros == 1 && conv.saida.flags.minus != 1) &&
		conv.saida.flags.n_left_indf == 0)
		{
			conv.troca = 1;
			conv.saida.flags.n_right = conv.saida.flags.n_left;
		}
	}
	return (conv);
}

t_cn	get_int_neg(t_cn input)
{
	t_cn conv;

	conv = input;
	conv.neg = 0;
	if (conv.n_i < 0 && conv.n_i != -2147483648)
	{
		conv.n_i = -conv.n_i;
		conv.neg = 1;
	}
	return (conv);
}

t_cn	get_int_first_pad(t_cn input, int *counter)
{
	t_cn conv;

	conv = input;
	if (conv.saida.flags.n_left >= 0 && conv.saida.flags.minus == 0)
	{
		conv.i = 0;
		conv.tam = ft_printf_itoa_log((long)conv.n_i) - 1;
		if ((conv.tam - conv.saida.flags.n_right) < 0)
			conv.tam -= (conv.tam - conv.saida.flags.n_right);
		while (conv.i < (conv.saida.flags.n_left - conv.tam - conv.neg))
		{
			if ((conv.saida.flags.pad_zeros == 1 &&
				conv.saida.flags.minus != 1))
				if (conv.saida.flags.precision == 1)
					ft_pchar(' ', counter);
				else
					ft_pchar('0', counter);
			else
				ft_pchar(' ', counter);
			conv.i += 1;
		}
	}
	return (conv);
}

t_cn	get_int_sec_pad(t_cn input, int *counter)
{
	t_cn conv;

	conv = input;
	if (conv.saida.flags.precision == 1 && conv.saida.flags.n_right >= 0)
	{
		conv.i = 0;
		conv.tam = ft_printf_itoa_log((long)conv.n_i) - 1;
		if (conv.troca == 1)
			conv.tam += conv.neg;
		ft_pnchar('0', conv.saida.flags.n_right - conv.tam, counter);
	}
	return (conv);
}
