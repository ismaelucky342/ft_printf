/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismherna <ismherna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 09:35:46 by ismherna          #+#    #+#             */
/*   Updated: 2025/03/03 00:56:46 by ismherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_print_unsigned(unsigned int n)
{
	int	size;

	size = 0;
	if (n == 0)
		size += ft_print_char('0');
	else
	{
		if (n / 10 != 0)
			ft_print_unsigned(n / 10);
		ft_print_char((n % 10) + '0');
		while (n > 0)
		{
			n /= 10;
			size++;
		}
	}
	return (size);
}
