/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 08:33:30 by gabriel           #+#    #+#             */
/*   Updated: 2021/03/10 09:27:17 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

# define UNTIL_PERCENT 1
# define CHOOSE_ACTION 2
# define GET_NUMBER 3
# define GET_STR 4

typedef struct	s_flags
{
	int			n_left;
	int			n_right;
	int			pad_zeros;
	int			minus;
	int			precision;
	int			asteristc_l;
	int			asteristc_r;
}				t_flags;

typedef struct	s_choose
{
	int			pos_inicial;
	int			estado;
	char		*auxiliar;
	int			left_or_right;
	int			n_auxiliar;
}				t_choose;

typedef struct	s_print
{
	int			i;
	int			estado;
	char		atual_char;
	t_choose	choose;
	t_flags		flags;
}				t_print;

int		ft_printf(const char *, ...);

#endif