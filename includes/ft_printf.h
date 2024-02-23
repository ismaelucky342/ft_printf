/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismherna <ismherna@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 18:41:02 by ismherna          #+#    #+#             */
/*   Updated: 2024/02/22 20:43:21 by ismherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifdef FT_PRINTF_H
#define FT_PRINTF_H 

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

/*-----------Flags------------*/
typedef	struct	s_flags 
{
	int		spec; 
	int		zero; 
	int		star; 
	int		width; 
	int		left; 
	int		precision; 
	int		hash; 
	int		space; 
	int		plus; 
}			t_flags;

t_flags	ft_flags_init(void);
t_flags	ft_flag_left(t_flags	flags);
t_flags ft_flag_digit(char c, t_flags flags);
t_flags ft_flag_width(va_list args, t_flags flags);
int	ft_flag_precision(const	char *str, int	pos,
	   	va_list	args, t_flags *flags);

/*----------My-Printf---------*/
int		ft_printf(const char *format, ...);
int		ft_print_arg(char type, va_list args, t_flags flags);

/*----Printf--Specifirers-----*/
//para %c
int		ft_print_char(char	c, t_flags	flags);
int		ft_print_c(char c);

//imprimir punteros 
int		ft_print_ptr(unsigned long int n, t_flags flags);
int		ft_print_p(unsigned long int n);
void	ft_prrint_adr(unsigned long int n);

//para %s 
int		ft_print_str(const	char *str, t_flags flags)
int		ft_print_s(const char *str);
int		ft_print_s_pre(const char *str, int precision);

//nummeros hexadecimales 
int		ft_print_hex(unsigned int n, int is_upper, t_flags flags);
int		ft_print_x(char	*nbstr, int	n, int is_upper, t_flags flags);
int		ft_print_hexadec(char *nbstr, int n, int is_upper, t_flags flags);
//enteros y signos 
int		ft_print_sign_pre(int	n, t_flags *flags);
int		ft_print_i(char	*nbstr, int n, t_flags flags);
int		ft_print_integer(char *nbstr, int n, t_flags flags);
int		ft_print_int(int n, t_flags flags);

//enteros sin signo 
int		ft_print_unsigned(unsigned int n, t_flags flags);
int		ft_print_u(char *nbstr, t_flags flags);
int 	ft_print_unint(char *nbstr, t_flags flags);

/*-------Helper---Functions---*/
/*------Flag---Functions------*/
