/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansimonn <ansimonn@student.42angouleme.f>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 11:06:40 by ansimonn          #+#    #+#             */
/*   Updated: 2025/10/29 17:35:05 by ansimonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft/libft.h"

static void	ft_putnbr_unsigned(unsigned int nb)
{
	char	digit;

	if (nb > 9)
	{
		ft_putnbr_unsigned(nb / 10);
	}
	digit = nb % 10 + '0';
	write(1, &digit, 1);
}

static void	ft_putnbr_hex(unsigned long int nbr, int ind)
{
	char	conv;
	if (ind == 2)
	{
		ind = 0;
		ft_putstr_fd("0x", 1);
	}
	if (nbr < 0)
	{
		nbr = -nbr;
	}
	if (nbr > 16)
		ft_putnbr_hex(nbr / 16, ind);
	if (nbr % 16 < 10)
		conv = '0' + nbr % 16;
	else if (ind == 1)
		conv = 'A' + nbr % 16 - 10;
	else
		conv = 'a' + nbr % 16 - 10;
	write(1, &conv, 1);
}

static int	ft_conversion(va_list args, const char spec)
{
	if (spec == 'c')
	 	ft_putchar_fd(va_arg(args, int), 1);
	 else if (spec == 's')
	 	ft_putstr_fd(va_arg(args, char *), 1);
	 else if (spec == 'p')
	 	ft_putnbr_hex((unsigned long int) va_arg(args, void *), 2);
	 else if (spec == 'd' || spec == 'i')
	 	ft_putnbr_fd(va_arg(args, int), 1);
	 else if (spec == 'u')
	 	ft_putnbr_unsigned(va_arg(args, unsigned int));
	 else if (spec == 'x')
	 	ft_putnbr_hex(va_arg(args, int), 0);
	 else if (spec == 'X')
	 	ft_putnbr_hex(va_arg(args, int), 1);
	 else if (spec == '%')
	 	ft_putchar_fd('%', 1);
	return (0);
}

int ft_printf(const char *format, ...)
{
	va_list args;
	int		ret;
	int		i;

	i = 0;
	ret = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			format++;
			ret += ft_conversion(args, format[i]);
		}
		else
		{
			ft_putchar_fd(format[i], 1);
			ret++;
		}
		i++;
	}
	va_end(args);
	return (ret);
}