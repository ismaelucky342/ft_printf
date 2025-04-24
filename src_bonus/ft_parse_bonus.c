/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismherna <ismherna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 23:36:06 by ismherna          #+#    #+#             */
/*   Updated: 2025/04/24 23:58:38 by ismherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_bonus.h"

const char *parse_format(const char *str, t_format *fmt, va_list args)
{
    str = parse_flags(str, fmt);
    str = parse_width(str, fmt, args);

    if (*str == '.')
    {
        fmt->has_precision = 1;
        str = parse_precision(str + 1, fmt, args);
    }
    str = parse_specifier(str, fmt);

    return (str);
}

const char *parse_flags(const char *str, t_format *fmt)
{
    while (*str == '-' || *str == '0' || *str == '+' || *str == ' ' || *str == '#')
    {
        if (*str == '-')
            fmt->flag_minus = 1;
        else if (*str == '0')
            fmt->flag_zero = 1;
        else if (*str == '+')
            fmt->flag_plus = 1;
        else if (*str == ' ')
            fmt->flag_space = 1;
        else if (*str == '#')
            fmt->flag_hash = 1;
        str++;
    }
    return (str);
}

const char *parse_width(const char *str, t_format *fmt, va_list args)
{
    if (*str == '*')
    {
        fmt->width = va_arg(args, int);
        if (fmt->width < 0)
        {
            fmt->flag_minus = 1;
            fmt->width = -fmt->width;
        }
        str++;
    }
    else if (isdigit(*str))
    {
        fmt->width = 0;
        while (isdigit(*str))
            fmt->width = (fmt->width * 10) + (*str++ - '0');
    }
    return (str);
}

const char *parse_precision(const char *str, t_format *fmt, va_list args)
{
    if (*str == '*')
    {
        fmt->precision = va_arg(args, int);
        str++;
    }
    else if (isdigit(*str))
    {
        fmt->precision = 0;
        while (isdigit(*str))
            fmt->precision = (fmt->precision * 10) + (*str++ - '0');
    }
    else
        fmt->precision = 0;
    fmt->has_precision = 1;
}

const char *parse_specifier(const char *str, t_format *fmt)
{
    if (*str)
    {
        fmt->specifier = *str;
        str++;
    }
    return (str);
}