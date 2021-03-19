
#include "ft_printf.h"

t_print	parse_flags(t_print print, va_list args)
{
	t_print	saida;

	saida = print;
	if (saida.p_flags.estado == 1)
	{
		if (saida.atual_char == '-')
			saida.flags.minus = 1;
		else if (saida.atual_char == '.')
			saida.flags.precision = 1;
		else if (saida.atual_char == '*')
		{
			if (saida.flags.precision == 0)
			{
				saida.flags.left_asteristic = 1;
				saida.flags.n_left = va_arg(args, int);
				saida.flags.n_left_indf = 0;
				if (saida.flags.n_left < 0)
				{
					saida.flags.minus = 1;
					saida.flags.n_left = -saida.flags.n_left;
				}
			}
			else if (saida.flags.precision == 1 && saida.flags.n_right_indf == 1)
			{
				saida.flags.right_asteristic = 1;
				saida.flags.n_right = va_arg(args, int);
				saida.flags.n_right_indf = 0;
			}
		}
		else if (saida.atual_char == '0' && saida.flags.pad_zeros != 1 &&
				saida.flags.precision == 0)
			saida.flags.pad_zeros = 1;
		else if (saida.atual_char >= '0' && saida.atual_char <= '9')
		{
			saida.p_flags.estado = 2;
			saida.p_flags.auxiliar = ft_calloc(1, 1);
			if (saida.flags.precision == 0)
				saida.p_flags.left_or_right = 1;
			else if (saida.flags.precision == 1 && saida.flags.n_right_indf == 1)
				saida.p_flags.left_or_right = 2;
			else
				saida.p_flags.left_or_right = 3;
			saida.i -= 1;
		}
		else
		{
			if (saida.flags.pad_zeros == 1 && saida.flags.n_left_indf == 1)
			{
				saida.flags.pad_zeros = 0;
				saida.flags.n_left = 0;
				saida.flags.n_left_indf = 0;
			}
			saida.estado = CHOOSE_ACTION;
			saida.i -= 1;
		}
	}
	else if (saida.p_flags.estado == 2)
	{
		if (saida.atual_char >= '0' && saida.atual_char <= '9')
		{
			saida.p_flags.auxiliar = ft_append(saida.p_flags.auxiliar, saida.atual_char);
			saida.leak = 1;
		}
		else
		{
			saida.p_flags.n_auxiliar = ft_atoi(saida.p_flags.auxiliar);
			free(saida.p_flags.auxiliar);
			saida.leak = 0;
			if (saida.p_flags.left_or_right == 1)
			{
				saida.flags.n_left = saida.p_flags.n_auxiliar;
				saida.flags.n_left_indf = 0;
			}
			else if (saida.p_flags.left_or_right == 2)
			{
				saida.flags.n_right = saida.p_flags.n_auxiliar;
				saida.flags.n_right_indf = 0;
			}
			saida.p_flags.estado = 1;
			saida.i -= 1;
		}
	}
	return (saida);
}
