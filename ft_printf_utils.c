/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sazzeddi <sazzeddi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 13:55:19 by sazzeddi          #+#    #+#             */
/*   Updated: 2022/12/08 13:55:22 by sazzeddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr_fd_count(char *s, int fd, int *count, char option)
{
	int	i;

	i = 0;
	if (s == NULL)
	{
		write(fd, "(null)", 6);
		*count += 6;
		return (6);
	}
	while (s[i] != '\0')
	{
		write(fd, &s[i], sizeof(char));
		i++;
	}
	*count += i;
	if (option == 'd' || option == 'i')
		free(s);
	return (i);
}

int	ft_putchar_fd_count(char c, int fd, int *count)
{
	if (write(fd, &c, 1) != -1)
	{
		*count += 1;
		return (1);
	}
	return (0);
}

void	ft_putnbr_fd_unsigned(unsigned int n, int fd, int *count)
{
	if (n < 10)
		ft_putchar_fd_count(n + '0', fd, count);
	else
	{
		ft_putnbr_fd_unsigned(n / 10, fd, count);
		ft_putchar_fd_count((n % 10) + '0', fd, count);
	}
}

void	ft_puthex_fd(unsigned long n, char option, int fd, int *count)
{
	if (n < 10)
		ft_putchar_fd_count(n + '0', fd, count);
	else if (n < 16 && (option == 'x' || option == 'p'))
		ft_putchar_fd_count('a' + (n - 10), fd, count);
	else if (n < 16 && option == 'X')
		ft_putchar_fd_count('A' + (n - 10), fd, count);
	else
	{
		ft_puthex_fd(n / 16, option, fd, count);
		ft_puthex_fd(n % 16, option, fd, count);
	}
}
