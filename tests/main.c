/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 08:31:12 by gabriel           #+#    #+#             */
/*   Updated: 2021/03/12 11:35:27 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../ft_printf.h"
#include "../libft/libft.h"

int main()
{
	char	c = 'a';
	int		d = 2147483647;
	int		e = -2147483648;
	int		i = 8;
	int		j = -12;
	int		k = 123456789;
	int		l = 0;
	int		m = -12345678;

	int verbose;
	verbose = 0;
	verbose = 1;

	// if (verbose == 1) { printf   ("\n\"main: 27: %%d; %%i; '%%s'\\n\", 234, 351, \"teste1\"\n"); }
	// printf   ("main: 28: %d; %i; '%s'\n", 234, 351, "teste1");
	// ft_printf("main: 29: %d; %i; '%s'\n", 234, 351, "teste1");

	// if (verbose == 1) { printf   ("\n\"main: 31: %%d; '%%s'\\n\", 352, \"teste2\"\n"); }
	// printf   ("main: 32: %d; '%s'\n", 352, "teste2");
	// ft_printf("main: 33: %d; '%s'\n", 352, "teste2");

	// if (verbose == 1) { printf   ("\n\"main: 35: %%052d; '%%s'\\n\", 353, \"teste3\"\n"); }
	// printf   ("main: 36: %052d; '%s'\n", 353, "teste3");
	// ft_printf("main: 37: %052d; '%s'\n", 353, "teste3");

	// if (verbose == 1) { printf   ("\n\"main: 39: %%05d; '%%s'\\n\", 355, \"teste5\"\n"); }
	// printf   ("main: 40: %05d; '%s'\n", 355, "teste5");
	// ft_printf("main: 41: %05d; '%s'\n", 355, "teste5");

	// if (verbose == 1) { printf   ("\n\"main: 43: %%1.2d; '%%s'\\n\", 354, \"teste4\"\n"); }
	// printf   ("main: 44: %1.2d; '%s'\n", 354, "teste4");
	// ft_printf("main: 45: %1.2d; '%s'\n", 354, "teste4");

	// if (verbose == 1) { printf   ("\n\"main: 47: {%%10d}\\n\", 42\n"); }
	// printf   ("main: 48: {%10d}\n", 42);
	// ft_printf("main: 49: {%10d}\n", 42);

	// ft_printf("main: 93: %1i, %1d, %1d, %1d, %1d, %1d, %1d, %1d", i, j, k, l, m, c, e, d); //T4
	// printf("\n");
	if (verbose == 1) { printf   ("\"main: 61: unsined = %%u\\n\", 4294967284\n"); }
	printf   ("main: 62: unsined = %u\n", (unsigned)4294967284);
	ft_printf("main: 63: unsined = %u\n", (unsigned)4294967284);
	printf("\n");

	if (verbose == 1) { printf   ("\"main: 66: unsined = %%u\\n\", 4294967284\n"); }
	printf   ("main: 67: unsined = %u\n", (unsigned)4294967285);
	ft_printf("main: 68: unsined = %u\n", (unsigned)4294967285);
	printf("\n");

	if (verbose == 1) { printf   ("\"main: 71: hex1 = %%x\\n\", 100\n"); }
	printf   ("main: 72: hex1 = %x\n", 100);
	ft_printf("main: 73: hex1 = %x\n", 100);
	printf("\n");

	if (verbose == 1) { printf   ("\"main: 76: hex2 = %%x\\n\", 150\n"); }
	printf   ("main: 77: hex2 = %x\n", 150);
	ft_printf("main: 78: hex2 = %x\n", 150);
	printf("\n");

	if (verbose == 1) { printf   ("\"main: 81: hex3 = %%x\\n\", 1550\n"); }
	printf   ("main: 82: hex3 = %x\n", 1550);
	ft_printf("main: 83: hex3 = %x\n", 1550);
	printf("\n");

	if (verbose == 1) { printf   ("\"main: 86: hex3 = %%x\\n\", 1550\n"); }
	printf   ("main: 87: hex4 = %x\n", 8);
	ft_printf("main: 88: hex4 = %x\n", 8);
	printf("\n");

	if (verbose == 1) { printf   ("\"main: 106: hex3 = %%x\\n\", 1550\n"); }
	printf   ("main: 107: hex4 = %x\n", 1257);
	ft_printf("main: 108: hex4 = %x\n", 1257);
	printf("\n");

	if (verbose == 1) { printf   ("\"main: 111: hex3 = %%x\\n\", 1550\n"); }
	printf   ("main: 112: hex4 = %x\n", 6398);
	ft_printf("main: 113: hex4 = %x\n", 6398);
	printf("\n");

	if (verbose == 1) { printf   ("\"main: 106: hex3 = %%x\\n\", 1550\n"); }
	printf   ("main: 107: hex4 = %X\n", 1257);
	ft_printf("main: 108: hex4 = %X\n", 1257);
	printf("\n");

	if (verbose == 1) { printf   ("\"main: 111: hex3 = %%x\\n\", 1550\n"); }
	printf   ("main: 112: hex4 = %X\n", 6398);
	ft_printf("main: 113: hex4 = %X\n", 6398);
	printf("\n");

	return (0);
}
