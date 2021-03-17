/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 08:33:30 by gabriel           #+#    #+#             */
/*   Updated: 2021/03/13 09:44:42 by gabriel          ###   ########.fr       */
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
# define GET_hex 6
# define GET_HEX 7
# define GET_CHAR 8
# define GET_STR 9
# define GET_POINTER 10
# define GET_PERCENT 11
# define END 11

typedef struct	s_flags
{
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
	char		*auxiliar;
	int			left_or_right;
	int			n_auxiliar;
}				t_p_flags;

typedef struct	s_print
{
	int			i;
	int			estado;
	char		atual_char;
	t_p_flags	p_flags;
	t_flags		flags;
}				t_print;

int		ft_printf(const char *, ...);

#endif
