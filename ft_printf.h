/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismherna <ismherna@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 09:50:01 by ismherna          #+#    #+#             */
/*   Updated: 2024/02/27 11:02:55 by ismherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include "libft/libft.h"

int		ft_print_char(int c);
int		ft_print_str(char *str);
int		ft_print_number(int n);
int		ft_print_hex(unsigned int num, const char word);
int		ft_print_unsigned(unsigned int n);
int		ft_print_puntero(unsigned long long ptr);
int		ft_printf(const char *str, ...);

#endif
