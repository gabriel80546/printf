/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 08:31:12 by gabriel           #+#    #+#             */
/*   Updated: 2021/03/11 13:53:29 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../ft_printf.h"
#include "../libft/libft.h"

int main()
{




	int		a = -4;
	int		b = 0;
	char	c = 'a';
	int		d = 2147483647;
	int		e = -2147483648;
	int		f = 42;
	int		g = 25;
	int		h = 4200;
	int		i = 8;
	int		j = -12;
	int		k = 123456789;
	int		l = 0;
	int		m = -12345678;
	char	*n = "abcdefghijklmnop";
	char	*o = "-a";
	char	*p = "-12";
	char	*q = "0";
	char	*r = "%%";
	char	*s = "-2147483648";
	char	*t = "0x12345678";
	char	*u = "-0";





	// printf("%1.2d\n", 42);
	int verbose;
	verbose = 0;
	verbose = 1;

	if (verbose == 1) { printf   ("\n\"main: 27: %%d; %%i; '%%s'\\n\", 234, 351, \"teste1\"\n"); }
	printf   ("main: 28: %d; %i; '%s'\n", 234, 351, "teste1");
	ft_printf("main: 29: %d; %i; '%s'\n", 234, 351, "teste1");

	if (verbose == 1) { printf   ("\n\"main: 31: %%d; '%%s'\\n\", 352, \"teste2\"\n"); }
	printf   ("main: 32: %d; '%s'\n", 352, "teste2");
	ft_printf("main: 33: %d; '%s'\n", 352, "teste2");

	if (verbose == 1) { printf   ("\n\"main: 35: %%052d; '%%s'\\n\", 353, \"teste3\"\n"); }
	printf   ("main: 36: %052d; '%s'\n", 353, "teste3");
	ft_printf("main: 37: %052d; '%s'\n", 353, "teste3");

	if (verbose == 1) { printf   ("\n\"main: 39: %%05d; '%%s'\\n\", 355, \"teste5\"\n"); }
	printf   ("main: 40: %05d; '%s'\n", 355, "teste5");
	ft_printf("main: 41: %05d; '%s'\n", 355, "teste5");

	if (verbose == 1) { printf   ("\n\"main: 43: %%1.2d; '%%s'\\n\", 354, \"teste4\"\n"); }
	printf   ("main: 44: %1.2d; '%s'\n", 354, "teste4");
	ft_printf("main: 45: %1.2d; '%s'\n", 354, "teste4");

	if (verbose == 1) { printf   ("\n\"main: 47: {%%10d}\\n\", 42\n"); }
	printf   ("main: 48: {%10d}\n", 42);
	ft_printf("main: 49: {%10d}\n", 42);

	// if (verbose == 1) { printf   ("\n\"main: 51: %%d\\n\", 2147483647\n"); }
	// printf   ("main: 52: %d\n", d);
	// ft_printf("main: 53: %d\n", d);

	// // printf("Simple input test"));
	// // printf("%i, %d, %d, %d, %d, %s, %c, %d, %u, %x, %X", i, j, k, l, m, n, c, c, j, j, j)); //T2
	// if (verbose == 1) { printf   ("\n\"main: 87: %%0i, %%0d, %%0d, %%0d, %%0d, %%0d, %%0d, %%0d\\n\", i, j, k, l, m, c, e, d\n"); } //T3
	// printf   ("main: 88: %0i, %0d, %0d, %0d, %0d, %0d, %0d, %0d\n", i, j, k, l, m, c, e, d); //T3
	// ft_printf("main: 89: %0i, %0d, %0d, %0d, %0d, %0d, %0d, %0d\n", i, j, k, l, m, c, e, d); //T3

	// if (verbose == 1) { printf   ("\n\"main: 91: %%1i, %%1d, %%1d, %%1d, %%1d, %%1d, %%1d, %%1d\\n\", i, j, k, l, m, c, e, d\n"); } //T4
	// printf   ("main: 92: %1i, %1d, %1d, %1d, %1d, %1d, %1d, %1d", i, j, k, l, m, c, e, d); //T4
	ft_printf("main: 93: %1i, %1d, %1d, %1d, %1d, %1d, %1d, %1d", i, j, k, l, m, c, e, d); //T4



	printf   ("\nteste: %-32s\n", NULL);
	ft_printf("teste: %-32s\n", NULL);

	printf   ("\nteste: %-16s\n", NULL);
	ft_printf("teste: %-16s\n", NULL);

	printf   ("\nteste: %.03s\n", NULL);
	ft_printf("teste: %.03s\n", NULL);

	printf   ("\nteste: %3.s\n", NULL);
	ft_printf("teste: %3.s\n", NULL);

	printf   ("\nteste: %10.s\n", NULL);
	ft_printf("teste: %10.s\n", NULL);

	printf   ("\nteste: %-3.s\n", NULL);
	ft_printf("teste: %-3.s\n", NULL);

	printf   ("\nteste: %-8.s\n", NULL);
	ft_printf("teste: %-8.s\n", NULL);

	printf   ("\nteste: %3.1s\n", NULL);
	ft_printf("teste: %3.1s\n", NULL);

	printf   ("\nteste: %9.1s\n", NULL);
	ft_printf("teste: %9.1s\n", NULL);

	printf   ("\nteste: %-3.1s\n", NULL);
	ft_printf("teste: %-3.1s\n", NULL);

	printf   ("\nteste: %-9.1s\n", NULL);
	ft_printf("teste: %-9.1s\n", NULL);

	printf   ("\nteste: %-10.8s\n", NULL);
	ft_printf("teste: %-10.8s\n", NULL);


	printf   ("\nteste: %23s\n", NULL);
	ft_printf("teste: %23s\n", NULL);
	
	printf   ("\nteste: %.s\n", NULL);
	ft_printf("teste: %.s\n", NULL);
	
	printf   ("\nteste: %32s\n", NULL);
	ft_printf("teste: %32s\n", NULL);
	
	printf   ("\nteste: %-32s\n", NULL);
	ft_printf("teste: %-32s\n", NULL);
	
	printf   ("\nteste: %-16s\n", NULL);
	ft_printf("teste: %-16s\n", NULL);
	
	printf   ("\nteste: %.03s\n", NULL);
	ft_printf("teste: %.03s\n", NULL);
	
	printf   ("\nteste: %3.s\n", NULL);
	ft_printf("teste: %3.s\n", NULL);
	
	printf   ("\nteste: %10.s\n", NULL);
	ft_printf("teste: %10.s\n", NULL);
	
	printf   ("\nteste: %-3.s\n", NULL);
	ft_printf("teste: %-3.s\n", NULL);
	
	printf   ("\nteste: %-8.s\n", NULL);
	ft_printf("teste: %-8.s\n", NULL);
	
	printf   ("\nteste: %3.1s\n", NULL);
	ft_printf("teste: %3.1s\n", NULL);
	
	printf   ("\nteste: %9.1s\n", NULL);
	ft_printf("teste: %9.1s\n", NULL);
	
	printf   ("\nteste: %-3.1s\n", NULL);
	ft_printf("teste: %-3.1s\n", NULL);
	
	printf   ("\nteste: %-9.1s\n", NULL);
	ft_printf("teste: %-9.1s\n", NULL);
	
	printf   ("\nteste: %20.6s\n", NULL);
	ft_printf("teste: %20.6s\n", NULL);
	
	printf   ("\nteste: %-10.8s\n", NULL);
	ft_printf("teste: %-10.8s\n", NULL);
	
	printf   ("\nteste: p3 %.4s\n\n", NULL);
	ft_printf("teste: p3 %.4s\n\n", NULL);
	
	printf("#######################################\n");
	printf("################teste 3################\n");
	printf("#######################################\n");

	printf   ("\nteste: %23s\n", NULL);
	ft_printf("teste: %23s\n", NULL);
	
	printf   ("\nteste: %32s\n", NULL);
	ft_printf("teste: %32s\n", NULL);
	
	printf   ("\nteste: %-32s\n", NULL);
	ft_printf("teste: %-32s\n", NULL);
	
	printf   ("\nteste: %-16s\n", NULL);
	ft_printf("teste: %-16s\n", NULL);
	
	printf   ("\nteste: %3.s\n", NULL);
	ft_printf("teste: %3.s\n", NULL);
	
	printf   ("\nteste: %10.s\n", NULL);
	ft_printf("teste: %10.s\n", NULL);
	
	printf   ("\nteste: %-3.s\n", NULL);
	ft_printf("teste: %-3.s\n", NULL);
	
	printf   ("\nteste: %-8.s\n", NULL);
	ft_printf("teste: %-8.s\n", NULL);
	
	printf   ("\nteste: %3.1s\n", NULL);
	ft_printf("teste: %3.1s\n", NULL);
	
	printf   ("\nteste: %9.1s\n", NULL);
	ft_printf("teste: %9.1s\n", NULL);
	
	printf   ("\nteste: %-3.1s\n", NULL);
	ft_printf("teste: %-3.1s\n", NULL);
	
	printf   ("\nteste: %-9.1s\n", NULL);
	ft_printf("teste: %-9.1s\n", NULL);
	
	printf   ("\nteste: %20.6s\n", NULL);
	ft_printf("teste: %20.6s\n", NULL);
	
	printf   ("\nteste: %-10.8s\n", NULL);
	ft_printf("teste: %-10.8s\n", NULL);
	

	printf("#######################################\n");
	printf("################teste 4################\n");
	printf("#######################################\n");


	printf   ("\nteste: %3.s\n", NULL);
	ft_printf("teste: %3.s\n", NULL);
	
	printf   ("\nteste: %10.s\n", NULL);
	ft_printf("teste: %10.s\n", NULL);
	
	printf   ("\nteste: %-3.s\n", NULL);
	ft_printf("teste: %-3.s\n", NULL);
	
	printf   ("\nteste: %-8.s\n", NULL);
	ft_printf("teste: %-8.s\n", NULL);
	
	printf   ("\nteste: %3.1s\n", NULL);
	ft_printf("teste: %3.1s\n", NULL);
	
	printf   ("\nteste: %9.1s\n", NULL);
	ft_printf("teste: %9.1s\n", NULL);
	
	printf   ("\nteste: %-3.1s\n", NULL);
	ft_printf("teste: %-3.1s\n", NULL);
	
	printf   ("\nteste: %-9.1s\n", NULL);
	ft_printf("teste: %-9.1s\n", NULL);
	
	printf   ("\nteste: %50.2s\n", NULL);
	ft_printf("teste: %50.2s\n", NULL);
	

	return (0);
}
