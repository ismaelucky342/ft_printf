/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismherna <ismherna@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 10:04:10 by ismherna          #+#    #+#             */
/*   Updated: 2024/02/27 09:13:57 by ismherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_print_str(char *str)
{
	int	count;

	count = 0;
	if (str == 0)
	{
		return (ft_print_str("(null)"));
	}
	while (str[count])
	{
		count += ft_print_char(str[count]);
	}
	return (count);
}
