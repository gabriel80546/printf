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
	char *s_hidden = "hi low\0don't print me lol\0";
	char *nulo = NULL;

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

	printf("@#@#@###@#@###@#@###@@#@#@##@#@@@#@#@#@#@#@##@#@#@@#@#@@#@#@#\n");
	printf("##@@@##@@#@#@##@#@##@@#@# Parte 2 @@#@##@@#@@#@##@#@#@#@#@#@@\n");
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
	printf   ("main: 123: '%3.s'\n", (char*)nulo);
	ft_printf("main: 124: '%3.s'\n", (char*)nulo);
	printf("\n");

	if (verbose == 1) { printf   ("\"main: 127: %%10.s\\n\", NULL\n"); }
	printf   ("main: 128: '%10.s'\n", (char*)nulo);
	ft_printf("main: 129: '%10.s'\n", (char*)nulo);
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
	printf   ("main: 158: '%-3.s'\n", (char*)nulo);
	ft_printf("main: 159: '%-3.s'\n", (char*)nulo);
	printf("\n");

	if (verbose == 1) { printf   ("\"main: 162: %%-8.s\\n\", NULL\n"); }
	printf   ("main: 163: '%-8.s'\n", (char*)nulo);
	ft_printf("main: 164: '%-8.s'\n", (char*)nulo);
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

	printf("@#@#@###@#@###@#@###@@#@#@##@#@@@#@#@#@#@#@##@#@#@@#@#@@#@#@#\n");
	printf("##@@@##@@#@#@##@#@##@@#@# Parte 3 @@#@##@@#@@#@##@#@#@#@#@#@@\n");
	printf("@@@#@#@@#@#@#@##@#@#@#@#@#@###@@@#@#@@@#@#@@#@#@#@#@#@@#@#@@#\n");
	printf("\n");

	if (verbose == 1) { printf   ("\"main: 188: '%%7i'\\n\", 33\n"); }
	printf   ("main: 189: '%7i'\n", 33);
	ft_printf("main: 190: '%7i'\n", 33);
	printf("\n");
	
	if (verbose == 1) { printf   ("\"main: 193: '%%7i'\\n\", -14\n"); }
	printf   ("main: 193: '%7i'\n", -14);
	ft_printf("main: 194: '%7i'\n", -14);
	printf("\n");
	
	if (verbose == 1) { printf   ("\"main: 198: '%%3i'\\n\", 0\n"); }
	printf   ("main: 197: '%3i'\n", 0);
	ft_printf("main: 198: '%3i'\n", 0);
	printf("\n");
	
	if (verbose == 1) { printf   ("\"main: 203: '%%-7i'\\n\", 33\n"); }
	printf   ("main: 201: '%-7i'\n", 33);
	ft_printf("main: 202: '%-7i'\n", 33);
	printf("\n");
	
	if (verbose == 1) { printf   ("\"main: 208: '%%-7i'\\n\", -14\n"); }
	printf   ("main: 205: '%-7i'\n", -14);
	ft_printf("main: 206: '%-7i'\n", -14);
	printf("\n");
	
	if (verbose == 1) { printf   ("\"main: 213: '%%-3i'\\n\", 0\n"); }
	printf   ("main: 209: '%-3i'\n", 0);
	ft_printf("main: 210: '%-3i'\n", 0);
	printf("\n");
	
	if (verbose == 1) { printf   ("\"main: 218: '%%.5i'\\n\", 2\n"); }
	printf   ("main: 213: '%.5i'\n", 2);
	ft_printf("main: 214: '%.5i'\n", 2);
	printf("\n");
	
	if (verbose == 1) { printf   ("\"main: 223: '%%.6i'\\n\", -3\n"); }
	printf   ("main: 217: '%.6i'\n", -3);
	ft_printf("main: 218: '%.6i'\n", -3);
	printf("\n");
	
	if (verbose == 1) { printf   ("\"main: 228: '%%.3i'\\n\", 0\n"); }
	printf   ("main: 221: '%.3i'\n", 0);
	ft_printf("main: 222: '%.3i'\n", 0);
	printf("\n");
	
	if (verbose == 1) { printf   ("\"main: 233: '%%07i'\\n\", -54\n"); }
	printf   ("main: 225: '%07i'\n", -54);
	ft_printf("main: 226: '%07i'\n", -54);
	printf("\n");
	
	if (verbose == 1) { printf   ("\"main: 238: '%%8.5i'\\n\", 34\n"); }
	printf   ("main: 229: '%8.5i'\n", 34);
	ft_printf("main: 230: '%8.5i'\n", 34);
	printf("\n");
	
	if (verbose == 1) { printf   ("\"main: 243: '%%10.5i'\\n\", -216\n"); }
	printf   ("main: 233: '%10.5i'\n", -216);
	ft_printf("main: 234: '%10.5i'\n", -216);
	printf("\n");
	
	if (verbose == 1) { printf   ("\"main: 248: '%%8.5i'\\n\", 0\n"); }
	printf   ("main: 237: '%8.5i'\n", 0);
	ft_printf("main: 238: '%8.5i'\n", 0);
	printf("\n");
	
	if (verbose == 1) { printf   ("\"main: 253: '%%8.3i'\\n\", 8375\n"); }
	printf   ("main: 241: '%8.3i'\n", 8375);
	ft_printf("main: 242: '%8.3i'\n", 8375);
	printf("\n");

	if (verbose == 1) { printf   ("\"max int = '%d'\\n\", -2147483648\n"); }
	printf   ("max int = '%d'\n", -2147483648);
	ft_printf("max int = '%d'\n", -2147483648);
	printf("\n");

	printf("@#@#@###@#@###@#@###@@#@#@##@#@@@#@#@#@#@#@##@#@#@@#@#@@#@#@#\n");
	printf("##@@@##@@#@#@##@#@##@@#@# Parte 4 @@#@##@@#@@#@##@#@#@#@#@#@@\n");
	printf("@@@#@#@@#@#@#@##@#@#@#@#@#@###@@@#@#@@@#@#@@#@#@#@#@#@@#@#@@#\n");
	printf("\n");


	if (verbose == 1) { printf   ("\"main: 268: '%%-7i'\", 33\n"); }
	printf   ("main: 270: '%-7i'\n", 33);
	ft_printf("main: 271: '%-7i'\n", 33);
	printf("\n");

	if (verbose == 1) { printf   ("\"main: 268: '%%-7i'\", -14\n"); }
	printf   ("main: 275: '%-7i'\n", -14);
	ft_printf("main: 276: '%-7i'\n", -14);
	printf("\n");

	if (verbose == 1) { printf   ("\"main: 268: '%%-3i'\", 0\n"); }
	printf   ("main: 280: '%-3i'\n", 0);
	ft_printf("main: 281: '%-3i'\n", 0);
	printf("\n");

	if (verbose == 1) { printf   ("\"main: 268: '%%-8.5i'\", 34\n"); }
	printf   ("main: 285: '%-8.5i'\n", 34);
	ft_printf("main: 286: '%-8.5i'\n", 34);
	printf("\n");

	if (verbose == 1) { printf   ("\"main: 268: '%%-10.5i'\", -216\n"); }
	printf   ("main: 290: '%-10.5i'\n", -216);
	ft_printf("main: 291: '%-10.5i'\n", -216);
	printf("\n");

	if (verbose == 1) { printf   ("\"main: 268: '%%-8.5i'\", 0\n"); }
	printf   ("main: 295: '%-8.5i'\n", 0);
	ft_printf("main: 296: '%-8.5i'\n", 0);
	printf("\n");

	if (verbose == 1) { printf   ("\"main: 268: '%%-8.3i'\", 8375\n"); }
	printf   ("main: 300: '%-8.3i'\n", 8375);
	ft_printf("main: 301: '%-8.3i'\n", 8375);
	printf("\n");

	if (verbose == 1) { printf   ("\"main: 268: '%%-8.3i'\", -8473\n"); }
	printf   ("main: 305: '%-8.3i'\n", -8473);
	ft_printf("main: 306: '%-8.3i'\n", -8473);
	printf("\n");

	if (verbose == 1) { printf   ("\"main: 268: '%%08.5i'\", 34\n"); }
	printf   ("main: 310: '%08.5i'\n", 34);
	ft_printf("main: 311: '%08.5i'\n", 34);
	printf("\n");

	if (verbose == 1) { printf   ("\"main: 268: '%%010.5i'\", -216\n"); }
	printf   ("main: 315: '%010.5i'\n", -216);
	ft_printf("main: 316: '%010.5i'\n", -216);
	printf("\n");

	if (verbose == 1) { printf   ("\"main: 268: '%%08.5i'\", 0\n"); }
	printf   ("main: 320: '%08.5i'\n", 0);
	ft_printf("main: 321: '%08.5i'\n", 0);
	printf("\n");

	if (verbose == 1) { printf   ("\"main: 268: '%%08.3i'\", 8375\n"); }
	printf   ("main: 325: '%08.3i'\n", 8375);
	ft_printf("main: 326: '%08.3i'\n", 8375);
	printf("\n");

	if (verbose == 1) { printf   ("\"main: 268: '%%08.3i'\", -8473\n"); }
	printf   ("main: 330: '%08.3i'\n", -8473);
	ft_printf("main: 331: '%08.3i'\n", -8473);
	printf("\n");

	if (verbose == 1) { printf   ("\"main: 268: '%%.0i'\", 0\n"); }
	printf   ("main: 335: '%.0i'\n", 0);
	ft_printf("main: 336: '%.0i'\n", 0);
	printf("\n");

	if (verbose == 1) { printf   ("\"main: 268: '%%.i'\", 0\n"); }
	printf   ("main: 340: '%.i'\n", 0);
	ft_printf("main: 341: '%.i'\n", 0);
	printf("\n");

	if (verbose == 1) { printf   ("\"main: 268: '%%5.0i'\", 0\n"); }
	printf   ("main: 345: '%5.0i'\n", 0);
	ft_printf("main: 346: '%5.0i'\n", 0);
	printf("\n");

	if (verbose == 1) { printf   ("\"main: 268: '%%5.i'\", 0\n"); }
	printf   ("main: 350: '%5.i'\n", 0);
	ft_printf("main: 351: '%5.i'\n", 0);
	printf("\n");

	if (verbose == 1) { printf   ("\"main: 268: '%%-5.0i'\", 0\n"); }
	printf   ("main: 355: '%-5.0i'\n", 0);
	ft_printf("main: 356: '%-5.0i'\n", 0);
	printf("\n");

	if (verbose == 1) { printf   ("\"main: 268: '%%-5.i'\", 0\n"); }
	printf   ("main: 360: '%-5.i'\n", 0);
	ft_printf("main: 361: '%-5.i'\n", 0);
	printf("\n");

	if (verbose == 1) { printf   ("\"main: 268: '%%-7d'\", 33\n"); }
	printf   ("main: 365: '%-7d'\n", 33);
	ft_printf("main: 366: '%-7d'\n", 33);
	printf("\n");

	if (verbose == 1) { printf   ("\"main: 268: '%%-7d'\", -14\n"); }
	printf   ("main: 370: '%-7d'\n", -14);
	ft_printf("main: 371: '%-7d'\n", -14);
	printf("\n");

	if (verbose == 1) { printf   ("\"main: 268: '%%-3d'\", 0\n"); }
	printf   ("main: 375: '%-3d'\n", 0);
	ft_printf("main: 376: '%-3d'\n", 0);
	printf("\n");

	if (verbose == 1) { printf   ("\"main: 268: '%%-8.5d'\", 34\n"); }
	printf   ("main: 380: '%-8.5d'\n", 34);
	ft_printf("main: 381: '%-8.5d'\n", 34);
	printf("\n");

	if (verbose == 1) { printf   ("\"main: 268: '%%-10.5d'\", -216\n"); }
	printf   ("main: 385: '%-10.5d'\n", -216);
	ft_printf("main: 386: '%-10.5d'\n", -216);
	printf("\n");

	if (verbose == 1) { printf   ("\"main: 268: '%%-8.5d'\", 0\n"); }
	printf   ("main: 390: '%-8.5d'\n", 0);
	ft_printf("main: 391: '%-8.5d'\n", 0);
	printf("\n");

	if (verbose == 1) { printf   ("\"main: 268: '%%-8.3d'\", 8375\n"); }
	printf   ("main: 395: '%-8.3d'\n", 8375);
	ft_printf("main: 396: '%-8.3d'\n", 8375);
	printf("\n");

	if (verbose == 1) { printf   ("\"main: 268: '%%-8.3d'\", -8473\n"); }
	printf   ("main: 400: '%-8.3d'\n", -8473);
	ft_printf("main: 401: '%-8.3d'\n", -8473);
	printf("\n");

	if (verbose == 1) { printf   ("\"main: 268: '%%08.5d'\", 34\n"); }
	printf   ("main: 405: '%08.5d'\n", 34);
	ft_printf("main: 406: '%08.5d'\n", 34);
	printf("\n");

	if (verbose == 1) { printf   ("\"main: 268: '%%010.5d'\", -216\n"); }
	printf   ("main: 410: '%010.5d'\n", -216);
	ft_printf("main: 411: '%010.5d'\n", -216);
	printf("\n");

	if (verbose == 1) { printf   ("\"main: 268: '%%08.5d'\", 0\n"); }
	printf   ("main: 415: '%08.5d'\n", 0);
	ft_printf("main: 416: '%08.5d'\n", 0);
	printf("\n");

	if (verbose == 1) { printf   ("\"main: 268: '%%08.3d'\", 8375\n"); }
	printf   ("main: 420: '%08.3d'\n", 8375);
	ft_printf("main: 421: '%08.3d'\n", 8375);
	printf("\n");

	printf("@#@#@###@#@###@#@###@@#@#@##@#@@@#@#@#@#@#@##@#@#@@#@#@@#@#@#\n");
	printf("##@@@##@@#@#@##@#@##@@#@# Parte 5 @@#@##@@#@@#@##@#@#@#@#@#@@\n");
	printf("@@@#@#@@#@#@#@##@#@#@#@#@#@###@@@#@#@@@#@#@@#@#@#@#@#@@#@#@@#\n");
	printf("\n");

//	if (verbose == 1) { printf   ("\nmain: 424: %%05i\", 43\n"); }
//	printf   ("main: 430: %05i\n", 43);
//	ft_printf("main: 431: %05i\n", 43);
//	printf("\n");

	if (verbose == 1) { printf   ("\nmain: 424: %%05i\", 43\n"); }
	printf   ("main: 435: '%05i'\n", 43);
	ft_printf("main: 436: '%05i'\n", 43);
	printf("\n");

	if (verbose == 1) { printf   ("\nmain: 424: %%07i\", -54\n"); }
	printf   ("main: 440: '%07i'\n", -54);
	ft_printf("main: 441: '%07i'\n", -54);
	printf("\n");

	if (verbose == 1) { printf   ("\nmain: 424: %%03i\", 0\n"); }
	printf   ("main: 445: '%03i'\n", 0);
	ft_printf("main: 446: '%03i'\n", 0);
	printf("\n");

	if (verbose == 1) { printf   ("\nmain: 424: %%010.5i\", -216\n"); }
	printf   ("main: 450: '%010.5i'\n", -216);
	ft_printf("main: 451: '%010.5i'\n", -216);
	printf("\n");

	if (verbose == 1) { printf   ("\nmain: 424: %%08.3i\", -8473\n"); }
	printf   ("main: 455: '%08.3i'\n", -8473);
	ft_printf("main: 456: '%08.3i'\n", -8473);
	printf("\n");

	if (verbose == 1) { printf   ("\nmain: 424: %%.0i\", 0\n"); }
	printf   ("main: 460: '%.0i'\n", 0);
	ft_printf("main: 461: '%.0i'\n", 0);
	printf("\n");

	if (verbose == 1) { printf   ("\nmain: 424: %%.i\", 0\n"); }
	printf   ("main: 465: '%.i'\n", 0);
	ft_printf("main: 466: '%.i'\n", 0);
	printf("\n");

	if (verbose == 1) { printf   ("\nmain: 424: %%5.0i\", 0\n"); }
	printf   ("main: 470: '%5.0i'\n", 0);
	ft_printf("main: 471: '%5.0i'\n", 0);
	printf("\n");

	if (verbose == 1) { printf   ("\nmain: 424: %%5.i\", 0\n"); }
	printf   ("main: 475: '%5.i'\n", 0);
	ft_printf("main: 476: '%5.i'\n", 0);
	printf("\n");

	if (verbose == 1) { printf   ("\nmain: 424: %%-5.0i\", 0\n"); }
	printf   ("main: 480: '%-5.0i'\n", 0);
	ft_printf("main: 481: '%-5.0i'\n", 0);
	printf("\n");

	if (verbose == 1) { printf   ("\nmain: 424: %%-5.i\", 0\n"); }
	printf   ("main: 485: '%-5.i'\n", 0);
	ft_printf("main: 486: '%-5.i'\n", 0);
	printf("\n");

	if (verbose == 1) { printf   ("\nmain: 424: %%05d\", 43\n"); }
	printf   ("main: 490: '%05d'\n", 43);
	ft_printf("main: 491: '%05d'\n", 43);
	printf("\n");

	if (verbose == 1) { printf   ("\nmain: 424: %%07d\", -54\n"); }
	printf   ("main: 495: '%07d'\n", -54);
	ft_printf("main: 496: '%07d'\n", -54);
	printf("\n");

	if (verbose == 1) { printf   ("\nmain: 424: %%03d\", 0\n"); }
	printf   ("main: 500: '%03d'\n", 0);
	ft_printf("main: 501: '%03d'\n", 0);
	printf("\n");

	if (verbose == 1) { printf   ("\nmain: 424: %%010.5d\", -216\n"); }
	printf   ("main: 505: '%010.5d'\n", -216);
	ft_printf("main: 506: '%010.5d'\n", -216);
	printf("\n");

	if (verbose == 1) { printf   ("\nmain: 424: %%08.3d\", -8473\n"); }
	printf   ("main: 510: '%08.3d'\n", -8473);
	ft_printf("main: 511: '%08.3d'\n", -8473);
	printf("\n");

	if (verbose == 1) { printf   ("\nmain: 424: %%.0d\", 0\n"); }
	printf   ("main: 515: '%.0d'\n", 0);
	ft_printf("main: 516: '%.0d'\n", 0);
	printf("\n");

	if (verbose == 1) { printf   ("\nmain: 424: %%.d\", 0\n"); }
	printf   ("main: 520: '%.d'\n", 0);
	ft_printf("main: 521: '%.d'\n", 0);
	printf("\n");

	if (verbose == 1) { printf   ("\nmain: 424: %%5.0d\", 0\n"); }
	printf   ("main: 525: '%5.0d'\n", 0);
	ft_printf("main: 526: '%5.0d'\n", 0);
	printf("\n");

	if (verbose == 1) { printf   ("\nmain: 424: %%5.d\", 0\n"); }
	printf   ("main: 530: '%5.d'\n", 0);
	ft_printf("main: 531: '%5.d'\n", 0);
	printf("\n");

	if (verbose == 1) { printf   ("\nmain: 424: %%-5.0d\", 0\n"); }
	printf   ("main: 535: '%-5.0d'\n", 0);
	ft_printf("main: 536: '%-5.0d'\n", 0);
	printf("\n");

	if (verbose == 1) { printf   ("\nmain: 424: %%-5.d\", 0\n"); }
	printf   ("main: 540: '%-5.d'\n", 0);
	ft_printf("main: 541: '%-5.d'\n", 0);
	printf("\n");


	printf("@#@#@###@#@###@#@###@@#@#@##@#@@@#@#@#@#@#@##@#@#@@#@#@@#@#@#\n");
	printf("##@@@##@@#@#@##@#@##@@#@# Parte 5 @@#@##@@#@@#@##@#@#@#@#@#@@\n");
	printf("@@@#@#@@#@#@#@##@#@#@#@#@#@###@@@#@#@@@#@#@@#@#@#@#@#@@#@#@@#\n");
	printf("\n");

	printf   ("\"main: 550: %%0.d   \\n\", 0\n"); // 1st '*' = -4, 2nd '*' = 0
	printf   ("main: 551: %0.d   \n", 0); // 1st '*' = -4, 2nd '*' = 0
	ft_printf("main: 552: %0.d   \n", 0); // 1st '*' = -4, 2nd '*' = 0
	printf("\n");

	printf   ("\"main: 555: %%0.0d  \\n\", 0\n"); // 1st '*' = -4, 2nd '*' = 0
	printf   ("main: 556: %0.0d  \n", 0); // 1st '*' = -4, 2nd '*' = 0
	ft_printf("main: 557: %0.0d  \n", 0); // 1st '*' = -4, 2nd '*' = 0
	printf("\n");

	printf   ("\"main: 560: %%-0.0d \\n\", 0\n"); // 1st '*' = -4, 2nd '*' = 0
	printf   ("main: 561: %-0.0d \n", 0); // 1st '*' = -4, 2nd '*' = 0
	ft_printf("main: 562: %-0.0d \n", 0); // 1st '*' = -4, 2nd '*' = 0
	printf("\n");

	return (0);
}
