
#include "ft_printf.h"

t_cn	get_uint_init(t_cn input)
{
	t_cn conv;

	conv = input;
	conv.tt = 0;
	if (conv.saida.flags.n_right == 0 && conv.saida.flags.n_left == 0 &&
		conv.saida.flags.right_asteristic == 1 && conv.n_ui == 0)
		conv.tt = 1;
	return (conv);
}

t_cn	get_uint_change_flag(t_cn input)
{
	t_cn conv;

	conv = input;
	if (conv.saida.flags.n_right < 0)
	{
		if ((conv.saida.flags.pad_zeros == 1 &&
			conv.saida.flags.minus != 1) && conv.saida.flags.n_left_indf == 0)
			conv.saida.flags.n_right = conv.saida.flags.n_left;
	}
	return (conv);
}

t_cn	get_uint_first_pad(t_cn input, int *counter)
{
	t_cn conv;

	conv = input;
	if (conv.saida.flags.n_left >= 0 && conv.saida.flags.minus == 0)
	{
		conv.i = 0;
		conv.tam = ft_printf_itoa_log((long)conv.n_ui) - 1;
		if ((conv.tam - conv.saida.flags.n_right) < 0)
			conv.tam -= (conv.tam - conv.saida.flags.n_right);
		while (conv.i < (conv.saida.flags.n_left - conv.tam))
		{
			if ((conv.saida.flags.pad_zeros == 1 &&
				conv.saida.flags.minus != 1))
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

t_cn	get_uint_sec_pad(t_cn input, int *counter)
{
	t_cn	conv;

	conv = input;
	if (conv.saida.flags.precision == 1 && conv.saida.flags.n_right >= 0)
	{
		conv.i = 0;
		conv.tam = ft_printf_itoa_log((long)conv.n_ui) - 1;
		ft_pnchar('0', conv.saida.flags.n_right - conv.tam, counter);
	}
	return (conv);
}
