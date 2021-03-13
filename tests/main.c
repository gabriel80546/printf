/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 08:31:12 by gabriel           #+#    #+#             */
/*   Updated: 2021/03/13 11:55:53 by gabriel          ###   ########.fr       */
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

	// if (verbose == 1) { printf   ("\"%%%%\\n\"\n"); }
	// printf   ("%%\n");
	// ft_printf("%%\n");
	// printf("\n");

	// if (verbose == 1) { printf   ("\"%%5%%\\n\"\n"); }
	// printf   ("%5%\n");
	// ft_printf("%5%\n");
	// printf("\n");

	if (verbose == 1) { printf("\n"); }
	printf   ("main: 69: %32s\n", "abc");
	ft_printf("main: 69: %32s\n", "abc");
	printf("\n");
	
	if (verbose == 1) { printf("\n"); }
	printf   ("main: 69: %16s\n", "nark nark");
	ft_printf("main: 69: %16s\n", "nark nark");
	printf("\n");
	
	if (verbose == 1) { printf("\n"); }
	printf   ("main: 69: %-32s\n", "abc");
	ft_printf("main: 69: %-32s\n", "abc");
	printf("\n");
	
	if (verbose == 1) { printf("\n"); }
	printf   ("main: 69: %-16s\n", "nark nark");
	ft_printf("main: 69: %-16s\n", "nark nark");
	printf("\n");
	
	if (verbose == 1) { printf("\n"); }
	printf   ("main: 69: %.3s\n", "hello");
	ft_printf("main: 69: %.3s\n", "hello");
	printf("\n");
	
	if (verbose == 1) { printf("\n"); }
	printf   ("main: 69: %.s\n", "hello");
	ft_printf("main: 69: %.s\n", "hello");
	printf("\n");
	
	if (verbose == 1) { printf("\n"); }
	printf   ("main: 69: %.0s\n", "hello");
	ft_printf("main: 69: %.0s\n", "hello");
	printf("\n");
	


	return (0);
}
