/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sazzeddi <sazzeddi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 13:55:41 by sazzeddi          #+#    #+#             */
/*   Updated: 2022/12/08 13:55:43 by sazzeddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include "libft/libft.h"

int		ft_printf(const char *str, ...);
int		ft_putstr_fd_count(char *s, int fd, int *count, char option);
int		ft_putchar_fd_count(char c, int fd, int *count);
void	ft_putnbr_fd_unsigned(unsigned int n, int fd, int *count);
void	ft_puthex_fd(unsigned long n, char option, int fd, int *count);
void	ft_put_next_arg(char option, va_list ap, int *count);

#endif
