/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismherna <ismherna@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 11:12:44 by ismherna          #+#    #+#             */
/*   Updated: 2024/02/26 12:49:17 by ismherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../ft_printf.h"

int	ft_print_formats(char espec, va_list ap)
{
	int	aux;

	aux = 0;
	if (espec == 'c')
		aux = ft_print_char(va_arg(ap, int));
	else if (espec == 's')
		aux += ft_print_str(va_arg(ap, char *));
	else if (espec == 'd')
		aux += ft_print_digit((long)(va_arg(ap, int)), 10);
	else if (espec == 'i')
		aux += ft_print_digit((long)(va_arg(ap, int)), 10);
	else if (espec == 'x')
		aux += ft_print_digit((long)(va_arg(ap, unsigned int)), 16);
	else if (espec == 'X')
		aux += ft_print_digitx((long)(va_arg(ap, unsigned int)), 16);
	else if (espec == 'u')
		aux += ft_print_digit((long)(va_arg(ap, unsigned int)), 10);
	else if (espec == 'p')
		aux += ft_puthex(va_arg(ap, unsigned long long));
	else
		aux += write(1, &espec, 1);
	return (aux);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		aux;

	va_start(ap, format);
	if (!format)
		return (-1);
	aux = 0;
	while (*format != '\0')
	{
		if (*format == '%')
			aux += ft_print_formats(*(++format), ap);
		else
			aux += ft_print_char(*format);
		++format;
	}
	va_end(ap);
	return (aux);
}
