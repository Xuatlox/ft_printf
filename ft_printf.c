/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansimonn <ansimonn@student.42angouleme.f>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 11:06:40 by ansimonn          #+#    #+#             */
/*   Updated: 2025/11/06 11:10:10 by ansimonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdio.h>

static int	ft_putnbr_unsigned(unsigned int nb)
{
	char	digit;
	int		ret;

	ret = 0;
	if (nb > 9)
	{
		ret += ft_putnbr_unsigned(nb / 10);
	}
	digit = nb % 10 + '0';
	if (write(1, &digit, 1) == -1)
		return (-1);
	return (ret + 1);
}

static int	ft_puthex(unsigned long int nbr, int maj)
{
	char	conv;
	int		ret;

	ret = 0;
	if (nbr > 15)
		ret += ft_puthex(nbr / 16, maj);
	if (nbr % 16 < 10)
		conv = '0' + nbr % 16;
	else if (maj == 1)
		conv = 'A' + nbr % 16 - 10;
	else
		conv = 'a' + nbr % 16 - 10;
	if (write(1, &conv, 1) == -1)
		return (-1);
	return (ret + 1);
}

static int	ft_putadr(unsigned long int nbr)
{
	int	ret;

	if (nbr == 0)
	{
		ret = write(1, "(nil)", 5);
		return (ret);
	}
	if (ft_putstr_fd("0x", 1) == -1)
		return (-1);
	ret = ft_puthex(nbr, 0) + 2;
	return (ret);
}

static int	ft_conversion(va_list args, const char spec)
{
	if (spec == 'c')
		return (ft_putchar_fd(va_arg(args, int), 1));
	if (spec == 's')
		return (ft_putstr_fd(va_arg(args, char *), 1));
	if (spec == 'p')
		return (ft_putadr(va_arg(args, unsigned long int)));
	if (spec == 'd' || spec == 'i')
		return (ft_putnbr_fd(va_arg(args, int), 1));
	if (spec == 'u')
		return (ft_putnbr_unsigned(va_arg(args, unsigned int)));
	if (spec == 'x')
		return (ft_puthex((unsigned int)va_arg(args, int), 0));
	if (spec == 'X')
		return (ft_puthex((unsigned int)va_arg(args, int), 1));
	if (spec == '%')
		return (ft_putchar_fd('%', 1));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		ret;
	int		tmp;

	ret = 0;
	if (!format)
		return (-1);
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			if (!format[1])
				return (ret);
			format++;
			tmp = ft_conversion(args, *format);
			if (tmp == -1)
				return (tmp);
			ret += tmp;
		}
		else
		{
			if (write(1, format, 1) == -1)
				return (-1);
			ret++;
		}
		format++;
	}
	va_end(args);
	return (ret);
}
