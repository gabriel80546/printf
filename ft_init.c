/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpassos- <gpassos-@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 22:21:33 by gpassos-          #+#    #+#             */
/*   Updated: 2021/03/19 22:21:35 by gpassos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags	ft_init_flags(void)
{
	t_flags saida;

	saida.left_asteristic = 0;
	saida.right_asteristic = 0;
	saida.n_left_indf = 1;
	saida.n_right_indf = 1;
	saida.n_left = 0;
	saida.n_right = 0;
	saida.pad_zeros = 0;
	saida.minus = 0;
	saida.precision = 0;
	return (saida);
}
