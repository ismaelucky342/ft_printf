/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismherna <ismherna@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 10:04:10 by ismherna          #+#    #+#             */
/*   Updated: 2024/02/26 10:49:11 by ismherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_printf_str(char *str)
{
	int		aux;

	aux = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (*str)
	{
		aux += ft_puthcar(*str);
		str++;
	}
	return (aux);
}
