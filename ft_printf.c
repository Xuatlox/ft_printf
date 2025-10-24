/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansimonn <ansimonn@student.42angouleme.f>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 11:06:40 by ansimonn          #+#    #+#             */
/*   Updated: 2025/10/24 11:00:11 by ansimonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansimonn <ansimonn@student.42angouleme.f>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 11:06:40 by ansimonn          #+#    #+#             */
/*   Updated: 2025/10/24 10:28:10 by ansimonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include "libft/libft.h"

void	conversion(void *arg, const char spec)
{
	 if (spec == 'c')
	 	ft_putchar((char) arg);
	 else if (spec == 's')
	 	ft_putstr((char *) arg);
	 else if (spec == 'p')
	 	ft_putadr(arg);
	 else if (spec == 'd')
	 	ft_putnbr((int) arg);
	 else if (spec == 'i')
	 	ft_putnbr((int) arg);
	 else if (spec == 'u')
	 	ft_putnbr((unsigned int) arg);
	 else if (spec == 'x')
	 	ft_putnbr_base((int) arg, 16);
	 else if (spec == 'X')
	 	ft_putnbr_base((int) arg, 16);
	 else if (spec == '%')
	 	ft_putchar('%');
}

int ft_printf(const char *format, ...)
{
	va_list args;
	int		i;

	i = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			conversion(va_arg(args, void*), format[i]);
		}
		else
			ft_putchar(format[i]);
		i++;
	}
	va_end(args);
}
