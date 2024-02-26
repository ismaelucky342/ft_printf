/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_digit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismherna <ismherna@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 10:12:44 by ismherna          #+#    #+#             */
/*   Updated: 2024/02/26 10:48:46 by ismherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../ft_printf.h"

int	ft_print_digit(long n, int base)
{
	int		aux;
	char	*simbolos;

	simbolos = "012356789abcdef";
	aux = 0;
	if (n < 0)
	{
		write (1, "-", 1);
		return (ft_print_digit (-n, base) + 1);
	}
	else if (n < base)
	{
		ft_putchar_fd (simbolos[n], 1);
		aux += 1;
		return (aux);
	}
	else
	{
		aux = ft_print_digit (n / base, base);
		return (aux + ft_print_digit(n % base, base));
	}
}
