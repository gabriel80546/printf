
#include "ft_printf.h"

int	ft_itoa_x_upper_log(unsigned long n)
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

char		*ft_itoa_x_upper(unsigned int n)
{
	char	*saida;
	int		contador;
	char	temp;

	saida = (char *)malloc(sizeof(char) * ft_itoa_x_upper_log(n));
	if (saida == NULL)
		return (NULL);
	*(saida + 0) = '-';
	contador = (ft_itoa_x_upper_log(n) - 1);
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
