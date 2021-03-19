/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_str.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpassos- <gpassos-@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 07:35:06 by gpassos-          #+#    #+#             */
/*   Updated: 2021/03/19 07:35:08 by gpassos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_print	get_str(t_print print, int *counter, va_list args)
{
	t_print	saida;
	char	*temp;
	int		tamanho;
	int		i;

	saida = print;
	temp = va_arg(args, char*);
	if (temp == NULL)
		temp = "(null)";
	if (saida.flags.precision == 1 && saida.flags.n_right >= 0)
		temp = ft_substr(temp, 0, saida.flags.n_right);
	else if (saida.flags.precision == 1 && saida.flags.n_right < 0)
		temp = ft_substr(temp, 0, ft_strlen(temp));
	else if (saida.flags.precision == 1)
		temp = "";
	if (saida.flags.n_left >= 0 && saida.flags.minus == 0)
	{
		i = 0;
		tamanho = ft_strlen(temp);
		while (i < (saida.flags.n_left - tamanho))
		{
			if (saida.flags.pad_zeros == 1)
				ft_pchar('0', counter);
			else
				ft_pchar(' ', counter);
			i++;
		}
	}
	ft_pstr(temp, counter);
	if (saida.flags.n_left >= 0 && saida.flags.minus == 1)
	{
		i = 0;
		tamanho = ft_strlen(temp);
		while (i < (saida.flags.n_left - tamanho))
		{
			ft_pchar(' ', counter);
			i++;
		}
	}
	if (saida.flags.precision == 1)
		free(temp);
	saida.estado = UNTIL_PERCENT;
	return (saida);
}
