/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 08:31:12 by gabriel           #+#    #+#             */
/*   Updated: 2021/03/11 09:23:49 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../ft_printf.h"
#include "../libft/libft.h"

int main()
{
	// printf("%1.2d\n", 42);
	int verbose;
	verbose = 0;
	verbose = 1;

	if (verbose == 1) { printf   ("\nmain: 27: %%d; %%i; '%%s'\\n\", 234, 351, \"teste1\"\n"); }
	printf("retorno = %d; ", printf   ("main: 28: %d; %i; '%s'\n", 234, 351, "teste1"));
	printf("retorno = %d; ", ft_printf("main: 29: %d; %i; '%s'\n", 234, 351, "teste1"));

	if (verbose == 1) { printf   ("\nmain: 31: %%d; '%%s'\\n\", 352, \"teste2\"\n"); }
	printf("retorno = %d; ", printf   ("main: 32: %d; '%s'\n", 352, "teste2"));
	printf("retorno = %d; ", ft_printf("main: 33: %d; '%s'\n", 352, "teste2"));

	if (verbose == 1) { printf   ("\nmain: 35: %%052d; '%%s'\\n\", 353, \"teste3\"\n"); }
	printf("retorno = %d; ", printf   ("main: 36: %052d; '%s'\n", 353, "teste3"));
	printf("retorno = %d; ", ft_printf("main: 37: %052d; '%s'\n", 353, "teste3"));

	if (verbose == 1) { printf   ("\nmain: 39: %%05d; '%%s'\\n\", 355, \"teste5\"\n"); }
	printf("retorno = %d; ", printf   ("main: 40: %05d; '%s'\n", 355, "teste5"));
	printf("retorno = %d; ", ft_printf("main: 41: %05d; '%s'\n", 355, "teste5"));

	if (verbose == 1) { printf   ("\nmain: 43: %%1.2d; '%%s'\\n\", 354, \"teste4\"\n"); }
	printf("retorno = %d; ", printf   ("main: 44: %1.2d; '%s'\n", 354, "teste4"));
	printf("retorno = %d; ", ft_printf("main: 45: %1.2d; '%s'\n", 354, "teste4"));

	if (verbose == 1) { printf   ("\nmain: 47: {%%10d}\\n\", 42\n"); }
	printf("retorno = %d; ", printf   ("main: 48: {%10d}\n", 42));
	printf("retorno = %d; ", ft_printf("main: 49: {%10d}\n", 42));

	return (0);
}
