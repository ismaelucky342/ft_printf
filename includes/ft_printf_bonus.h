/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismherna <ismherna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 23:37:34 by ismherna          #+#    #+#             */
/*   Updated: 2025/04/24 23:55:14 by ismherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/*====================================INCLUDES==============================*/

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

/*====================================STRUCTURE==============================*/

typedef struct s_format
{
    int     flag_minus;
    int     flag_zero;
    int     flag_plus;
    int     flag_space;
    int     flag_hash;
    int     width;
    int     precision;
    int     has_precision;
    char    specifier;
}   t_format;

/*====================================PROTOTYPES=============================*/

// ft_printf main function
int     ft_printf(const char *format, ...);

// Parser functions
const char  *parse_format(const char *str, t_format *fmt, va_list args);
const char  *parse_flags(const char *str, t_format *fmt);
const char  *parse_width(const char *str, t_format *fmt, va_list args);
const char  *parse_precision(const char *str, t_format *fmt, va_list args);
const char  *parse_specifier(const char *str, t_format *fmt);

// Print functions
int     handle_conversion(t_format *fmt, va_list args);
int     print_char(t_format *fmt, va_list args);
int     print_string(t_format *fmt, va_list args);
int     print_pointer(t_format *fmt, va_list args);
int     print_number(t_format *fmt, va_list args);

// Aux functions
int     ft_putchar(char c);
int     ft_putstr(char *s);
int     ft_strlen(const char *s);
char    *ft_itoa(int n);
char    *ft_uitoa(unsigned int n);
char    *ft_itoa_base(unsigned long n, int base, int uppercase);

#endif
