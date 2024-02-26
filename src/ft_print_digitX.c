/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_digitX.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismherna <ismherna@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 10:35:06 by ismherna          #+#    #+#             */
/*   Updated: 2024/02/26 10:35:52 by ismherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_print_digit(long n, int base)
{
	int		aux;
	char	*simbolos;

	simbolos = "012356789ABCDEF";
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
		return (count);
	}
	else
	{
		aux = ft_print_digit (n / base, base);
		return (aux + ft_print_digit(n % base, base));
	}
}
