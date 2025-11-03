/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansimonn <ansimonn@student.42angouleme.f>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 11:06:40 by ansimonn          #+#    #+#             */
/*   Updated: 2025/11/03 16:07:39 by ansimonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

static int	ft_putnbr_hex(unsigned int nbr, int ind)
{
	char	conv;
	int		ret;

	ret = 0;
	if (ind == 2)
	{
		ind = 0;
		if (ft_putstr_fd("0x", 1) == -1)
			return (-1);
		ret += 2;
	}
	if (nbr > 16)
		ret += ft_putnbr_hex(nbr / 16, ind);
	if (nbr % 16 < 10)
		conv = '0' + nbr % 16;
	else if (ind == 1)
		conv = 'A' + nbr % 16 - 10;
	else
		conv = 'a' + nbr % 16 - 10;
	if (write(1, &conv, 1) == -1)
		return (-1);
	ret++;
	return (ret);
}

static int	ft_conversion(va_list args, const char spec)
{
	if (spec == 'c')
	 	return (ft_putchar_fd(va_arg(args, int), 1));
	if (spec == 's')
	 	return (ft_putstr_fd(va_arg(args, char *), 1));
	if (spec == 'p')
	 	return (ft_putnbr_hex(va_arg(args, unsigned int), 2));
	if (spec == 'd' || spec == 'i')
	 	return (ft_putnbr_fd(va_arg(args, int), 1));
	if (spec == 'u')
	 	return (ft_putnbr_unsigned(va_arg(args, unsigned int)));
	if (spec == 'x')
	 	return (ft_putnbr_hex(va_arg(args, int), 0));
	if (spec == 'X')
	 	return (ft_putnbr_hex(va_arg(args, int), 1));
	if (spec == '%')
	 	return (ft_putchar_fd('%', 1));
	return (0);
}

int ft_printf(const char *format, ...)
{
	va_list args;
	int		ret;
	int		tmp;

	ret = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
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
