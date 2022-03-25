/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oarnoldo <oarnoldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 00:23:27 by oarnoldo          #+#    #+#             */
/*   Updated: 2022/01/11 01:22:30 by oarnoldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	type_choice(char *str, va_list ap, int *len)
{
	if (*str == 'c')
		ft_putchar((char) va_arg(ap, int), len);
	else if (*str == 's')
		ft_putstring((char *)va_arg(ap, char *), len);
	else if (*str == 'd' || *str == 'i')
		ft_putnbr((int) va_arg(ap, int), len);
	else if (*str == 'u')
		ft_putlong(va_arg(ap, unsigned int), len);
	else if (*str == 'x' || *str == 'X')
		ft_puthex(str, va_arg(ap, unsigned int), len);
	else if (*str == 'p')
	{
		ft_putstring("0x", len);
		ft_puthex(str, va_arg(ap, unsigned long long), len);
	}
	else
		ft_putchar(*str, len);
}

int	ft_printf(const char *str, ...)
{
	int		len;
	va_list	ap;

	len = 0;
	va_start(ap, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			type_choice((char *)str, ap, &len);
			str++;
		}
		else
			ft_putchar(*str++, &len);
	}
	va_end(ap);
	return (len);
}
