/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansimonn <ansimonn@student.42angouleme.f>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 18:40:45 by ansimonn          #+#    #+#             */
/*   Updated: 2025/11/12 15:31:01 by ansimonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd, int *ret)
{
	if (!s)
	{
		ft_putstr_fd("(null)", fd, ret);
		return ;
	}
	while (*s)
	{
		ft_putchar_fd(*s, fd, ret);
		s++;
	}
}
