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

	printf   ("main: 27: '%-5c'\n", '\0');
	ft_printf("main: 27: '%-5c'\n", '\0');
	printf   ("main: 28: '{%3c}'\n", 0);
	ft_printf("main: 28: '{%3c}'\n", 0);



	printf   ("%*d\n", 5, 42);
	ft_printf("%*d\n", 5, 42);
	printf("\n");

	printf   ("{%*d}\n", -5, 42);
	ft_printf("{%*d}\n", -5, 42);
	printf("\n");

	printf   ("{%*d}\n", 0, 42);
	ft_printf("{%*d}\n", 0, 42);
	printf("\n");

	printf   ("{%*c}\n", 0, 0);
	ft_printf("{%*c}\n", 0, 0);
	printf("\n");

	printf   ("{%*c}\n", -15, 0);
	ft_printf("{%*c}\n", -15, 0);
	printf("\n");

	printf   ("{%.*d}\n", 5, 42);
	ft_printf("{%.*d}\n", 5, 42);
	printf("\n");

	printf   ("{%.*d}\n", -5, 42);
	ft_printf("{%.*d}\n", -5, 42);
	printf("\n");

	printf   ("{%.*d}\n", 0, 42);
	ft_printf("{%.*d}\n", 0, 42);
	printf("\n");

	return (0);
}
