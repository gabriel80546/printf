/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 08:31:12 by gabriel           #+#    #+#             */
/*   Updated: 2021/03/10 11:15:29 by gabriel          ###   ########.fr       */
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
	verbose = 1;
	verbose = 0;

	if (verbose == 1) { printf   ("main: 27: %%d; %%i; '%%s'\\n\", 234, 351, \"teste1\"\n"); }
	printf   ("main: 28: %d; %i; '%s'\n", 234, 351, "teste1");
	ft_printf("main: 29: %d; %i; '%s'\n", 234, 351, "teste1");

	if (verbose == 1) { printf   ("main: 31: %%d; '%%s'\\n\", 352, \"teste2\"\n"); }
	printf   ("main: 32: %d; '%s'\n", 352, "teste2");
	ft_printf("main: 33: %d; '%s'\n", 352, "teste2");

	if (verbose == 1) { printf   ("main: 35: %%052d; '%%s'\\n\", 353, \"teste3\"\n"); }
	printf   ("main: 36: %052d; '%s'\n", 353, "teste3");
	ft_printf("main: 37: %052d; '%s'\n", 353, "teste3");

	if (verbose == 1) { printf   ("main: 39: %%05d; '%%s'\\n\", 355, \"teste5\"\n"); }
	printf   ("main: 40: %05d; '%s'\n", 355, "teste5");
	ft_printf("main: 41: %05d; '%s'\n", 355, "teste5");

	if (verbose == 1) { printf   ("main: 43: %%1.2d; '%%s'\\n\", 354, \"teste4\"\n"); }
	printf   ("main: 44: %1.2d; '%s'\n", 354, "teste4");
	ft_printf("main: 45: %1.2d; '%s'\n", 354, "teste4");

	// printf   ("32: %*.2d; '%s'\n", 354, "teste4");
	// ft_printf("33: %*.2d; '%s'\n", 354, "teste4");

	// printf   ("32: %1.*d; '%s'\n", 354, "teste4");
	// ft_printf("33: %1.*d; '%s'\n", 354, "teste4");

	// printf   ("48: float = '%f'\n", 3.56);
	// ft_printf("49: float = '%f'\n", 3.56);
	return (0);
}
