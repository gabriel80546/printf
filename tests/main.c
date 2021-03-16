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



	printf   ("{%3c}\n", 0);
	ft_printf("{%3c}\n", 0);
	printf("\n");

	printf   ("{%*c}\n", 0, 0);
	ft_printf("{%*c}\n", 0, 0);
	printf("\n");

	printf   ("{%*c}\n", -15, 0);
	ft_printf("{%*c}\n", -15, 0);
	printf("\n");

	printf   ("main: 59: '%---34c%-107.*u'\n" ,7,-168,2003619509u);
	ft_printf("main: 60: '%---34c%-107.*u'\n" ,7,-168,2003619509u);
	printf("\n");

	printf   ("main: 61: '%-190.*u%--6.26X%156.96s'\n" ,-109,3830289361u,1359348041u,"p@.CbB<\\?d");
	ft_printf("main: 62: '%-190.*u%--6.26X%156.96s'\n" ,-109,3830289361u,1359348041u,"p@.CbB<\\?d");
	printf("\n");


	return (0);
}
