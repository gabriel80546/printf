/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags_num.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpassos- <gpassos-@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 08:52:50 by gpassos-          #+#    #+#             */
/*   Updated: 2021/03/19 08:52:52 by gpassos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_print	parse_flags_num_set(t_print print)
{
	t_print	saida;

	saida = print;
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
	return (saida);
}

t_print	parse_flags_num(t_print print)
{
	t_print	saida;

	saida = print;
	if (saida.atual_char >= '0' && saida.atual_char <= '9')
	{
		saida.p_flags.aux = ft_append(saida.p_flags.aux, saida.atual_char);
		saida.leak = 1;
	}
	else
	{
		saida.p_flags.n_auxiliar = ft_atoi(saida.p_flags.aux);
		free(saida.p_flags.aux);
		saida.leak = 0;
		saida = parse_flags_num_set(saida);
		saida.p_flags.estado = 1;
		saida.i -= 1;
	}
	return (saida);
}
