/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansimonn <ansimonn@student.42angouleme.f>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 11:06:40 by ansimonn          #+#    #+#             */
/*   Updated: 2025/11/12 16:54:48 by ansimonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_puthex(unsigned long nbr, const char upcase, int *ret)
{
	if (nbr > 15)
		ft_puthex(nbr / 16, upcase, ret);
	if (nbr % 16 < 10)
		ft_putchar_fd('0' + (nbr % 16), 1, ret);
	else if (upcase)
		ft_putchar_fd('A' + (nbr % 16) - 10, 1, ret);
	else
		ft_putchar_fd('a' + (nbr % 16) - 10, 1, ret);
}

static void	ft_putadr(unsigned long nbr, int *ret)
{
	if (nbr == 0)
		ft_putstr_fd("(nil)", 1, ret);
	else
	{
		ft_putstr_fd("0x", 1, ret);
		ft_puthex(nbr, 0, ret);
	}
}

static void	ft_conversion(va_list args, const char **format, int *ret)
{
	(*format)++;
	if (**format == 'c')
		ft_putchar_fd(va_arg(args, int), 1, ret);
	else if (**format == 's')
		ft_putstr_fd(va_arg(args, char *), 1, ret);
	else if (**format == 'p')
		ft_putadr(va_arg(args, unsigned long), ret);
	else if (**format == 'd' || **format == 'i')
		ft_putnbr_fd(va_arg(args, int), 1, ret, 1);
	else if (**format == 'u')
		ft_putnbr_fd(va_arg(args, unsigned int), 1, ret, 0);
	else if (**format == 'x')
		ft_puthex(va_arg(args, unsigned int), 0, ret);
	else if (**format == 'X')
		ft_puthex(va_arg(args, unsigned int), 1, ret);
	else
	{
		ft_putchar_fd('%', 1, ret);
		if (**format && **format != '%')
			ft_putchar_fd(**format, 1, ret);
	}
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		ret;

	ret = 0;
	if (!format)
		return (-1);
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
			ft_conversion(args, &format, &ret);
		else if (*format != '%')
			ft_putchar_fd(*format, 1, &ret);
		if (*format)
			format++;
	}
	va_end(args);
	return (ret);
}
