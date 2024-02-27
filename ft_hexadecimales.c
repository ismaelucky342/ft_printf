/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexadecimales.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismherna <ismherna@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 09:35:46 by ismherna          #+#    #+#             */
/*   Updated: 2024/02/27 10:48:25 by ismherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	ft_buscar_hex(unsigned int num, const char word);
static	int	ft_longitud_hex(unsigned int num);

int	ft_print_hex(unsigned int num, const char word)
{
	if (num == 0)
		return (ft_print_char('0'));
	else
		ft_buscar_hex (num, word);
	return (ft_longitud_hex(num));
}

static	void	ft_buscar_hex(unsigned int num, const char word)
{
	if (num >= 16)
	{
		ft_buscar_hex(num / 16, word);
		ft_buscar_hex(num % 16, word);
	}
	else
	{
		if (num < 10)
			ft_print_char (num + '0');
		else
		{
			if (word == 'x')
				ft_print_char(num - 10 + 'a');
			if (word == 'X')
				ft_print_char(num - 10 + 'A');
		}
	}
}

static	int	ft_longitud_hex(unsigned int num)
{
	int		longitud;

	longitud = 0;
	while (num != 0)
	{
		longitud ++;
		num /= 16;
	}
	return (longitud);
}
