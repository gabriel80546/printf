
#include "ft_printf.h"

t_print	get_percent(t_print print, int *counter, va_list args)
{
	t_print	saida;
	int		i;

	saida = print;
	if (saida.flags.n_right == -1)
	{
		saida.flags.n_right = va_arg(args, int);
	}

	if (saida.flags.n_left >= 0 && saida.flags.minus == 0)
	{
		i = 0;
		while (i < (saida.flags.n_left - 1))
		{
			if (saida.flags.pad_zeros == 1)
				ft_pchar('0', counter);
			else
				ft_pchar(' ', counter);
			i++;
		}
	}
	ft_pchar('%', counter);
	if (saida.flags.n_left >= 0 && saida.flags.minus == 1)
	{
		i = 0;
		while (i < (saida.flags.n_left - 1))
		{
			ft_pchar(' ', counter);
			i++;
		}
	}
	saida.estado = UNTIL_PERCENT;
	return (saida);
}
