/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_number.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismherna <ismherna@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 09:35:46 by ismherna          #+#    #+#             */
/*   Updated: 2024/02/27 10:48:25 by ismherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_print_number(int n)
{
	int	size;

	size = 0;
	if (n == 0)
		size += ft_print_char('0');
	if (n == -2147483648)
	{
		size += ft_print_str("-2147483648");
		return (size);
	}
	if (n < 0)
	{
		size += ft_print_char('-');
		n = -n;
	}
	if (n > 0)
		size += ft_print_unsigned((unsigned int)n);
	return (size);
}