/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansimonn <ansimonn@student.42angouleme.f>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 18:57:07 by ansimonn          #+#    #+#             */
/*   Updated: 2025/11/07 15:12:02 by ansimonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd, int *ret)
{
	if (n == -2147483648)
		ft_putstr_fd("-2147483648", fd, ret);
	if (n < 0)
	{
		ft_putchar_fd('-', fd, ret);
		n = -n;
	}
	if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd, ret);
	}
	ft_putchar_fd(n % 10 + '0', 1, ret);
}
