/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansimonn <ansimonn@student.42angouleme.f>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 12:24:16 by ansimonn          #+#    #+#             */
/*   Updated: 2025/11/12 16:05:35 by ansimonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>

int		ft_strlen(const char *s);
void	ft_putstr_fd(char *s, int fd, int *ret);
void	ft_putnbr_fd(long n, int fd, int *ret, char sign);
void	ft_putchar_fd(char c, int fd, int *ret);

#endif