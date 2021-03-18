/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 08:29:20 by gabriel           #+#    #+#             */
/*   Updated: 2021/03/14 11:29:31 by gpassos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>


int in_file = 0;
int debug = 0;

int g_fd;
char *g_string;


#ifndef CAMINHO_SAIDA
# define CAMINHO_SAIDA "/home/gabriel/desktop/qd/projetos/printf/printf/tests/saida"
#endif

// void	*ft_calloco(size_t nmemb, size_t size)
// {
// 	void *saida;

// 	saida = malloc(nmemb * size);
// 	if (saida == NULL)
// 		return (NULL);
// 	ft_memset(saida, 0, nmemb * size);
// 	return (saida);
// }


t_flags	ft_init_flags(void)
{
	t_flags saida;

	saida.left_asteristic  = 0;
	saida.right_asteristic = 0;
	saida.n_left_indf      = 1;
	saida.n_right_indf     = 1;
	saida.n_left           = 0;
	saida.n_right          = 0;
	saida.pad_zeros        = 0;
	saida.minus            = 0;
	saida.precision        = 0;
	return (saida);
}

void	logging(char *str, ...)
{
	va_list args;

	va_start(args, str);
	if (in_file == 0)
		vprintf(str, args);
	else if (in_file == 1)
	{
		vsprintf(g_string, str, args);
		ft_putstr_fd(g_string, g_fd);
	}
	va_end(args);
}

void	ft_print_flags(char *append, t_flags flags)
{
	logging("%sflags.minus     = %d\n", append, flags.minus);
	logging("%sflags.n_left    = %d\n", append, flags.n_left);
	logging("%sflags.n_right   = %d\n", append, flags.n_right);
	logging("%sflags.pad_zeros = %d\n", append, flags.pad_zeros);
	logging("%sflags.precision = %d\n", append, flags.precision);
}

int	ft_printf_itoa_log(long n)
{
	int contador;
	int temp;

	contador = 0;
	if (n < 0)
	{
		contador++;
		n = -n;
	}
	temp = n;
	while (n > 9)
	{
		n = n / 10;
		contador++;
	}
	n = temp;
	contador++;
	return (contador + 1);
}

static unsigned int	ft_itoa_ui_log(unsigned long n)
{
	unsigned int contador;
	unsigned int temp;

	contador = 0;
	if (n < 0)
	{
		contador++;
		n = -n;
	}
	temp = n;
	while (n > 9)
	{
		n = n / 10;
		contador++;
	}
	n = temp;
	contador++;
	return (contador + 1);
}

char		*ft_itoa_ui(unsigned int n)
{
	char			*saida;
	unsigned int	contador;

	saida = (char *)malloc(sizeof(char) * ft_itoa_ui_log(n));
	if (saida == NULL)
		return (NULL);
	*(saida + 0) = '-';
	contador = (ft_itoa_ui_log(n) - 1);
	n = (n < 0) ? (-n) : n;
	*(saida + contador) = '\0';
	while (n > 9)
	{
		*(saida + contador - 1) = (n % 10) + '0';
		n = (n / 10);
		contador--;
	}
	*(saida + contador - 1) = (n % 10) + '0';
	return (saida);
}

static int	ft_itoa_x_log(unsigned long n)
{
	int contador;
	int temp;

	contador = 0;
	if (n < 0)
	{
		contador++;
		n = -n;
	}
	temp = n;
	while (n > 15)
	{
		n = n / 16;
		contador++;
	}
	n = temp;
	contador++;
	return (contador + 1);
}

char		*ft_itoa_x(unsigned int n)
{
	char	*saida;
	int		contador;
	char	temp;

	saida = (char *)malloc(sizeof(char) * ft_itoa_x_log(n));
	if (saida == NULL)
		return (NULL);
	*(saida + 0) = '-';
	contador = (ft_itoa_x_log(n) - 1);
	n = (n < 0) ? (-n) : n;
	*(saida + contador) = '\0';
	while (n > 15)
	{
		temp = (n % 16) + '0';
		if (temp > '9')
			temp += ('a' - ('9' + 1));
		*(saida + contador - 1) = temp;
		n = (n / 16);
		contador--;
	}
	temp = (n % 16) + '0';
	if (temp > '9')
		temp += ('a' - ('9' + 1));
	*(saida + contador - 1) = temp;
	return (saida);
}



static int	ft_itoa_x_ul_log(unsigned long n)
{
	int contador;
	int temp;

	contador = 0;
	if (n < 0)
	{
		contador++;
		n = -n;
	}
	temp = n;
	while (n > 15)
	{
		n = n / 16;
		contador++;
	}
	n = temp;
	contador++;
	return (contador + 1);
}

char		*ft_itoa_x_ul(unsigned long n)
{
	char	*saida;
	int		contador;
	char	temp;

	saida = (char *)malloc(sizeof(char) * ft_itoa_x_ul_log(n));
	if (saida == NULL)
		return (NULL);
	*(saida + 0) = '-';
	contador = (ft_itoa_x_ul_log(n) - 1);
	n = (n < 0) ? (-n) : n;
	*(saida + contador) = '\0';
	while (n > 15)
	{
		temp = (n % 16) + '0';
		if (temp > '9')
			temp += ('a' - ('9' + 1));
		*(saida + contador - 1) = temp;
		n = (n / 16);
		contador--;
	}
	temp = (n % 16) + '0';
	if (temp > '9')
		temp += ('a' - ('9' + 1));
	*(saida + contador - 1) = temp;
	return (saida);
}

static int	ft_itoa_X_log(unsigned long n)
{
	int contador;
	int temp;

	contador = 0;
	if (n < 0)
	{
		contador++;
		n = -n;
	}
	temp = n;
	while (n > 15)
	{
		n = n / 16;
		contador++;
	}
	n = temp;
	contador++;
	return (contador + 1);
}

char		*ft_itoa_X(unsigned int n)
{
	char	*saida;
	int		contador;
	char	temp;

	saida = (char *)malloc(sizeof(char) * ft_itoa_X_log(n));
	if (saida == NULL)
		return (NULL);
	*(saida + 0) = '-';
	contador = (ft_itoa_X_log(n) - 1);
	n = (n < 0) ? (-n) : n;
	*(saida + contador) = '\0';
	while (n > 15)
	{
		temp = (n % 16) + '0';
		if (temp > '9')
			temp += ('A' - ('9' + 1));
		*(saida + contador - 1) = temp;
		n = (n / 16);
		contador--;
	}
	temp = (n % 16) + '0';
	if (temp > '9')
		temp += ('A' - ('9' + 1));
	*(saida + contador - 1) = temp;
	return (saida);
}

void	ft_pchar(char caracter, int *counter)
{
	write(1, &caracter, 1);
	*counter = *counter + 1;
}
void	ft_pstr(char *string, int *counter)
{
	ft_putstr_fd(string, 1);
	*counter = *counter + ft_strlen(string);
}
void	ft_pnchar(char caracter, int n, int *counter)
{
	int i;

	i = 0;
	while(i < n)
	{
		ft_pchar(caracter, counter);
		i++;
	}
}


char	*ft_append(char *str, char caracter)
{
	char	*saida;
	int		len;

	len = ft_strlen(str);
	saida = (char *)malloc(len + 2);
	ft_strlcpy(saida, str, len + 1);
	saida[len + 0] = caracter;
	saida[len + 1] = '\0';
	free(str);
	return (saida);
}

char	*ft_strappend(char *str, char *to_append)
{
	char	*saida;
	int		i;
	int		len_str;
	int		len_append;

	if (debug > 2) { logging("326: to_append = %p\n", to_append); }
	if (debug > 2) { logging("327: to_append = %p\n", to_append); }
	if (debug > 2) { logging("328: to_append = '%s'\n", to_append); }
	len_str = ft_strlen(str);
	len_append = ft_strlen(to_append);
	saida = (char *)malloc(len_str + len_append + 2);
	ft_strlcpy(saida, str, len_str + 1);
	i = 0;
	while (to_append[i] != '\0')
	{
		saida[len_str + i] = to_append[i];
		i++;
	}
	saida[len_str + i] = '\0';
	if (debug > 2) { logging("340: to_append = '%p'\n", to_append); }
	free(str);
	if (debug > 2) { logging("342: to_append = '%p'\n", to_append); }
	return (saida);
}

t_print	get_int(t_print print, int *counter, va_list args)
{
	t_print	saida;
	char	*temp;
	int		n;
	int		i;
	int		tamanho;
	int		neg;
	int		tt;
	int		troca;


	saida = print;
	n = va_arg(args, int);

	tt = 0;
	if (saida.flags.n_right == 0 && saida.flags.n_left == 0 && saida.flags.right_asteristic == 1 && n == 0)
		tt = 1;

	troca = 0;
	if (saida.flags.n_right < 0)
	{
		if ((saida.flags.pad_zeros == 1 && saida.flags.minus != 1) && saida.flags.n_left_indf == 0)
		{
			troca = 1;
			saida.flags.n_right = saida.flags.n_left;
		}
	}

	neg = 0;
	if (n < 0 && n != -2147483648)
	{
		n = -n;
		neg = 1;
	}
	if (neg == 1 && ((saida.flags.pad_zeros == 1 && saida.flags.minus != 1) && saida.flags.precision == 0))
		ft_pchar('-', counter);

	if (saida.flags.n_left >= 0 && saida.flags.minus == 0)
	{
		i = 0;
		tamanho = ft_printf_itoa_log((long)n) - 1;
		if ((tamanho - saida.flags.n_right) < 0)
			tamanho -= (tamanho - saida.flags.n_right);
		while (i < (saida.flags.n_left - tamanho - neg))
		{
			if ((saida.flags.pad_zeros == 1 && saida.flags.minus != 1))
				if (saida.flags.precision == 1)
					ft_pchar(' ', counter);
				else
					ft_pchar('0', counter);
			else
				ft_pchar(' ', counter);
			i++;
		}
	}

	if (neg == 1 && !((saida.flags.pad_zeros == 1 && saida.flags.minus != 1) && saida.flags.precision == 0))
		ft_pchar('-', counter);

	if (saida.flags.precision == 1 && saida.flags.n_right >= 0)
	{
		i = 0;
		tamanho = ft_printf_itoa_log((long)n) - 1;
		if(troca == 1)
			tamanho += neg;
		ft_pnchar('0', saida.flags.n_right - tamanho, counter);
		/*
		while (i < (saida.flags.n_right - tamanho))
		{
			ft_pchar('0', counter);
			i++;
		}
		*/
	}

	if (tt == 1)
	{
		temp = ft_calloc(1, 1);
	}
	else
	{
		if (n == 0 && saida.flags.precision == 1 && (saida.flags.pad_zeros == 0 || saida.flags.minus == 1))
		{
			temp = ft_calloc(1, 2);
			if (saida.flags.n_right > 0 || saida.flags.n_right < 0)
				temp[0] = '0';
			else if (saida.flags.n_left > 0)
				temp[0] = ' ';
			ft_pstr(temp, counter);
		}
		else
		{
			if (n == 0 && saida.flags.n_left_indf == 0 && saida.flags.n_right_indf == 0 && saida.flags.n_left != 0 && saida.flags.n_right == 0)
			{
				temp = ft_calloc(1, 1);
				ft_pchar(' ', counter);
			}
			else
			{
				temp = ft_itoa(n);
				ft_pstr(temp, counter);
			}
		}
	}

	if (saida.flags.n_left >= 0 && saida.flags.minus == 1)
	{
		i = 0;
		tamanho = ft_printf_itoa_log((long)n) - 1;
		if ((tamanho - saida.flags.n_right) < 0)
			tamanho -= (tamanho - saida.flags.n_right);
		ft_pnchar(' ',saida.flags.n_left - tamanho - neg, counter); 
	}

	free(temp);
	saida.estado = UNTIL_PERCENT;
	return (saida);
}

t_print	get_uint(t_print print, int *counter, va_list args)
{
	t_print			saida;
	char			*temp;
	unsigned int	n;
	int				i;
	int				tamanho;

	saida = print;


	if (saida.flags.n_right < 0)
	{
		if (saida.flags.pad_zeros == 1 && saida.flags.n_left_indf == 0)
			saida.flags.n_right = saida.flags.n_left;
		else
			saida.flags.n_right = 0;
	}


/*
	if (saida.flags.n_right == -1)
	{
		saida.flags.n_right = va_arg(args, int);
		if (saida.flags.n_right < 0)
		{
			if (saida.flags.pad_zeros == 1 && saida.flags.n_left != -2)
				saida.flags.n_right = saida.flags.n_left;
			else
				saida.flags.n_right = 0;
		}
	}

*/


	n = va_arg(args, unsigned int);
	if (debug > 2) { logging("parte1\n"); }
	if (saida.flags.n_left >= 0 && saida.flags.minus == 0)
	{
		i = 0;
		tamanho = ft_printf_itoa_log((long)n) - 1;
		if ((tamanho - saida.flags.n_right) < 0)
			tamanho -= (tamanho - saida.flags.n_right);
		while (i < (saida.flags.n_left - tamanho))
		{
			if (saida.flags.pad_zeros == 1)
				if (saida.flags.precision == 1)
					ft_pchar(' ', counter);
				else
					ft_pchar('0', counter);
			else
				ft_pchar(' ', counter);
			i++;
		}
	}
	if (debug > 2) { logging("parte2\n"); }

	if (saida.flags.precision == 1 && saida.flags.n_right >= 0)
	{
		i = 0;
		tamanho = ft_printf_itoa_log((long)n) - 1;
		while (i < (saida.flags.n_right - tamanho))
		{
			ft_pchar('0', counter);
			i++;
		}
	}
	if (debug > 2) { logging("parte3\n"); }

	if (n == 0 && saida.flags.precision == 1 && saida.flags.pad_zeros == 0)
	{
		temp = ft_calloc(1, 2);
		if (saida.flags.n_right > 0)
			temp[0] = '0';
		else if (saida.flags.n_left > 0)
			temp[0] = ' ';
		ft_pstr(temp, counter);
	}
	else
	{
		temp = ft_itoa_ui(n);
		ft_pstr(temp, counter);
	}
	if (debug > 2) { logging("parte4\n"); }

	if (saida.flags.n_left >= 0 && saida.flags.minus == 1)
	{
		i = 0;
		tamanho = ft_printf_itoa_log((long)n) - 1;
		if ((tamanho - saida.flags.n_right) < 0)
			tamanho -= (tamanho - saida.flags.n_right);
		while (i < (saida.flags.n_left - tamanho))
		{
			if (saida.flags.pad_zeros == 1)
				ft_pchar(' ', counter);
			else
				ft_pchar(' ', counter);
			i++;
		}
	}
	
	if (debug > 2) { logging("parte5\n"); }

	free(temp);
	if (debug > 2) { logging("parte6\n"); }
	saida.estado = UNTIL_PERCENT;
	if (debug > 2) { logging("parte7\n"); }
	//if (debug > 2) { logging("*output = '%s'\n", *output); }
	if (debug > 2) { logging("*counter = %d\n", *counter); }
	return (saida);
}

t_print	get_hex(t_print print, int *counter, va_list args)
{
	t_print			saida;
	char			*temp;
	int				tamanho;
	unsigned int	n;
	//int				log;
	int				i;

	saida = print;

	/*
	if (saida.flags.n_right == -1)
	{
		saida.flags.n_right = va_arg(args, int);
		if (saida.flags.n_right < 0)
		{
			if (saida.flags.pad_zeros == 1 && saida.flags.n_left_indf != -2)
				saida.flags.n_right = saida.flags.n_left;
			else
				saida.flags.n_right = 0;
		}
	}
	*/

	n = va_arg(args, unsigned int);
	if (debug > 2) { logging("parte1\n"); }
	if (saida.flags.n_left >= 0 && saida.flags.minus == 0)
	{
		i = 0;
		tamanho = ft_itoa_x_log((long)n) - 1;
		if ((tamanho - saida.flags.n_right) < 0)
			tamanho -= (tamanho - saida.flags.n_right);
		while (i < (saida.flags.n_left - tamanho))
		{
			if (saida.flags.pad_zeros == 1)
				if (saida.flags.precision == 1)
					ft_pchar(' ', counter);
				else
					ft_pchar('0', counter);
			else
				ft_pchar(' ', counter);
			i++;
		}
	}
	if (debug > 2) { logging("parte2\n"); }

	if (saida.flags.precision == 1 && saida.flags.n_right >= 0)
	{
		i = 0;
		tamanho = ft_itoa_x_log((long)n) - 1;
		while (i < (saida.flags.n_right - tamanho))
		{
			ft_pchar('0', counter);
			i++;
		}
	}
	if (debug > 2) { logging("parte3\n"); }

	if (n == 0 && saida.flags.precision == 1 && saida.flags.pad_zeros == 0)
	{
		temp = ft_calloc(1, 2);
		if (saida.flags.n_right > 0)
			temp[0] = '0';
		else if (saida.flags.n_left > 0)
			temp[0] = ' ';
		ft_pstr(temp, counter);
	}
	else
	{
		temp = ft_itoa_x(n);
		ft_pstr(temp, counter);
	}
	if (debug > 2) { logging("parte4\n"); }

	if (saida.flags.n_left >= 0 && saida.flags.minus == 1)
	{
		i = 0;
		tamanho = ft_itoa_x_log((long)n) - 1;
		if ((tamanho - saida.flags.n_right) < 0)
			tamanho -= (tamanho - saida.flags.n_right);
		while (i < (saida.flags.n_left - tamanho))
		{
			if (saida.flags.pad_zeros == 1)
				ft_pchar(' ', counter);
			else
				ft_pchar(' ', counter);
			i++;
		}
	}
	
	if (debug > 2) { logging("parte5\n"); }

	free(temp);
	if (debug > 2) { logging("parte6\n"); }
	saida.estado = UNTIL_PERCENT;
	if (debug > 2) { logging("parte7\n"); }
	if (debug > 2) { logging("*counter = %d\n", *counter); }
	return (saida);
}

t_print	get_HEX(t_print print, int *counter, va_list args)
{
	t_print			saida;
	char			*temp;
	int				tamanho;
	unsigned int	n;
	//int				log;
	int				i;

	saida = print;

	/*
	if (saida.flags.n_right == -1)
	{
		saida.flags.n_right = va_arg(args, int);
		if (saida.flags.n_right < 0)
		{
			if (saida.flags.pad_zeros == 1 && saida.flags.n_left != -2)
				saida.flags.n_right = saida.flags.n_left;
			else
				saida.flags.n_right = 0;
		}
	}
	*/

	n = va_arg(args, unsigned int);
	if (debug > 2) { logging("parte1\n"); }
	if (saida.flags.n_left >= 0 && saida.flags.minus == 0)
	{
		i = 0;
		tamanho = ft_itoa_X_log((long)n) - 1;
		if ((tamanho - saida.flags.n_right) < 0)
			tamanho -= (tamanho - saida.flags.n_right);
		while (i < (saida.flags.n_left - tamanho))
		{
			if (saida.flags.pad_zeros == 1)
				if (saida.flags.precision == 1)
					ft_pchar(' ', counter);
				else
					ft_pchar('0', counter);
			else
				ft_pchar(' ', counter);
			i++;
		}
	}
	if (debug > 2) { logging("parte2\n"); }

	if (saida.flags.precision == 1 && saida.flags.n_right >= 0)
	{
		i = 0;
		tamanho = ft_itoa_X_log((long)n) - 1;
		while (i < (saida.flags.n_right - tamanho))
		{
			ft_pchar('0', counter);
			i++;
		}
	}
	if (debug > 2) { logging("parte3\n"); }

	if (n == 0 && saida.flags.precision == 1 && saida.flags.pad_zeros == 0)
	{
		temp = ft_calloc(1, 2);
		if (saida.flags.n_right > 0)
			temp[0] = '0';
		else if (saida.flags.n_left > 0)
			temp[0] = ' ';
		ft_pstr(temp, counter);
	}
	else
	{
		temp = ft_itoa_X(n);
		ft_pstr(temp, counter);
	}
	if (debug > 2) { logging("parte4\n"); }

	if (saida.flags.n_left >= 0 && saida.flags.minus == 1)
	{
		i = 0;
		tamanho = ft_itoa_X_log((long)n) - 1;
		if ((tamanho - saida.flags.n_right) < 0)
			tamanho -= (tamanho - saida.flags.n_right);
		while (i < (saida.flags.n_left - tamanho))
		{
			if (saida.flags.pad_zeros == 1)
				ft_pchar(' ', counter);
			else
				ft_pchar(' ', counter);
			i++;
		}
	}
	
	if (debug > 2) { logging("parte5\n"); }

	free(temp);
	if (debug > 2) { logging("parte6\n"); }
	saida.estado = UNTIL_PERCENT;
	if (debug > 2) { logging("parte7\n"); }
	if (debug > 2) { logging("*counter = %d\n", *counter); }
	return (saida);
}


t_print	get_char(t_print print, int *counter, va_list args)
{
	t_print	saida;
	char	temp;
	int		i;

	saida = print;
	if (saida.flags.n_left >= 0 && saida.flags.minus == 0)
	{
		i = 0;
		while (i < (saida.flags.n_left - 1))
		{
			if (saida.flags.pad_zeros == 1)
				ft_pchar('0', counter);
			else
				ft_pchar(' ', counter);
			i++;
		}
	}
	temp = va_arg(args, int);
	if (temp == 0 && 0)
	{
		saida.estado = END;
		return (saida);
	}
	else
		ft_pchar(temp, counter);
	if (saida.flags.n_left >= 0 && saida.flags.minus == 1)
	{
		i = 0;
		while (i < (saida.flags.n_left - 1))
		{
			ft_pchar(' ', counter);
			i++;
		}
	}
	saida.estado = UNTIL_PERCENT;
	return (saida);
}

t_print	get_str(t_print print, int *counter, va_list args)
{
	t_print	saida;
	char	*temp;
	int		tamanho;
	int		i;
	//int		tt;
	//int		flag;

	saida = print;


	temp = va_arg(args, char*);
	if (temp == NULL)
		temp = "(null)";
	if (saida.flags.precision == 1 && saida.flags.n_right >= 0)
		temp = ft_substr(temp, 0, saida.flags.n_right);
	else if (saida.flags.precision == 1 && saida.flags.n_right < 0)
		temp = ft_substr(temp, 0, ft_strlen(temp));
	else if (saida.flags.precision == 1)
		temp = "";
	if (saida.flags.n_left >= 0 && saida.flags.minus == 0)
	{
		i = 0;
		tamanho = ft_strlen(temp);
		while (i < (saida.flags.n_left - tamanho))
		{
			if (saida.flags.pad_zeros == 1)
				ft_pchar('0', counter);
			else
				ft_pchar(' ', counter);
			i++;
		}
	}

/*
	tt = ft_strlen(temp);
	write(1, temp, tt);
	*counter = *counter + tt;
*/

	ft_pstr(temp, counter);

	if (saida.flags.n_left >= 0 && saida.flags.minus == 1)
	{
		i = 0;
		tamanho = ft_strlen(temp);
		while (i < (saida.flags.n_left - tamanho))
		{
			ft_pchar(' ', counter);
			i++;
		}
	}
	if (saida.flags.precision == 1)
		free(temp);
	saida.estado = UNTIL_PERCENT;
	return (saida);
}

/*
t_print	get_pointer(t_print print, int *counter, va_list args)
{
	t_print			saida;
	long			temp;
	char			*out;

	saida = print;
	temp = va_arg(args, unsigned long);
	out = ft_itoa_x_ul(temp);
	*output = ft_strappend(*output, "0x");
	*output = ft_strappend(*output, out);
	free(out);
	saida.estado = UNTIL_PERCENT;
	return (saida);
}
*/

t_print	get_pointer(t_print print, int *counter, va_list args)
{
	t_print			saida;
	char			*temp;
	int				tamanho;
	//int				flag;
	unsigned long	n;
	//int				log;
	int				i;

	saida = print;

	//flag = 0;
	/*
	if (saida.flags.n_right == -1)
		saida.flags.n_right = va_arg(args, int);
	//else if (saida.flags.n_right == -2)
	*/
	//	flag = 1;

	n = va_arg(args, unsigned long);
	if (debug > 2) { logging("parte1\n"); }
	if (saida.flags.n_left >= 0 && saida.flags.minus == 0)
	{
		i = 0;
		if (n == 0 && saida.flags.precision == 1)
			tamanho = ft_itoa_x_ul_log(n) - 2 + 2;
		else
			tamanho = ft_itoa_x_ul_log(n) - 1 + 2;
		if ((tamanho - saida.flags.n_right) < 0)
			tamanho -= (tamanho - saida.flags.n_right);
		while (i < (saida.flags.n_left - tamanho))
		{
			if (saida.flags.pad_zeros == 1)
				if (saida.flags.precision == 1)
					ft_pchar(' ', counter);
				else
					ft_pchar('0', counter);
			else
				ft_pchar(' ', counter);
			i++;
		}
	}
	if (debug > 2) { logging("parte2\n"); }

	if (saida.flags.precision == 1 && saida.flags.n_right >= 0)
	{
		i = 0;
		tamanho = ft_itoa_x_ul_log(n) - 1 + 2;
		while (i < (saida.flags.n_right - tamanho))
		{
			ft_pchar('0', counter);
			i++;
		}
	}
	if (debug > 2) { logging("parte3\n"); }

	ft_pstr("0x", counter);
	temp = ft_itoa_x_ul(n);
	if (!(saida.flags.precision == 1 && n == 0))
		ft_pstr(temp, counter);

	if (debug > 2) { logging("parte4\n"); }

	if (saida.flags.n_left >= 0 && saida.flags.minus == 1)
	{
		i = 0;
		if (n == 0 && saida.flags.precision == 1)
			tamanho = ft_itoa_x_ul_log(n) - 2 + 2;
		else
			tamanho = ft_itoa_x_ul_log(n) - 1 + 2;
		if ((tamanho - saida.flags.n_right) < 0)
			tamanho -= (tamanho - saida.flags.n_right);
		while (i < (saida.flags.n_left - tamanho))
		{
			if (saida.flags.pad_zeros == 1)
				ft_pchar(' ', counter);
			else
				ft_pchar(' ', counter);
			i++;
		}
	}
	
	if (debug > 2) { logging("parte5\n"); }

	free(temp);
	if (debug > 2) { logging("parte6\n"); }
	saida.estado = UNTIL_PERCENT;
	if (debug > 2) { logging("parte7\n"); }
	if (debug > 2) { logging("*counter = %d\n", *counter); }
	return (saida);
}

t_print	get_percent(t_print print, int *counter, va_list args)
{
	t_print	saida;
	int		i;

	saida = print;
	if (saida.flags.n_right == -1)
	{
		saida.flags.n_right = va_arg(args, int);
	}

	if (saida.flags.n_left >= 0 && saida.flags.minus == 0)
	{
		i = 0;
		while (i < (saida.flags.n_left - 1))
		{
			if (saida.flags.pad_zeros == 1)
				ft_pchar('0', counter);
			else
				ft_pchar(' ', counter);
			i++;
		}
	}
	ft_pchar('%', counter);
	if (saida.flags.n_left >= 0 && saida.flags.minus == 1)
	{
		i = 0;
		while (i < (saida.flags.n_left - 1))
		{
			ft_pchar(' ', counter);
			i++;
		}
	}
	saida.estado = UNTIL_PERCENT;
	return (saida);
}

t_print	parse_flags(t_print print, int *counter, va_list args)
{
	t_print	saida;

	saida = print;
	if (debug > 0) { logging("198: saida.atual_char = '%c'; saida.p_flags.n_auxiliar = %d; saida.p_flags.estado = %d\n", saida.atual_char, saida.p_flags.n_auxiliar, saida.p_flags.estado); }
	if (saida.p_flags.estado == 1)
	{
		if (debug > 0) { logging("201: saida.atual_char = '%c'; saida.p_flags.n_auxiliar = %d; saida.p_flags.estado = %d\n", saida.atual_char, saida.p_flags.n_auxiliar, saida.p_flags.estado); }
		if (saida.atual_char == '-')
			saida.flags.minus = 1;
		else if (saida.atual_char == '.')
			saida.flags.precision = 1;
		else if (saida.atual_char == '*')
		{
			if (saida.flags.precision == 0)
			{
				//saida.flags.n_left = -1;
				saida.flags.left_asteristic  = 1;
				saida.flags.n_left = va_arg(args, int);
				saida.flags.n_left_indf = 0;
				if (saida.flags.n_left < 0)
				{
					saida.flags.minus = 1;
					saida.flags.n_left = -saida.flags.n_left;
				}
			}
			else if (saida.flags.precision == 1 && saida.flags.n_right_indf == 1)
			{
				//saida.flags.n_right = -1;
				saida.flags.right_asteristic = 1;
				saida.flags.n_right = va_arg(args, int);
				saida.flags.n_right_indf = 0;
			}
		}
		else if (saida.atual_char == '0' && saida.flags.pad_zeros != 1 &&
				saida.flags.precision == 0)
			saida.flags.pad_zeros = 1;
		else if (saida.atual_char >= '0' && saida.atual_char <= '9')
		{
			saida.p_flags.estado = 2;
			saida.p_flags.auxiliar = ft_calloc(1, 1);
			if (saida.flags.precision == 0)
				saida.p_flags.left_or_right = 1;
			else if (saida.flags.precision == 1 && saida.flags.n_right_indf == 1)
				saida.p_flags.left_or_right = 2;
			else
				saida.p_flags.left_or_right = 3;
			saida.i -= 1;
		}
		else
		{
			if (saida.flags.pad_zeros == 1 && saida.flags.n_left_indf == 1)
			{
				saida.flags.pad_zeros = 0;
				saida.flags.n_left = 0;
				saida.flags.n_left_indf = 0;
			}
			saida.estado = CHOOSE_ACTION;
			saida.i -= 1;
		}
	}
	else if (saida.p_flags.estado == 2)
	{
		if (debug > 0) { logging("235: saida.p_flags.auxiliar = '%s'\n", saida.p_flags.auxiliar); }
		if(saida.atual_char >= '0' && saida.atual_char <= '9')
			saida.p_flags.auxiliar = ft_append(saida.p_flags.auxiliar, saida.atual_char);
		else
		{
			saida.p_flags.n_auxiliar = ft_atoi(saida.p_flags.auxiliar);
			free(saida.p_flags.auxiliar);
			if (saida.p_flags.left_or_right == 1)
			{
				saida.flags.n_left      = saida.p_flags.n_auxiliar;
				saida.flags.n_left_indf = 0;
			}
			else if (saida.p_flags.left_or_right == 2)
			{
				saida.flags.n_right      = saida.p_flags.n_auxiliar;
				saida.flags.n_right_indf = 0;
			}
			saida.p_flags.estado = 1;
			saida.i -= 1;
		}
	}
	if (debug > 0) { logging("251: saida.estado = %d\n", saida.estado); }
 	return (saida);
}

t_print	choose_action(t_print print, int *counter, va_list args)
{
	t_print	saida;

	saida = print;


	if (debug > 2) { logging("260: saida.atual_char = '%c'; saida.p_flags.n_auxiliar = %d; saida.p_flags.estado = %d; saida.i = %d\n", saida.atual_char, saida.p_flags.n_auxiliar, saida.p_flags.estado, saida.i); }
	if (saida.atual_char == 'd')
		saida.estado = GET_INT;
	else if (saida.atual_char == 'i')
		saida.estado = GET_INT;
	else if (saida.atual_char == 'u')
		saida.estado = GET_UINT;
	else if (saida.atual_char == 'x')
		saida.estado = GET_hex;
	else if (saida.atual_char == 'X')
		saida.estado = GET_HEX;
	else if (saida.atual_char == 'c')
		saida.estado = GET_CHAR;
	else if (saida.atual_char == 's')
		saida.estado = GET_STR;
	else if (saida.atual_char == 'p')
		saida.estado = GET_POINTER;
	else if (saida.atual_char == '%')
		saida.estado = GET_PERCENT;
	else
		saida.estado = UNTIL_PERCENT;
	saida.i -= 1;
	if (debug > 2) { logging("272: saida.estado = %d; saida.i = %d\n", saida.estado, saida.i); }
 	return (saida);
}

t_print	until_percent(t_print print, int *counter, va_list args)
{
	t_print	saida;

	saida = print;
	if (saida.atual_char != '%')
		ft_pchar(saida.atual_char, counter);
	else
	{
		saida.flags = ft_init_flags();
		saida.p_flags.pos_inicial = saida.i;
		saida.p_flags.auxiliar = NULL;
		saida.p_flags.n_auxiliar = 0;
		saida.p_flags.estado = 1;
		saida.estado = PARSE_FLAGS;
	}
	return (saida);
}

int		ft_printf_parse(const char *str, int *counter, va_list args)
{
	t_print	print;

	print.i = 0;
	print.estado = UNTIL_PERCENT;
	if (debug > 2) { logging("301: str = '%s'\n", str); }
	while (str[print.i] != '\0')
	{
		print.atual_char = str[print.i];
		//if (debug > 2) { logging("305: *output = '%s'(%ld); print.estado = %d; print.atual_char = '%c'\n", *output, ft_strlen(*output), print.estado, print.atual_char); }
		if (print.estado == UNTIL_PERCENT)
			print = until_percent(print, counter, args);
		else if (print.estado == PARSE_FLAGS)
			print = parse_flags(print, counter, args);
		else if (print.estado == CHOOSE_ACTION)
			print = choose_action(print, counter, args);
		else if (print.estado == GET_INT)
			print = get_int(print, counter, args);
		else if (print.estado == GET_UINT)
			print = get_uint(print, counter, args);
		else if (print.estado == GET_hex)
			print = get_hex(print, counter, args);
		else if (print.estado == GET_HEX)
			print = get_HEX(print, counter, args);
		else if (print.estado == GET_CHAR)
			print = get_char(print, counter, args);
		else if (print.estado == GET_STR)
			print = get_str(print, counter, args);
		else if (print.estado == GET_POINTER)
			print = get_pointer(print, counter, args);
		else if (print.estado == GET_PERCENT)
			print = get_percent(print, counter, args);
		else if (print.estado == END)
			break;
		else
			return (-1);
		print.i += 1;
	}
	//if (debug > 2) { logging("305: *output = '%s'(%ld); print.estado = %d; print.atual_char = '%c'\n", *output, ft_strlen(*output), print.estado, print.atual_char); }
	return (0);
}

int		ft_printf(const char *str, ...)
{
	char	*output;
	int		counter;
	//int		saida;
	va_list	args;


	counter = 0;
	if (debug > 0) { logging("866: entrou aqui\n"); }

	g_string = (char *)malloc(sizeof(char) * 4450);
	g_fd = open(CAMINHO_SAIDA, O_RDWR | O_APPEND);

	if (debug > 0) { logging("871: entrou aqui\n"); }

	va_start(args, str);
	if (debug > 0) { logging("874: entrou aqui\n"); }
	output = ft_calloc(1, 1);
	if (debug > 0) { logging("876: entrou aqui\n"); }
	ft_printf_parse(str, &counter, args);
	//ft_putstr_fd(output, 1);
	free(output);
	va_end(args);

	free(g_string);
	if (g_fd != -1)
		close(g_fd);
	return (counter);
}
