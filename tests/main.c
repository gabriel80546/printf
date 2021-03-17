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


	printf   ("main: 50: '            0x0'\n");
	ft_printf("main: 50: '%15p'\n", NULL);
	printf("\n");

	printf   ("main: 50: '0x0            '\n");
	ft_printf("main: 50: '%-15p'\n", NULL);
	printf("\n");














	return (0);
}
