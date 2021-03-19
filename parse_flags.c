/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpassos- <gpassos-@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 08:52:47 by gpassos-          #+#    #+#             */
/*   Updated: 2021/03/19 08:52:49 by gpassos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_print	parse_flags_star(t_print print, va_list args)
{
	t_print	saida;

	saida = print;
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
	return (saida);
}

t_print	parse_flags_end(t_print print)
{
	t_print	saida;

	saida = print;
	if (saida.flags.pad_zeros == 1 && saida.flags.n_left_indf == 1)
	{
		saida.flags.pad_zeros = 0;
		saida.flags.n_left = 0;
		saida.flags.n_left_indf = 0;
	}
	saida.estado = CHOOSE_ACTION;
	saida.i -= 1;
	return (saida);
}

t_print	parse_flags_prep_num(t_print print)
{
	t_print	saida;

	saida = print;
	saida.p_flags.estado = 2;
	saida.p_flags.aux = ft_calloc(1, 1);
	if (saida.flags.precision == 0)
		saida.p_flags.left_or_right = 1;
	else if (saida.flags.precision == 1 && saida.flags.n_right_indf == 1)
		saida.p_flags.left_or_right = 2;
	else
		saida.p_flags.left_or_right = 3;
	saida.i -= 1;
	return (saida);
}

t_print	parse_flags_main(t_print print, va_list args)
{
	t_print	saida;

	saida = print;
	if (saida.atual_char == '-')
		saida.flags.minus = 1;
	else if (saida.atual_char == '.')
		saida.flags.precision = 1;
	else if (saida.atual_char == '*')
		saida = parse_flags_star(saida, args);
	else if (saida.atual_char == '0' && saida.flags.pad_zeros != 1 &&
			saida.flags.precision == 0)
		saida.flags.pad_zeros = 1;
	else if (saida.atual_char >= '0' && saida.atual_char <= '9')
		saida = parse_flags_prep_num(saida);
	else if (saida.atual_char >= '0' && saida.atual_char <= '9')
		saida = parse_flags_prep_num(saida);
	else
		saida = parse_flags_end(saida);
	return (saida);
}

t_print	parse_flags(t_print print, va_list args)
{
	t_print	saida;

	saida = print;
	if (saida.p_flags.estado == 1)
		saida = parse_flags_main(saida, args);
	else if (saida.p_flags.estado == 2)
		saida = parse_flags_num(saida);
	return (saida);
}
