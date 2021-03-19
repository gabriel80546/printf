/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpassos- <gpassos-@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 07:34:39 by gpassos-          #+#    #+#             */
/*   Updated: 2021/03/19 07:34:40 by gpassos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_pchar(char caracter, int *counter)
{
	write(1, &caracter, 1);
	*counter = *counter + 1;
}

void	ft_pstr(char *string, int *counter)
{
	ft_putstr_fd(string, 1);
	*counter = *counter + ft_strlen(string);
}

void	ft_pnchar(char caracter, int n, int *counter)
{
	int i;

	i = 0;
	while (i < n)
	{
		ft_pchar(caracter, counter);
		i++;
	}
}
