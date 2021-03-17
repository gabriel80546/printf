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







	printf("*******************************************************\n");
	printf("************************* main ************************\n");
	printf("*******************************************************\n");
	printf("\n");

	printf("\n");

	printf   ("\"'%%.p'\", NULL\n");
	printf   ("'0x'\n", NULL);
	ft_printf("'%.p'\n", NULL);
	printf("\n");

	printf   ("\"'%%1.p'\", NULL\n");
	printf   ("'0x'\n", NULL);
	ft_printf("'%1.p'\n", NULL);
	printf("\n");

	printf   ("\"'%%5.p'\", NULL\n");
	printf   ("'   0x'\n", NULL);
	ft_printf("'%5.p'\n", NULL);
	printf("\n");

	printf   ("\"'-->|%%-16.p|<-- '\", NULL\n");
	printf   ("'-->|0x              |<-- '\n", NULL);
	ft_printf("'-->|%-16.p|<-- '\n", NULL);
	printf("\n");


	ft_printf("main: 50: '%15p'\n", NULL);
	printf   ("main: 50: '            0x0'\n");
	ft_printf("main: 50: '%15p'\n", NULL);
	printf("\n");

	ft_printf("main: 50: '%-15p'\n", NULL);
	printf   ("main: 50: '0x0            '\n");
	ft_printf("main: 50: '%-15p'\n", NULL);
	printf("\n");



	while (a < 5) //T34-69
	{
		printf   ("a = %d\n", a);
		printf   ("%.*i, %.*d, %.*d, %.*d, %.*d, %.*d, %.*d, %.*d\n", a, i, a, j, a, k, a, l, a, m, a, c, a, e, a, d);
		ft_printf("%.*i, %.*d, %.*d, %.*d, %.*d, %.*d, %.*d, %.*d\n", a, i, a, j, a, k, a, l, a, m, a, c, a, e, a, d);
		a++;
	}


	return (0);
}
