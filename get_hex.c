
#include "ft_printf.h"

t_print	get_hex(t_print print, int *counter, va_list args)
{
	t_print			saida;
	char			*temp;
	unsigned int	n;
	int				i;
	int				tamanho;
	int				tt;


	saida = print;
	n = va_arg(args, unsigned int);
	tt = 0;
	if (saida.flags.n_right == 0 && saida.flags.n_left == 0 && saida.flags.right_asteristic == 1 && n == 0)
		tt = 1;
	if (saida.flags.n_right < 0)
	{
		if ((saida.flags.pad_zeros == 1 && saida.flags.minus != 1) && saida.flags.n_left_indf == 0)
			saida.flags.n_right = saida.flags.n_left;
	}
	if (saida.flags.n_left >= 0 && saida.flags.minus == 0)
	{
		i = 0;
		tamanho = ft_itoa_x_log((long)n) - 1;
		if ((tamanho - saida.flags.n_right) < 0)
			tamanho -= (tamanho - saida.flags.n_right);
		while (i < (saida.flags.n_left - tamanho))
		{
			if ((saida.flags.pad_zeros == 1 && saida.flags.minus != 1))
				if (saida.flags.precision == 1)
					ft_pchar(' ', counter);
				else
					ft_pchar('0', counter);
			else
				ft_pchar(' ', counter);
			i++;
		}
	}
	if (saida.flags.precision == 1 && saida.flags.n_right >= 0)
	{
		i = 0;
		tamanho = ft_itoa_x_log((long)n) - 1;
		ft_pnchar('0', saida.flags.n_right - tamanho, counter);
	}
	if (tt == 1)
	{
		temp = ft_calloc(1, 1);
	}
	else
	{
		if (n == 0 && saida.flags.precision == 1 && (saida.flags.pad_zeros == 0 || saida.flags.minus == 1))
		{
			temp = ft_calloc(1, 2);
			if (saida.flags.n_right > 0 || saida.flags.n_right < 0)
				temp[0] = '0';
			else if (saida.flags.n_left > 0)
				temp[0] = ' ';
			ft_pstr(temp, counter);
		}
		else
		{
			if (n == 0 && saida.flags.n_left_indf == 0 && saida.flags.n_right_indf == 0 && saida.flags.n_left != 0 && saida.flags.n_right == 0)
			{
				temp = ft_calloc(1, 1);
				ft_pchar(' ', counter);
			}
			else
			{
				temp = ft_itoa_x(n);
				ft_pstr(temp, counter);
			}
		}
	}
	if (saida.flags.n_left >= 0 && saida.flags.minus == 1)
	{
		i = 0;
		tamanho = ft_itoa_x_log((long)n) - 1;
		if ((tamanho - saida.flags.n_right) < 0)
			tamanho -= (tamanho - saida.flags.n_right);
		ft_pnchar(' ',saida.flags.n_left - tamanho, counter); 
	}
	free(temp);
	saida.estado = UNTIL_PERCENT;
	return (saida);
}
