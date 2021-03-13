/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 08:31:12 by gabriel           #+#    #+#             */
/*   Updated: 2021/03/13 13:00:36 by gabriel          ###   ########.fr       */
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

	if (verbose == 1) { printf   ("\"main: 26: %%7.5s\\n\", \"yolo\"\n"); }
	printf   ("main: 27: '%7.5s'\n", "yolo");
	ft_printf("main: 28: '%7.5s'\n", "yolo");
	printf("\n");
	
	if (verbose == 1) { printf   ("\"main: 31: %%7.5s\\n\", \"bombastic\"\n"); }
	printf   ("main: 32: '%7.5s'\n", "bombastic");
	ft_printf("main: 33: '%7.5s'\n", "bombastic");
	printf("\n");
	
	if (verbose == 1) { printf   ("\"main: 36: %%-7.5s\\n\", \"yolo\"\n"); }
	printf   ("main: 37: '%-7.5s'\n", "yolo");
	ft_printf("main: 38: '%-7.5s'\n", "yolo");
	printf("\n");
	
	if (verbose == 1) { printf   ("\"main: 41: %%-7.5s\\n\", \"tubular\"\n"); }
	printf   ("main: 42: '%-7.5s'\n", "tubular");
	ft_printf("main: 43: '%-7.5s'\n", "tubular");
	printf("\n");
	
	if (verbose == 1) { printf   ("\"main: 46: %%7.7s%%7.7s\\n\", \"hello\", \"world\"\n"); }
	printf   ("main: 47: '%7.7s%7.7s'\n", "hello", "world");
	ft_printf("main: 48: '%7.7s%7.7s'\n", "hello", "world");
	printf("\n");
	
	if (verbose == 1) { printf   ("\"main: 51: %%3.7s%%7.7s\\n\", \"hello\", \"world\"\n"); }
	printf   ("main: 52: '%3.7s%7.7s'\n", "hello", "world");
	ft_printf("main: 53: '%3.7s%7.7s'\n", "hello", "world");
	printf("\n");
	
	if (verbose == 1) { printf   ("\"main: 56: %%7.7s%%3.7s\\n\", \"hello\", \"world\"\n"); }
	printf   ("main: 57: '%7.7s%3.7s'\n", "hello", "world");
	ft_printf("main: 58: '%7.7s%3.7s'\n", "hello", "world");
	printf("\n");
	
	if (verbose == 1) { printf   ("\"main: 61: %%7.3s%%7.7s\\n\", \"hello\", \"world\"\n"); }
	printf   ("main: 62: '%7.3s%7.7s'\n", "hello", "world");
	ft_printf("main: 63: '%7.3s%7.7s'\n", "hello", "world");
	printf("\n");
	
	if (verbose == 1) { printf   ("\"main: 66: %%3.3s%%7.7s\\n\", \"hello\", \"world\"\n"); }
	printf   ("main: 67: '%3.3s%7.7s'\n", "hello", "world");
	ft_printf("main: 68: '%3.3s%7.7s'\n", "hello", "world");
	printf("\n");
	
	if (verbose == 1) { printf   ("\"main: 71: %%7.3s%%3.7s\\n\", \"hello\", \"world\"\n"); }
	printf   ("main: 72: '%7.3s%3.7s'\n", "hello", "world");
	ft_printf("main: 73: '%7.3s%3.7s'\n", "hello", "world");
	printf("\n");
	
	if (verbose == 1) { printf   ("\"main: 76: %%7.7s%%7.3s\\n\", \"hello\", \"world\"\n"); }
	printf   ("main: 77: '%7.7s%7.3s'\n", "hello", "world");
	ft_printf("main: 78: '%7.7s%7.3s'\n", "hello", "world");
	printf("\n");
	
	if (verbose == 1) { printf   ("\"main: 81: %%3.7s%%7.3s\\n\", \"hello\", \"world\"\n"); }
	printf   ("main: 82: '%3.7s%7.3s'\n", "hello", "world");
	ft_printf("main: 83: '%3.7s%7.3s'\n", "hello", "world");
	printf("\n");
	
	if (verbose == 1) { printf   ("\"main: 86: %%7.7s%%3.3s\\n\", \"hello\", \"world\"\n"); }
	printf   ("main: 87: '%7.7s%3.3s'\n", "hello", "world");
	ft_printf("main: 88: '%7.7s%3.3s'\n", "hello", "world");
	printf("\n");
	
	if (verbose == 1) { printf   ("\"main: 91: %%7.3s%%7.3s\\n\", \"hello\", \"world\"\n"); }
	printf   ("main: 92: '%7.3s%7.3s'\n", "hello", "world");
	ft_printf("main: 93: '%7.3s%7.3s'\n", "hello", "world");
	printf("\n");
	
	if (verbose == 1) { printf   ("\"main: 96: %%3.3s%%7.3s\\n\", \"hello\", \"world\"\n"); }
	printf   ("main: 97: '%3.3s%7.3s'\n", "hello", "world");
	ft_printf("main: 98: '%3.3s%7.3s'\n", "hello", "world");
	printf("\n");
	
	if (verbose == 1) { printf   ("\"main: 101: %%7.3s%%3.3s\\n\", \"hello\", \"world\"\n"); }
	printf   ("main: 102: '%7.3s%3.3s'\n", "hello", "world");
	ft_printf("main: 103: '%7.3s%3.3s'\n", "hello", "world");
	printf("\n");
	
	return (0);
}
