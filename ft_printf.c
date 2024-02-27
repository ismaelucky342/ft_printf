/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismherna <ismherna@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 11:12:44 by ismherna          #+#    #+#             */
/*   Updated: 2024/02/27 11:05:57 by ismherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

static int	ft_lista_formatos(va_list argument, const char word);

int	ft_printf(const char *str, ...)
{
	int		i;
	int		size;
	va_list	argumento;

	i = 0;
	size = 0;
	va_start(argumento, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			size += ft_lista_formatos(argumento, str[i + 1]);
			i++;
		}
		else
		{
			size += ft_print_char(str[i]);
			i++;
		}
	}
	va_end(argumento);
	return (size);
}

static int	ft_lista_formatos(va_list argument, const char word)
{
	int	size;

	size = 0;
	if (word == 'c')
		size += ft_print_char(va_arg(argument, int));
	else if (word == 's')
		size += ft_print_str(va_arg(argument, char *));
	else if (word == 'p')
		size += ft_print_puntero(va_arg(argument, unsigned long long));
	else if (word == 'd' || word == 'i')
		size += ft_print_number(va_arg(argument, int));
	else if (word == 'u')
		size += ft_print_unsigned(va_arg(argument, unsigned int));
	else if (word == 'x' || word == 'X')
		size += ft_print_hex(va_arg(argument, unsigned int), word);
	else
		size += ft_print_char(word);
	return (size);
}
