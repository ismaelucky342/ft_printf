/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_number.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismherna <ismherna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 09:35:46 by ismherna          #+#    #+#             */
/*   Updated: 2025/03/03 00:56:14 by ismherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_print_number(int n)
{
	int	size;

	size = 0;
	if (n == 0)
		size += ft_print_char('0');
	if (n == -2147483648)
	{
		size += ft_print_str("-2147483648");
		return (size);
	}
	if (n < 0)
	{
		size += ft_print_char('-');
		n = -n;
	}
	if (n > 0)
		size += ft_print_unsigned((unsigned int)n);
	return (size);
}
