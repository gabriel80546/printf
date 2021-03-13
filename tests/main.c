/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 08:31:12 by gabriel           #+#    #+#             */
/*   Updated: 2021/03/13 13:52:57 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../ft_printf.h"
#include "../libft/libft.h"

int main()
{
	char *s_hidden = "hi low\0don't print me lol\0";

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

	printf("@#@#@###@#@###@#@###@@#@#@##@#@@@#@#@#@#@#@##@#@#@@#@#@@#@#@#\n\0");
	printf("##@@@##@@#@#@##@#@##@@#@# Parte 2 @@#@##@@#@@#@##@#@#@#@#@#@@\n\0");
	printf("@@@#@#@@#@#@#@##@#@#@#@#@#@###@@@#@#@@@#@#@@#@#@#@#@#@@#@#@@#\n\n");

	if (verbose == 1) { printf   ("\"main: 112: %%3.s\\n\", s_hidden\n"); }
	printf   ("main: 113: '%3.s'\n", s_hidden);
	ft_printf("main: 114: '%3.s'\n", s_hidden);
	printf("\n");

	if (verbose == 1) { printf   ("\"main: 117: %%10.s\\n\", s_hidden\n"); }
	printf   ("main: 118: '%10.s'\n", s_hidden);
	ft_printf("main: 119: '%10.s'\n", s_hidden);
	printf("\n");

	if (verbose == 1) { printf   ("\"main: 122: %%3.s\\n\", NULL\n"); }
	printf   ("main: 123: '%3.s'\n", NULL);
	ft_printf("main: 124: '%3.s'\n", NULL);
	printf("\n");

	if (verbose == 1) { printf   ("\"main: 127: %%10.s\\n\", NULL\n"); }
	printf   ("main: 128: '%10.s'\n", NULL);
	ft_printf("main: 129: '%10.s'\n", NULL);
	printf("\n");

	if (verbose == 1) { printf   ("\"main: 132: %%1.s\\n\", \"\\0\"\n"); }
	printf   ("main: 133: '%1.s'\n", "\0");
	ft_printf("main: 134: '%1.s'\n", "\0");
	printf("\n");

	if (verbose == 1) { printf   ("\"main: 137: %%2.s\\n\", \"\\0\"\n"); }
	printf   ("main: 138: '%2.s'\n", "\0");
	ft_printf("main: 139: '%2.s'\n", "\0");
	printf("\n");

	if (verbose == 1) { printf   ("\"main: 142: %%9.s\\n\", \"\\0\"\n"); }
	printf   ("main: 143: '%9.s'\n", "\0");
	ft_printf("main: 144: '%9.s'\n", "\0");
	printf("\n");

	if (verbose == 1) { printf   ("\"main: 147: %%-3.s\\n\", s_hidden\n"); }
	printf   ("main: 148: '%-3.s'\n", s_hidden);
	ft_printf("main: 149: '%-3.s'\n", s_hidden);
	printf("\n");

	if (verbose == 1) { printf   ("\"main: 152: %%-8.s\\n\", s_hidden\n"); }
	printf   ("main: 153: '%-8.s'\n", s_hidden);
	ft_printf("main: 154: '%-8.s'\n", s_hidden);
	printf("\n");

	if (verbose == 1) { printf   ("\"main: 157: %%-3.s\\n\", NULL\n"); }
	printf   ("main: 158: '%-3.s'\n", NULL);
	ft_printf("main: 159: '%-3.s'\n", NULL);
	printf("\n");

	if (verbose == 1) { printf   ("\"main: 162: %%-8.s\\n\", NULL\n"); }
	printf   ("main: 163: '%-8.s'\n", NULL);
	ft_printf("main: 164: '%-8.s'\n", NULL);
	printf("\n");

	if (verbose == 1) { printf   ("\"main: 167: %%-1.s\\n\", \"\\0\"\n"); }
	printf   ("main: 168: '%-1.s'\n", "\0");
	ft_printf("main: 169: '%-1.s'\n", "\0");
	printf("\n");

	if (verbose == 1) { printf   ("\"main: 172: %%-2.s\\n\", \"\\0\"\n"); }
	printf   ("main: 173: '%-2.s'\n", "\0");
	ft_printf("main: 174: '%-2.s'\n", "\0");
	printf("\n");

	if (verbose == 1) { printf   ("\"main: 177: %%-6.s\\n\", \"\\0\"\n"); }
	printf   ("main: 178: '%-6.s'\n", "\0");
	ft_printf("main: 179: '%-6.s'\n", "\0");
	printf("\n");

	return (0);
}
