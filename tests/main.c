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
	int a01;
	int a02;
	int a03;
	int a04;
	int a05;
	int a06;
	int a07;
	int a08;
	int a09;
	int a10;
	int a11;
	int a12;
	int a13;
	int a14;
	int a15;
	int a16;
	int a17;
	int a18;
	int a19;
	int a20;
	int a21;

	int verbose;
	verbose = 0;
	verbose = 1;

	printf   ("main: 48: '%70p%70p%70p%70p%70p%70p%70p%70p%70p%70p%70p%70p'\n",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12);
	ft_printf("main: 49: '%70p%70p%70p%70p%70p%70p%70p%70p%70p%70p%70p%70p'\n",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12);
	printf("\n");

	printf   ("main: 52: '%16p%16p%16p%16p%16p%16p%16p%16p%16p%16p%16p%16p'\n",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12);
	ft_printf("main: 53: '%16p%16p%16p%16p%16p%16p%16p%16p%16p%16p%16p%16p'\n",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12);
	printf("\n");

	printf   ("main: 56: '%32p%32p%32p%32p%32p%32p%32p%32p%32p%32p%32p%32p'\n",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12);
	ft_printf("main: 57: '%32p%32p%32p%32p%32p%32p%32p%32p%32p%32p%32p%32p'\n",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12);
	printf("\n");

	printf   ("main: 60: '%-70p%-70p%-70p%-70p%-70p%-70p%-70p%-70p%-70p%-70p%-70p%-70p'\n",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12);
	ft_printf("main: 61: '%-70p%-70p%-70p%-70p%-70p%-70p%-70p%-70p%-70p%-70p%-70p%-70p'\n",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12);
	printf("\n");

	printf   ("main: 64: '%-16p%-16p%-16p%-16p%-16p%-16p%-16p%-16p%-16p%-16p%-16p%-16p'\n",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12);
	ft_printf("main: 65: '%-16p%-16p%-16p%-16p%-16p%-16p%-16p%-16p%-16p%-16p%-16p%-16p'\n",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12);
	printf("\n");

	printf   ("main: 68: '%-32p%-32p%-32p%-32p%-32p%-32p%-32p%-32p%-32p%-32p%-32p%-32p'\n",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12);
	ft_printf("main: 69: '%-32p%-32p%-32p%-32p%-32p%-32p%-32p%-32p%-32p%-32p%-32p%-32p'\n",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12);
	printf("\n");

	return (0);
}
