/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puntero.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismherna <ismherna@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 09:48:43 by ismherna          #+#    #+#             */
/*   Updated: 2024/02/27 10:29:54 by ismherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_longitud_puntero(unsigned long long ptr);
static void	ft_buscar_puntero(unsigned long long ptr);

int	ft_print_puntero(unsigned long long ptr)
{
	int	size;

	size = 0;
	size += ft_print_str("0x");
	if (ptr == 0)
		size += ft_print_char('0');
	else
	{
		ft_buscar_puntero(ptr);
		size += ft_longitud_puntero(ptr);
	}
	return (size);
}

static int	ft_longitud_puntero(unsigned long long ptr)
{
	int	len;

	len = 0;
	while (ptr > 0)
	{
		len++;
		ptr /= 16;
	}
	return (len);
}

static void	ft_buscar_puntero(unsigned long long ptr)
{
	if (ptr >= 16)
	{
		ft_buscar_puntero(ptr / 16);
		ft_buscar_puntero(ptr % 16);
	}
	else
	{
		if (ptr < 10)
			ft_print_char(ptr + '0');
		else
			ft_print_char(ptr - 10 + 'a');
	}
}
