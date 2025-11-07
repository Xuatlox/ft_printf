/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansimonn <ansimonn@student.42angouleme.f>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 12:24:16 by ansimonn          #+#    #+#             */
/*   Updated: 2025/11/07 15:07:55 by ansimonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>

size_t	ft_strlen(const char *s);
int		ft_putstr_fd(char *s, int fd, int *ret);
int		ft_putnbr_fd(int n, int fd, int *ret);
int		ft_putchar_fd(char c, int fd, int *ret);

#endif