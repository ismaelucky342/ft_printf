/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexadecimals.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismherna <ismherna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 09:35:46 by ismherna          #+#    #+#             */
/*   Updated: 2025/03/03 00:56:28 by ismherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_length_hex(unsigned int num);
static void	ft_search_hex(unsigned int num, const char word);

int	ft_print_hex(unsigned int num, const char word)

{
	if (num == 0)
		return (ft_print_char('0'));
	else
		ft_search_hex(num, word);
	return (ft_length_hex(num));
}

static void	ft_search_hex(unsigned int num, const char word)
{
	if (num >= 16)
	{
		ft_search_hex(num / 16, word);
		ft_search_hex(num % 16, word);
	}
	else
	{
		if (num < 10)
			ft_print_char(num + '0');
		else
		{
			if (word == 'x')
				ft_print_char(num - 10 + 'a');
			if (word == 'X')
				ft_print_char(num - 10 + 'A');
		}
	}
}

static int	ft_length_hex(unsigned int num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}
