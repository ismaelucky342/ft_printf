/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismherna <ismherna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 23:32:50 by ismherna          #+#    #+#             */
/*   Updated: 2025/04/24 23:53:33 by ismherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_bonus.h"
#include <stdarg.h>

int ft_printf(const char *format, ...)
{
    va_list args;
    int     total_length = 0;
    t_format fmt;

    va_start(args, format);

    while (*format)
    {
        if (*format == '%')
        {
            format++;
            fmt.flag_minus = 0;
            fmt.flag_zero = 0;
            fmt.flag_plus = 0;
            fmt.flag_space = 0;
            fmt.flag_hash = 0;
            fmt.width = 0;
            fmt.precision = -1;
            fmt.has_precision = 0;
            fmt.specifier = '\0';

            format = parse_format(format, &fmt, args);
            total_length += handle_conversion(&fmt, args);
        }
        else
        {
            total_length += ft_putchar(*format);
            format++;
        }
    }

    va_end(args);
    return (total_length);
}

int handle_conversion(t_format *fmt, va_list args)
{
    int length = 0;

    if (fmt->specifier == 'c')
        length = print_char(fmt, args);
    else if (fmt->specifier == 's')
        length = print_string(fmt, args);
    else if (fmt->specifier == 'd' || fmt->specifier == 'i')
        length = print_int(fmt, args);
    else if (fmt->specifier == 'u')
        length = print_unsigned(fmt, args);
    else if (fmt->specifier == 'x')
        length = print_hex(fmt, args, 0);
    else if (fmt->specifier == 'X')
        length = print_hex(fmt, args, 1);
    else if (fmt->specifier == 'p')
        length = print_pointer(fmt, args);
    else if (fmt->specifier == 'f')
        length = print_float(fmt, args);
    else if (fmt->specifier == 'l')
        length = print_long(fmt, args);
    else if (fmt->specifier == 'll')
        length = print_long_long(fmt, args);
    else if (fmt->specifier == '%')
        length = ft_putchar('%');
    return (length);
}
