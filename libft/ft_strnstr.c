/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 10:59:16 by gpassos-          #+#    #+#             */
/*   Updated: 2021/03/05 12:52:38 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *l, size_t len)
{
	size_t	i;

	if (ft_strlen(l) == 0)
		return ((char *)big);
	i = 0;
	while (*(big + i) != '\0' && i < len)
	{
		if (*(big + i) == *(l + 0))
		{
			if (ft_strncmp(((char *)big + i), l, ft_strlen(l)) == 0)
			{
				if ((i + ft_strlen(l)) > len)
					return (NULL);
				else
					return ((char *)big + i);
			}
		}
		i++;
	}
	return (NULL);
}
