/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismherna <ismherna@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 09:50:01 by ismherna          #+#    #+#             */
/*   Updated: 2024/02/26 09:50:09 by ismherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include "libft/libft.h"

int		ft_print_char(int c);
int		ft_print_str(char *str);
int		ft_print_digit(long n, int base);
int		ft_print_digitx(long n, int base);
int		ft_print_u(unsigned int n);
int		ft_putpoi(unsigned long long ptr);
int		ft_printf(const char *format, ...);

#endif
