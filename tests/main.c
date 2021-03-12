/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 08:31:12 by gabriel           #+#    #+#             */
/*   Updated: 2021/03/12 13:05:26 by gabriel          ###   ########.fr       */
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

	printf   ("main: 59: %1i, %1d, %1d, %1d, %1d, %1d, %1d, %1d\n", i, j, k, l, m, c, e, d); //T4
	ft_printf("main: 60: %1i, %1d, %1d, %1d, %1d, %1d, %1d, %1d\n", i, j, k, l, m, c, e, d); //T4
	printf("\n");

	printf   ("main: 63: %i, %d, %d, %d, %d, %s, %c, %d, %u, %x, %X\n", 8, -12, 123456789, 0, -12345678, "abcdefghijklmnop", 'a', 97, (unsigned)4294967284, 0xfffffff4, 0xFFFFFFF4);
	ft_printf("main: 64: %i, %d, %d, %d, %d, %s, %c, %d, %u, %x, %X\n", 8, -12, 123456789, 0, -12345678, "abcdefghijklmnop", 'a', 97, (unsigned)4294967284, 0xfffffff4, 0xFFFFFFF4);
	printf("\n");

// 1c1
// < 8, -12, 123456789, 0, -12345678, abcdefghijklmnop, c, 97, 97, fffffff4, X --- Return : 73
// ---
// > 8, -12, 123456789, 0, -12345678, abcdefghijklmnop, a, 97, 4294967284, fffffff4, FFFFFFF4 --- Return : 88


	// printf("\n");
	if (verbose == 1) { printf   ("\"main: 74: unsined = %%u\\n\", 4294967284\n"); }
	printf   ("main: 75: unsined = %u\n", (unsigned)4294967284);
	ft_printf("main: 76: unsined = %u\n", (unsigned)4294967284);
	printf("\n");

	if (verbose == 1) { printf   ("\"main: 79: unsined = %%u\\n\", 4294967284\n"); }
	printf   ("main: 80: unsined = %u\n", (unsigned)4294967285);
	ft_printf("main: 81: unsined = %u\n", (unsigned)4294967285);
	printf("\n");

	// if (verbose == 1) { printf   ("\"main: 71: hex1 = %%x\\n\", 100\n"); }
	// printf   ("main: 72: hex1 = %x\n", 100);
	// ft_printf("main: 73: hex1 = %x\n", 100);
	// printf("\n");

	// if (verbose == 1) { printf   ("\"main: 76: hex2 = %%x\\n\", 150\n"); }
	// printf   ("main: 77: hex2 = %x\n", 150);
	// ft_printf("main: 78: hex2 = %x\n", 150);
	// printf("\n");

	// if (verbose == 1) { printf   ("\"main: 81: hex3 = %%x\\n\", 1550\n"); }
	// printf   ("main: 82: hex3 = %x\n", 1550);
	// ft_printf("main: 83: hex3 = %x\n", 1550);
	// printf("\n");

	// if (verbose == 1) { printf   ("\"main: 86: hex3 = %%x\\n\", 1550\n"); }
	// printf   ("main: 87: hex4 = %x\n", 8);
	// ft_printf("main: 88: hex4 = %x\n", 8);
	// printf("\n");

	// if (verbose == 1) { printf   ("\"main: 106: hex3 = %%x\\n\", 1550\n"); }
	// printf   ("main: 107: hex4 = %x\n", 1257);
	// ft_printf("main: 108: hex4 = %x\n", 1257);
	// printf("\n");

	// if (verbose == 1) { printf   ("\"main: 111: hex3 = %%x\\n\", 1550\n"); }
	// printf   ("main: 112: hex4 = %x\n", 6398);
	// ft_printf("main: 113: hex4 = %x\n", 6398);
	// printf("\n");

	// if (verbose == 1) { printf   ("\"main: 106: hex3 = %%x\\n\", 1550\n"); }
	// printf   ("main: 107: hex4 = %X\n", 1257);
	// ft_printf("main: 108: hex4 = %X\n", 1257);
	// printf("\n");

	// if (verbose == 1) { printf   ("\"main: 111: hex3 = %%x\\n\", 1550\n"); }
	// printf   ("main: 112: hex4 = %X\n", 6398);
	// ft_printf("main: 113: hex4 = %X\n", 6398);
	// printf("\n");
	if (verbose == 1) { printf   ("main: 123: \"%%s%%s\\n\", \"hello\", \"world\"\n"); }
	printf   ("main: 124: %s%s\n", "hello", "world");
	ft_printf("main: 125: %s%s\n", "hello", "world");
	printf("\n");

	if (verbose == 1) { printf   ("main: 123: \"%%s%%s\\n\", \"hello\", \"world\"\n"); }
	printf   ("main: 124: %s%s\n", "hello", "world");
	ft_printf("main: 125: %s%s\n", "hello", "world");
	printf("\n");

	if (verbose == 1) { printf   ("main: 123: \"%%s%%s\\n\", \"hello\", \"world\"\n"); }
	printf   ("main: 124: %p %p\n", "hello", "world");
	ft_printf("main: 125: %p %p\n", "hello", "world");
	printf("\n");
	return (0);
}
