/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismherna <ismherna@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 09:14:11 by ismherna          #+#    #+#             */
/*   Updated: 2024/02/27 09:35:04 by ismherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_unsigned(unsigned int n)
{
	int		i;

	i = 0;
	if (n == 0)
		i += ft_print_char('0');
	else
	{
		if (n / 10 != 0)
			ft_print_unsigned(n / 10);
		ft_print_char((n % 10) + '0');
		while (n > 0)
		{
			n /= 10;
			i++;
		}
	}
	return (i);
}
