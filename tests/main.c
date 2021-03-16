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

	if (verbose == 1) { printf   ("\"main: 27: '%%7x'\\n\", 33\n"); }
	printf   ("main: 28: '%7x'\n", 33);
	ft_printf("main: 29: '%7x'\n", 33);
	printf("\n");

	if (verbose == 1) { printf   ("\"main: 32: '%%3x'\\n\", 0\n"); }
	printf   ("main: 33: '%3x'\n", 0);
	ft_printf("main: 34: '%3x'\n", 0);
	printf("\n");

	if (verbose == 1) { printf   ("\"main: 37: '%%5x'\\n\", 52625\n"); }
	printf   ("main: 38: '%5x'\n", 52625);
	ft_printf("main: 39: '%5x'\n", 52625);
	printf("\n");

	if (verbose == 1) { printf   ("\"main: 42: '%%-7x'\\n\", 33\n"); }
	printf   ("main: 43: '%-7x'\n", 33);
	ft_printf("main: 44: '%-7x'\n", 33);
	printf("\n");

	if (verbose == 1) { printf   ("\"main: 47: '%%-3x'\\n\", 0\n"); }
	printf   ("main: 48: '%-3x'\n", 0);
	ft_printf("main: 49: '%-3x'\n", 0);
	printf("\n");

	if (verbose == 1) { printf   ("\"main: 52: '%%-5x'\\n\", 52625\n"); }
	printf   ("main: 53: '%-5x'\n", 52625);
	ft_printf("main: 54: '%-5x'\n", 52625);
	printf("\n");

	if (verbose == 1) { printf   ("\"main: 57: '%%.5x'\\n\", 21\n"); }
	printf   ("main: 58: '%.5x'\n", 21);
	ft_printf("main: 59: '%.5x'\n", 21);
	printf("\n");

	if (verbose == 1) { printf   ("\"main: 62: '%%.3x'\\n\", 0\n"); }
	printf   ("main: 63: '%.3x'\n", 0);
	ft_printf("main: 64: '%.3x'\n", 0);
	printf("\n");

	if (verbose == 1) { printf   ("\"main: 67: '%%8.5x'\\n\", 34\n"); }
	printf   ("main: 68: '%8.5x'\n", 34);
	ft_printf("main: 69: '%8.5x'\n", 34);
	printf("\n");

	if (verbose == 1) { printf   ("\"main: 72: '%%8.5x'\\n\", 0\n"); }
	printf   ("main: 73: '%8.5x'\n", 0);
	ft_printf("main: 74: '%8.5x'\n", 0);
	printf("\n");

	if (verbose == 1) { printf   ("\"main: 77: '%%8.3x'\\n\", 8375\n"); }
	printf   ("main: 78: '%8.3x'\n", 8375);
	ft_printf("main: 79: '%8.3x'\n", 8375);
	printf("\n");

	if (verbose == 1) { printf   ("\"main: 82: '%%2.7x'\\n\", 3267\n"); }
	printf   ("main: 83: '%2.7x'\n", 3267);
	ft_printf("main: 84: '%2.7x'\n", 3267);
	printf("\n");

	return (0);
}
