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



	printf   ("main: 97: '{%*d}'\n", -5, 42);
	ft_printf("main: 98: '{%*d}'\n", -5, 42);
	printf("\n");

	printf   ("main: 101: '{%.*s}'\n", -5, "42");
	ft_printf("main: 102: '{%.*s}'\n", -5, "42");
	printf("\n");

	printf   ("main: 105: '{%05.*d}'\n", -15, 42);
	ft_printf("main: 106: '{%05.*d}'\n", -15, 42);
	printf("\n");

	printf   ("main: 109: 'neg1 %*s'\n", -9, "coucou");
	ft_printf("main: 110: 'neg1 %*s'\n", -9, "coucou");
	printf("\n");

	printf   ("main: 113: 'neg2 %*.*s'\n", -9, 4, "coucou");
	ft_printf("main: 114: 'neg2 %*.*s'\n", -9, 4, "coucou");
	printf("\n");

	printf   ("main: 117: 'neg3 %*s'\n", -9, NULL);
	ft_printf("main: 118: 'neg3 %*s'\n", -9, NULL);
	printf("\n");

	printf   ("main: 121: 'neg5 %*s'\n", -100, "coucou");
	ft_printf("main: 122: 'neg5 %*s'\n", -100, "coucou");
	printf("\n");





	printf   ("main: 129: '{%05.*d}'\n", -15, 42);
	ft_printf("main: 129: '{%05.*d}'\n", -15, 42);
	printf("\n");


	printf   ("main: 129: '%-66p%-90c%--*.69x%0045.*u'\n" ,(void*)9420165689360028937lu,-29,-122,174318236u,-127,2553740548u);
	ft_printf("main: 129: '%-66p%-90c%--*.69x%0045.*u'\n" ,(void*)9420165689360028937lu,-29,-122,174318236u,-127,2553740548u);
	printf("\n");


	printf   ("main: 129: '%-171.108s%0022.*u%-93.114u%*c'\n" ,"r>KM,cWZ,k7U",-75,1057557429u,580880397u,-25,-80);
	ft_printf("main: 129: '%-171.108s%0022.*u%-93.114u%*c'\n" ,"r>KM,cWZ,k7U",-75,1057557429u,580880397u,-25,-80);
	printf("\n");

	printf   ("main: 129: '%-12.*s%98.128s%--8p%095.*i%00182.193x'\n" ,139,"o=Z*[","9S14l$RgnTv`-Wm",(void*)3870843096944218592lu,-156,201214506,1134523837u);
	ft_printf("main: 129: '%-12.*s%98.128s%--8p%095.*i%00182.193x'\n" ,139,"o=Z*[","9S14l$RgnTv`-Wm",(void*)3870843096944218592lu,-156,201214506,1134523837u);
	printf("\n");




	while (a < 5) //T34-69
	{
		printf   ("a = %d\n", a);
		printf   ("%.*i, %.*d, %.*d, %.*d, %.*d, %.*d, %.*d, %.*d\n", a, i, a, j, a, k, a, l, a, m, a, c, a, e, a, d);
		ft_printf("%.*i, %.*d, %.*d, %.*d, %.*d, %.*d, %.*d, %.*d\n", a, i, a, j, a, k, a, l, a, m, a, c, a, e, a, d);
		a++;
	}

	printf("\n");
	printf("\n");

	printf   ("main: 159: 'this %i number'\n", 0);
	ft_printf("main: 160: 'this %i number'\n", 0);
	printf("\n");

	printf   ("main: 163: '%i'\n", 0);
	ft_printf("main: 164: '%i'\n", 0);
	printf("\n");

	printf   ("main: 167: 'this %d number'\n", 0);
	ft_printf("main: 168: 'this %d number'\n", 0);
	printf("\n");

	printf   ("main: 171: '%3i'\n", 0);
	ft_printf("main: 172: '%3i'\n", 0);
	printf("\n");

	printf   ("main: 175: '%-3i'\n", 0);
	ft_printf("main: 176: '%-3i'\n", 0);
	printf("\n");

	printf   ("main: 179: '%03i'\n", 0);
	ft_printf("main: 180: '%03i'\n", 0);
	printf("\n");

	printf   ("main: 183: '%5.0i'\n", 0);
	ft_printf("main: 184: '%5.0i'\n", 0);
	printf("\n");

	printf   ("main: 187: '%5.i'\n", 0);
	ft_printf("main: 188: '%5.i'\n", 0);
	printf("\n");

	printf   ("main: 191: '%-5.0i'\n", 0);
	ft_printf("main: 192: '%-5.0i'\n", 0);
	printf("\n");

	printf   ("main: 195: '%-5.i'\n", 0);
	ft_printf("main: 196: '%-5.i'\n", 0);
	printf("\n");

	printf   ("main: 199: '%d'\n", 0);
	ft_printf("main: 200: '%d'\n", 0);
	printf("\n");

	printf   ("main: 203: '%3d'\n", 0);
	ft_printf("main: 204: '%3d'\n", 0);
	printf("\n");

	printf   ("main: 207: '%-3d'\n", 0);
	ft_printf("main: 208: '%-3d'\n", 0);
	printf("\n");

	printf   ("main: 211: '%03d'\n", 0);
	ft_printf("main: 212: '%03d'\n", 0);
	printf("\n");

	printf   ("main: 215: '%5.0d'\n", 0);
	ft_printf("main: 216: '%5.0d'\n", 0);
	printf("\n");

	printf   ("main: 219: '%5.d'\n", 0);
	ft_printf("main: 220: '%5.d'\n", 0);
	printf("\n");

	printf   ("main: 223: '%-5.0d'\n", 0);
	ft_printf("main: 224: '%-5.0d'\n", 0);
	printf("\n");

	printf   ("main: 227: '%-5.d'\n", 0);
	ft_printf("main: 228: '%-5.d'\n", 0);
	printf("\n");

	printf   ("main: 231: '{%05.*d}'\n", -15, 42);
	ft_printf("main: 232: '{%05.*d}'\n", -15, 42);
	printf("\n");

	printf   ("main: 235: '32 This is an int : %0d\n\n'\n", 0);
	ft_printf("main: 236: '32 This is an int : %0d\n\n'\n", 0);
	printf("\n");

	printf   ("main: 239: 'st13 %*d\n'\n", 0, 0);
	ft_printf("main: 240: 'st13 %*d\n'\n", 0, 0);
	printf("\n");

	printf   ("main: 243: 'st118 %*d\n'\n", 100, 0);
	ft_printf("main: 244: 'st118 %*d\n'\n", 100, 0);
	printf("\n");

	printf   ("main: 247: 'ultimate1 %*d        %*i\n'\n", 500, 0, 10, 10);
	ft_printf("main: 248: 'ultimate1 %*d        %*i\n'\n", 500, 0, 10, 10);
	printf("\n");

	printf   ("main: 251: '%20.d'\n", 0);
	ft_printf("main: 252: '%20.d'\n", 0);
	printf("\n");

	printf   ("main: 255: '%20.i'\n", 0);
	ft_printf("main: 256: '%20.i'\n", 0);
	printf("\n");

	return (0);
}
