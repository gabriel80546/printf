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

t_flags	ft_init_flags(void)
{
	t_flags saida;

	saida.left_asteristic = 0;
	saida.right_asteristic = 0;
	saida.n_left_indf = 1;
	saida.n_right_indf = 1;
	saida.n_left = 0;
	saida.n_right = 0;
	saida.pad_zeros = 0;
	saida.minus = 0;
	saida.precision = 0;
	return (saida);
}

int	ft_printf_itoa_log(long n)
{
	int	contador;
	int	temp;

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
	unsigned int	contador;
	unsigned int	temp;

	contador = 0;
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
	int	contador;
	int	temp;

	contador = 0;
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
	int	contador;
	int	temp;

	contador = 0;
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
	while (i < n)
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
		if (troca == 1)
			tamanho += neg;
		ft_pnchar('0', saida.flags.n_right - tamanho, counter);
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
	int				tt;


	saida = print;
	n = va_arg(args, unsigned int);
	tt = 0;
	if (saida.flags.n_right == 0 && saida.flags.n_left == 0 && saida.flags.right_asteristic == 1 && n == 0)
		tt = 1;
	if (saida.flags.n_right < 0)
	{
		if ((saida.flags.pad_zeros == 1 && saida.flags.minus != 1) && saida.flags.n_left_indf == 0)
			saida.flags.n_right = saida.flags.n_left;
	}
	if (saida.flags.n_left >= 0 && saida.flags.minus == 0)
	{
		i = 0;
		tamanho = ft_printf_itoa_log((long)n) - 1;
		if ((tamanho - saida.flags.n_right) < 0)
			tamanho -= (tamanho - saida.flags.n_right);
		while (i < (saida.flags.n_left - tamanho))
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
	if (saida.flags.precision == 1 && saida.flags.n_right >= 0)
	{
		i = 0;
		tamanho = ft_printf_itoa_log((long)n) - 1;
		ft_pnchar('0', saida.flags.n_right - tamanho, counter);
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
				temp = ft_itoa_ui(n);
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
		ft_pnchar(' ',saida.flags.n_left - tamanho, counter); 
	}
	free(temp);
	saida.estado = UNTIL_PERCENT;
	return (saida);
}

t_print	get_hex(t_print print, int *counter, va_list args)
{
	t_print			saida;
	char			*temp;
	unsigned int	n;
	int				i;
	int				tamanho;
	int				tt;


	saida = print;
	n = va_arg(args, unsigned int);
	tt = 0;
	if (saida.flags.n_right == 0 && saida.flags.n_left == 0 && saida.flags.right_asteristic == 1 && n == 0)
		tt = 1;
	if (saida.flags.n_right < 0)
	{
		if ((saida.flags.pad_zeros == 1 && saida.flags.minus != 1) && saida.flags.n_left_indf == 0)
			saida.flags.n_right = saida.flags.n_left;
	}
	if (saida.flags.n_left >= 0 && saida.flags.minus == 0)
	{
		i = 0;
		tamanho = ft_itoa_x_log((long)n) - 1;
		if ((tamanho - saida.flags.n_right) < 0)
			tamanho -= (tamanho - saida.flags.n_right);
		while (i < (saida.flags.n_left - tamanho))
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
	if (saida.flags.precision == 1 && saida.flags.n_right >= 0)
	{
		i = 0;
		tamanho = ft_itoa_x_log((long)n) - 1;
		ft_pnchar('0', saida.flags.n_right - tamanho, counter);
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
				temp = ft_itoa_x(n);
				ft_pstr(temp, counter);
			}
		}
	}
	if (saida.flags.n_left >= 0 && saida.flags.minus == 1)
	{
		i = 0;
		tamanho = ft_itoa_x_log((long)n) - 1;
		if ((tamanho - saida.flags.n_right) < 0)
			tamanho -= (tamanho - saida.flags.n_right);
		ft_pnchar(' ',saida.flags.n_left - tamanho, counter); 
	}
	free(temp);
	saida.estado = UNTIL_PERCENT;
	return (saida);
}

t_print	get_HEX(t_print print, int *counter, va_list args)
{
	t_print			saida;
	char			*temp;
	unsigned int	n;
	int				i;
	int				tamanho;
	int				tt;

	saida = print;
	n = va_arg(args, unsigned int);

	tt = 0;
	if (saida.flags.n_right == 0 && saida.flags.n_left == 0 && saida.flags.right_asteristic == 1 && n == 0)
		tt = 1;
	if (saida.flags.n_right < 0)
	{
		if ((saida.flags.pad_zeros == 1 && saida.flags.minus != 1) && saida.flags.n_left_indf == 0)
			saida.flags.n_right = saida.flags.n_left;
	}
	if (saida.flags.n_left >= 0 && saida.flags.minus == 0)
	{
		i = 0;
		tamanho = ft_itoa_X_log((long)n) - 1;
		if ((tamanho - saida.flags.n_right) < 0)
			tamanho -= (tamanho - saida.flags.n_right);
		while (i < (saida.flags.n_left - tamanho))
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
	if (saida.flags.precision == 1 && saida.flags.n_right >= 0)
	{
		i = 0;
		tamanho = ft_itoa_X_log((long)n) - 1;
		ft_pnchar('0', saida.flags.n_right - tamanho, counter);
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
				temp = ft_itoa_X(n);
				ft_pstr(temp, counter);
			}
		}
	}
	if (saida.flags.n_left >= 0 && saida.flags.minus == 1)
	{
		i = 0;
		tamanho = ft_itoa_X_log((long)n) - 1;
		if ((tamanho - saida.flags.n_right) < 0)
			tamanho -= (tamanho - saida.flags.n_right);
		ft_pnchar(' ',saida.flags.n_left - tamanho, counter); 
	}
	free(temp);
	saida.estado = UNTIL_PERCENT;
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


t_print	get_pointer(t_print print, int *counter, va_list args)
{
	t_print			saida;
	char			*temp;
	int				tamanho;
	unsigned long	n;
	int				i;

	saida = print;
	n = va_arg(args, unsigned long);
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
	ft_pstr("0x", counter);
	if (saida.flags.precision == 1 && saida.flags.n_right >= 0)
	{
		i = 0;
		tamanho = ft_itoa_x_ul_log(n) - 1 + 0;
		while (i < (saida.flags.n_right - tamanho))
		{
			ft_pchar('0', counter);
			i++;
		}
	}

	temp = ft_itoa_x_ul(n);
	if (!(saida.flags.precision == 1 && saida.flags.n_right <= 0 && n == 0))
		ft_pstr(temp, counter);
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
	free(temp);
	saida.estado = UNTIL_PERCENT;
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

t_print	parse_flags(t_print print, va_list args)
{
	t_print	saida;

	saida = print;
	if (saida.p_flags.estado == 1)
	{
		if (saida.atual_char == '-')
			saida.flags.minus = 1;
		else if (saida.atual_char == '.')
			saida.flags.precision = 1;
		else if (saida.atual_char == '*')
		{
			if (saida.flags.precision == 0)
			{
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
		if (saida.atual_char >= '0' && saida.atual_char <= '9')
		{
			saida.p_flags.auxiliar = ft_append(saida.p_flags.auxiliar, saida.atual_char);
			saida.leak = 1;
		}
		else
		{
			saida.p_flags.n_auxiliar = ft_atoi(saida.p_flags.auxiliar);
			free(saida.p_flags.auxiliar);
			saida.leak = 0;
			if (saida.p_flags.left_or_right == 1)
			{
				saida.flags.n_left = saida.p_flags.n_auxiliar;
				saida.flags.n_left_indf = 0;
			}
			else if (saida.p_flags.left_or_right == 2)
			{
				saida.flags.n_right = saida.p_flags.n_auxiliar;
				saida.flags.n_right_indf = 0;
			}
			saida.p_flags.estado = 1;
			saida.i -= 1;
		}
	}
 	return (saida);
}

t_print	choose_action(t_print print)
{
	t_print	saida;

	saida = print;
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
 	return (saida);
}

t_print	until_percent(t_print print, int *counter)
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
	print.leak = 0;
	while (str[print.i] != '\0')
	{
		print.atual_char = str[print.i];
		if (print.estado == UNTIL_PERCENT)
			print = until_percent(print, counter);
		else if (print.estado == PARSE_FLAGS)
			print = parse_flags(print, args);
		else if (print.estado == CHOOSE_ACTION)
			print = choose_action(print);
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
	if (print.leak == 1)
		free(print.p_flags.auxiliar);
	return (0);
}

int		ft_printf(const char *str, ...)
{
	char	*output;
	int		counter;
	va_list	args;

	counter = 0;
	va_start(args, str);
	output = ft_calloc(1, 1);
	ft_printf_parse(str, &counter, args);
	free(output);
	va_end(args);

	return (counter);
}
