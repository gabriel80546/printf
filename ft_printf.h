/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpassos- <gpassos-@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 22:22:14 by gpassos-          #+#    #+#             */
/*   Updated: 2021/03/19 22:22:15 by gpassos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

# define UNTIL_PERCENT 1
# define PARSE_FLAGS 2
# define CHOOSE_ACTION 3
# define GET_INT 4
# define GET_UINT 5
# define GET_HEX 6
# define GET_HEX_UP 7
# define GET_CHAR 8
# define GET_STR 9
# define GET_POINTER 10
# define GET_PERCENT 11
# define END 11

typedef struct	s_flags
{
	int			left_asteristic;
	int			right_asteristic;
	int			n_left_indf;
	int			n_right_indf;
	int			n_left;
	int			n_right;
	int			pad_zeros;
	int			minus;
	int			precision;
}				t_flags;

typedef struct	s_p_flags
{
	int			pos_inicial;
	int			estado;
	char		*aux;
	int			left_or_right;
	int			n_auxiliar;
}				t_p_flags;

typedef struct	s_print
{
	int			i;
	int			estado;
	char		atual_char;
	int			leak;
	t_p_flags	p_flags;
	t_flags		flags;
}				t_print;

typedef struct	s_cn
{
	char			*temp;
	int				i;
	int				tam;
	int				tt;
	int				troca;
	int				neg;
	int				n_i;
	unsigned int	n_ui;
	unsigned long	n_ul;
	t_print			saida;
}				t_cn;

int				ft_printf(const char *str, ...);
int				ft_printf_itoa_log(long n);
unsigned int	ft_itoa_ui_log(unsigned long n);
char			*ft_itoa_ui(unsigned int n);
int				ft_itoa_x_ul_log(unsigned long n);
char			*ft_itoa_x_ul(unsigned long n);
int				ft_itoa_x_log(unsigned long n);
char			*ft_itoa_x(unsigned int n);
char			*ft_itoa_x_upper(unsigned int n);
int				ft_itoa_x_upper_log(unsigned long n);
void			ft_pchar(char caracter, int *counter);
void			ft_pstr(char *string, int *counter);
void			ft_pnchar(char caracter, int n, int *counter);
char			*ft_append(char *str, char caracter);
t_flags			ft_init_flags(void);
t_print			until_percent(t_print print, int *counter);
t_print			get_int(t_print print, int *counter, va_list args);
t_print			get_percent(t_print print, int *counter);
t_print			get_pointer(t_print print, int *counter, va_list args);
t_print			get_str(t_print print, int *counter, va_list args);
t_print			get_char(t_print print, int *counter, va_list args);
t_print			get_hex(t_print print, int *counter, va_list args);
t_print			get_hex_up(t_print print, int *counter, va_list args);
t_print			get_uint(t_print print, int *counter, va_list args);
t_print			parse_flags(t_print print, va_list args);
t_print			parse_flags_num(t_print print);

t_cn			get_int_change_flag(t_cn input);
t_cn			get_int_neg(t_cn input);
t_cn			get_int_first_pad(t_cn input, int *counter);
t_cn			get_int_sec_pad(t_cn input, int *counter);

t_cn			get_uint_init(t_cn input);
t_cn			get_uint_change_flag(t_cn input);
t_cn			get_uint_first_pad(t_cn input, int *counter);
t_cn			get_uint_sec_pad(t_cn input, int *counter);

t_cn			get_hex_init(t_cn input);
t_cn			get_hex_change_flag(t_cn input);
t_cn			get_hex_first_pad(t_cn input, int *counter);
t_cn			get_hex_sec_pad(t_cn input, int *counter);

t_cn			get_hex_up_init(t_cn input);
t_cn			get_hex_up_change_flag(t_cn input);
t_cn			get_hex_up_first_pad(t_cn input, int *counter);
t_cn			get_hex_up_sec_pad(t_cn input, int *counter);

#endif
