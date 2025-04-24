/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llitoa_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismherna <ismherna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 23:55:40 by ismherna          #+#    #+#             */
/*   Updated: 2025/04/24 23:56:20 by ismherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_bonus.h"

char    *ft_lltoa_base(unsigned long long n, int base, int uppercase)
{
    char                *str;
    unsigned long long  temp = n;
    int                 len = 1;
    char                *base_chars;

    if (base < 2 || base > 16)
        return (NULL);

    if (uppercase)
        base_chars = "0123456789ABCDEF";
    else
        base_chars = "0123456789abcdef";

    while (temp /= base)
        len++;

    str = (char *)malloc(sizeof(char) * (len + 1));
    if (!str)
        return (NULL);

    str[len] = '\0';
    while (len--)
    {
        str[len] = base_chars[n % base];
        n /= base;
    }
    return (str);
}