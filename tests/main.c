/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 08:31:12 by gabriel           #+#    #+#             */
/*   Updated: 2021/03/08 08:24:46 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../ft_printf.h"
#include "../libft/libft.h"

int main()
{

	printf   ("23: %d; %i; '%s'\n", 234, 351, "teste");
	ft_printf("24: %d; %i; '%s'\n", 234, 351, "teste");

	printf   ("26: %d; '%s'\n", 351, "teste");
	ft_printf("27: %d; '%s'\n", 351, "teste");

	printf   ("29: %05d; '%s'\n", 351, "teste");
	ft_printf("30: %05d; '%s'\n", 351, "teste");

	printf   ("32: %00000000000005d; '%s'\n", 351, "teste");
	ft_printf("33: %00000000000005d; '%s'\n", 351, "teste");

	printf   ("35: %1.2d; '%s'\n", 351, "teste");
	ft_printf("36: %1.2d; '%s'\n", /* 351, */ "teste");

	printf   ("38: %1...............2d; '%s'\n", /* 351, */ "teste");
	ft_printf("39: %1...............2d; '%s'\n", /* 351, */ "teste");

	printf   ("41: %05d; '%s'\n", 351, "teste");
	ft_printf("42: %05d; '%s'\n", 351, "teste");

	printf   ("44: float = '%f'\n", 3.51);
	ft_printf("45: float = '%f'\n", 3.51);
	return (0);
}
