/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 08:31:12 by gabriel           #+#    #+#             */
/*   Updated: 2021/03/13 14:26:11 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../ft_printf.h"
#include "../libft/libft.h"

int main()
{

	int verbose;
	verbose = 0;
	verbose = 1;

	printf   ("{%05.*d}\n", -15, 42);
	ft_printf("{%05.*d}\n", -15, 42);
	printf("\n");

	printf   ("{%.*d}\n", -5, 42);
	ft_printf("{%.*d}\n", -5, 42);
	printf("\n");

	printf   ("{%.*s}\n", -5, "42");
	ft_printf("{%.*s}\n", -5, "42");
	printf("\n");

	return (0);
}
