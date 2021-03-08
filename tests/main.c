/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 08:31:12 by gabriel           #+#    #+#             */
/*   Updated: 2021/03/08 07:23:43 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../ft_printf.h"
#include "../libft/libft.h"

int main()
{

	printf   ("%d; %i; '%s'\n", 234, 351, "teste");
	ft_printf("%d; %i; '%s'\n", 234, 351, "teste");

	printf   ("%d; '%s'\n", 351, "teste");
	ft_printf("%d; '%s'\n", 351, "teste");

	printf   ("%05d; '%s'\n", 351, "teste");
	ft_printf("%05d; '%s'\n", /* 351, */ "teste");

	printf   ("float = '%f'\n", 3.51);
	ft_printf("float = '%f'\n", 3.51);


	// printf   ("%.1.'d\n", 835479);
	// printf   ("%010.1d %d\n", 123);
	return (0);
}
