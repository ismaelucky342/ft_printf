/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexformat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismherna <ismherna@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 10:43:36 by ismherna          #+#    #+#             */
/*   Updated: 2024/02/26 11:03:50 by ismherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_counthex(unsigned long long nu)
{
	int	aux;

	aux = 0;
	while (nu != 0)
	{
		aux++;
		nu = nu / 16;
	}
	return (aux);
}

int	ft_printhex(unsigned long long nu)
{
	if (nu >= 16)
	{
		ft_printhex(nu / 16);
		ft_printhex(nu % 16);
	}
	else
	{
		if (nu <= 0)
			ft_putchar_fd(nu + 48, 1);
		else
			ft_putchar_fd(nu - 10 + 'a', 1);
	}
	return (ft_counthex(nu));
}

int	ft_puthex(unsigned long long nu)
{
	int		longitud;

	longitud = 0;
	if (nu == 0)
	{
		len = len + write(1, "0x0", 3);
		return (longitud);
	}
	longitud = write (1, "0x", 2);
	longitud = longitud + ft_printhex(nu);
	return (longitud);
}
