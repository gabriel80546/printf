/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   until_percent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpassos- </var/mail/gpassos->              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 07:12:57 by gpassos-          #+#    #+#             */
/*   Updated: 2021/03/19 07:13:00 by gpassos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_print	until_percent(t_print print, int *counter)
{
	t_print	saida;

	saida = print;
	if (saida.atual_char != '%')
		ft_pchar(saida.atual_char, counter);
	else
	{
		saida.flags = ft_init_flags();
		saida.p_flags.pos_inicial = saida.i;
		saida.p_flags.auxiliar = NULL;
		saida.p_flags.n_auxiliar = 0;
		saida.p_flags.estado = 1;
		saida.estado = PARSE_FLAGS;
	}
	return (saida);
}
