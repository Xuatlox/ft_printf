/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansimonn <ansimonn@student.42angouleme.f>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 11:06:40 by ansimonn          #+#    #+#             */
/*   Updated: 2025/10/24 16:16:02 by ansimonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft/libft.h"

void	conversion(void *arg, const char spec)
{
	 if (spec == 'c')
	 	ft_putchar_fd(*(char *) arg, 1);
	 else if (spec == 's')
	 	ft_putstr_fd((char *) arg, 1);
	 else if (spec == 'p')
	 	write(1, arg, ft_strlen(arg));
	 else if (spec == 'd')
	 	ft_putnbr_fd(*((int *) arg), 1);
	 else if (spec == 'i')
	 	ft_putnbr_fd(*(int *)arg, 1);
	 else if (spec == 'u')
	 	ft_putnbr_fd((int) *(unsigned int *) arg, 1);
	 /*else if (spec == 'x')
	 	ft_putnbr_base((int) arg, 16);
	 else if (spec == 'X')
	 	ft_putnbr_base((int) arg, 16);*/
	 else if (spec == '%')
	 	ft_putchar_fd('%', 1);
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
			ft_putchar_fd(format[i], 1);
		i++;
	}
	va_end(args);
	return (1);
}

int	main(int argc, char **argv)
{
	(void) argc;
	ft_printf("%d", ft_atoi(argv[1]));
}