/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oarnoldo <oarnoldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 00:51:46 by oarnoldo          #+#    #+#             */
/*   Updated: 2022/01/11 01:22:34 by oarnoldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c, int *len)
{
	write(1, &c, 1);
	return ((*len)++);
}

int	ft_putstring(char *str, int *len)
{
	if (!str)
		str = "(null)";
	while (*str)
		ft_putchar(*str++, len);
	return (*len);
}

void	ft_putnbr(int nbr, int *length)
{
	if (nbr < 0)
	{
		nbr = -nbr;
		ft_putchar('-', length);
	}
	if (nbr == -2147483648)
	{
		ft_putchar('2', length);
		nbr = 147483648;
	}
	if (nbr < 10)
		ft_putchar(nbr + '0', length);
	else
	{
		ft_putnbr(nbr / 10, length);
		ft_putnbr(nbr % 10, length);
	}
}

void	ft_putlong(unsigned int nbr, int *length)
{
	if (nbr < 10)
		ft_putchar(nbr + '0', length);
	else
	{
		ft_putlong(nbr / 10, length);
		ft_putlong(nbr % 10, length);
	}
}

void	ft_puthex(char *str, unsigned long long nbr, int *length)
{
	if (nbr >= 16)
	{
		ft_puthex(str, nbr / 16, length);
		nbr %= 16;
	}
	if (nbr > 9 && nbr < 16)
	{
		if (*str == 'x' || *str == 'p')
			ft_putchar(nbr % 10 + 97, length);
		else
			ft_putchar(nbr % 10 + 65, length);
	}
	else
		ft_putchar(nbr + '0', length);
}
