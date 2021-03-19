/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_char.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpassos- <gpassos-@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 07:34:43 by gpassos-          #+#    #+#             */
/*   Updated: 2021/03/19 07:34:44 by gpassos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_print	get_char(t_print print, int *counter, va_list args)
{
	t_print	saida;
	char	temp;
	int		i;

	saida = print;
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
	temp = va_arg(args, int);
	if (temp == 0 && 0)
	{
		saida.estado = END;
		return (saida);
	}
	else
		ft_pchar(temp, counter);
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
