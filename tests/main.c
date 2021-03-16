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

	return (0);
}
