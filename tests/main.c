/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 08:31:12 by gabriel           #+#    #+#             */
/*   Updated: 2021/03/09 10:31:43 by gabriel          ###   ########.fr       */
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
	printf   ("23: %d; %i; '%s'\n", 234, 351, "teste1");
	ft_printf("24: %d; %i; '%s'\n", 234, 351, "teste1");

	printf   ("26: %d; '%s'\n", 352, "teste2");
	ft_printf("27: %d; '%s'\n", 352, "teste2");

	printf   ("29: %05d; '%s'\n", 353, "teste3");
	ft_printf("30: %05d; '%s'\n", 353, "teste3");

	printf   ("32: %1.2d; '%s'\n", 354, "teste4");
	ft_printf("33: %1.2d; '%s'\n", 354, "teste4");

	printf   ("45: %05d; '%s'\n", 355, "teste5");
	ft_printf("46: %05d; '%s'\n", 355, "teste5");

	printf   ("48: float = '%f'\n", 3.56);
	ft_printf("49: float = '%f'\n", 3.56);
	return (0);
}
