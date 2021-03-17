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


	printf("*******************************************************\n");
	printf("************************* main ************************\n");
	printf("*******************************************************\n");
	printf("\n");

	if (verbose == 1) { printf   ("\"main: 27: '%%---34c%%-107.*u'\\n\" ,7,-168,2003619509u\n"); }
	printf   ("main: 28: '%---34c%-107.*u'\n" ,7,-168,2003619509u);
	ft_printf("main: 29: '%---34c%-107.*u'\n" ,7,-168,2003619509u);
	printf("\n");

	if (verbose == 1) { printf   ("\"main: 32: '%%-190.*u%%--6.26X%$156.96s'\\n\" ,-109,3830289361u,1359348041u,\"p@.CbB<\\?d\"\n"); }
	printf   ("main: 33: '%-190.*u%--6.26X%156.96s'\n" ,-109,3830289361u,1359348041u,"p@.CbB<\\?d");
	ft_printf("main: 34: '%-190.*u%--6.26X%156.96s'\n" ,-109,3830289361u,1359348041u,"p@.CbB<\\?d");
	printf("\n");

	printf("\n");

	if (verbose == 1) { printf   ("\"main: 39: {%%05.*d}\\n\", -15, 42\n"); }
	printf   ("main: 40: {%05.*d}\n", -15, 42);
	ft_printf("main: 41: {%05.*d}\n", -15, 42);
	printf("\n");

	if (verbose == 1) { printf   ("\"main: 44: {%%.*d}\\n\", -5, 42\n"); }
	printf   ("main: 45: {%.*d}\n", -5, 42);
	ft_printf("main: 46: {%.*d}\n", -5, 42);
	printf("\n");

	if (verbose == 1) { printf   ("\"main: 49: {%%.*s}\\n\", -5, \"42\"\n"); }
	printf   ("main: 50: {%.*s}\n", -5, "42");
	ft_printf("main: 51: {%.*s}\n", -5, "42");
	printf("\n");

	printf   ("main: 54: neg9 '%*.*d'\n", 158, 155, -3000);
	ft_printf("main: 55: neg9 '%*.*d'\n", 158, 155, -3000);
	printf("\n");

	printf   ("main: 58: neg10 '%*.*d'\n", -155, 15, 150);
	ft_printf("main: 59: neg10 '%*.*d'\n", -155, 15, 150);
	printf("\n");

	printf   ("main: 62: neg11 '%*.*d'\n", -155, 15, 0);
	ft_printf("main: 63: neg11 '%*.*d'\n", -155, 15, 0);
	printf("\n");


	printf   ("saida = %d\n", printf   ("Hello World\n"));
	ft_printf("saida = %d\n", ft_printf("Hello World\n"));


//	printf   ("{%3c}\n", 0);
//	ft_printf("{%3c}\n", 0);
//	printf("\n");
//	
//	printf   ("{%*c}\n", 0, 0);
//	ft_printf("{%*c}\n", 0, 0);
//	printf("\n");
//	
//	printf   ("{%*c}\n", -15, 0);
//	ft_printf("{%*c}\n", -15, 0);
//	printf("\n");

	return (0);
}
