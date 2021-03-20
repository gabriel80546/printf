/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_percent.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpassos- <gpassos-@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 07:34:58 by gpassos-          #+#    #+#             */
/*   Updated: 2021/03/19 07:34:59 by gpassos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_print	get_percent(t_print print, int *counter)
{
	t_print	saida;
	int		i;

	saida = print;
	if (saida.flags.n_left >= 0 && saida.flags.minus == 0)
	{
		if (saida.flags.pad_zeros == 1)
			ft_pnchar('0', saida.flags.n_left - 1, counter);
		else
			ft_pnchar(' ', saida.flags.n_left - 1, counter);
	}
	ft_pchar('%', counter);
	if (saida.flags.n_left >= 0 && saida.flags.minus == 1)
		ft_pnchar(' ', saida.flags.n_left - 1, counter);
	saida.estado = UNTIL_PERCENT;
	return (saida);
}
