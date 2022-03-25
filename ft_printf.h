/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oarnoldo <oarnoldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 00:27:32 by oarnoldo          #+#    #+#             */
/*   Updated: 2022/01/11 01:22:23 by oarnoldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int		ft_putchar(char c, int *len);
int		ft_putstring(char *str, int *len);
void	ft_putnbr(int nbr, int *len);
void	ft_putlong(unsigned int nbr, int *length);
void	ft_puthex(char *str, unsigned long long nbr, int *length);
int		ft_printf(const char *format, ...);

#endif
