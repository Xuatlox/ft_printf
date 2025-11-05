/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansimonn <ansimonn@student.42angouleme.f>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 18:40:45 by ansimonn          #+#    #+#             */
/*   Updated: 2025/11/05 10:52:19 by ansimonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr_fd(char *s, int fd)
{
	int	ret;

	if (s)
	{
		ret = (int) write(1, s, ft_strlen(s));
		return (ret);
	}
	ret = write(fd, "(null)", 6);
	return (ret);
}
