/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 08:33:30 by gabriel           #+#    #+#             */
/*   Updated: 2021/03/09 10:32:56 by gabriel          ###   ########.fr       */
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
	int			min_width;
	int			max_width;
	int			pad_zeros;
	int			minus;
	int			asteristc;
}				t_flags;

typedef struct	s_choose
{
	int			pos_inicial;
	int			estado;
	char		*auxiliar;
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