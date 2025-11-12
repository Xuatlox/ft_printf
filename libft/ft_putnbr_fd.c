/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansimonn <ansimonn@student.42angouleme.f>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 18:57:07 by ansimonn          #+#    #+#             */
/*   Updated: 2025/11/12 16:15:40 by ansimonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(long n, int fd, int *ret, char sign)
{
	if (n < 0)
	{
		ft_putchar_fd('-', fd, ret);
		n = -n;
	}
	if (n > 9)
		ft_putnbr_fd(n / 10, fd, ret, sign);
	ft_putchar_fd(n % 10 + '0', fd, ret);
}
