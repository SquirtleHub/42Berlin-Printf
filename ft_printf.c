/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sazzeddi <sazzeddi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 13:55:33 by sazzeddi          #+#    #+#             */
/*   Updated: 2022/12/08 13:55:48 by sazzeddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put_next_arg(char option, va_list ap, int *count)
{
	unsigned long long	ll;

	if (option == '%')
		ft_putchar_fd_count('%', 1, count);
	else if (option == 'c')
		ft_putchar_fd_count((char)va_arg(ap, int), 1, count);
	else if (option == 's')
		ft_putstr_fd_count(va_arg(ap, char *), 1, count, option);
	else if (option == 'd' || option == 'i')
		ft_putstr_fd_count(ft_itoa(va_arg(ap, int)), 1, count, option);
	else if (option == 'u')
		ft_putnbr_fd_unsigned(va_arg(ap, unsigned int), 1, count);
	else if (option == 'p')
	{
		ll = va_arg(ap, unsigned long);
		if (ll == 0)
			ft_putstr_fd_count("(nil)", 1, count, option);
		else
		{
			ft_putstr_fd_count("0x", 1, count, option);
			ft_puthex_fd(ll, option, 1, count);
		}
	}
	else if (option == 'x' || option == 'X')
		ft_puthex_fd(va_arg(ap, unsigned int), option, 1, count);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		count_printed;
	va_list	ap;

	i = 0;
	count_printed = 0;
	va_start(ap, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%' && str[i + 1] != '\0')
		{
			i++;
			ft_put_next_arg(str[i], ap, &count_printed);
		}
		else
			ft_putchar_fd_count(str[i], 1, &count_printed);
		i++;
	}
	va_end(ap);
	return (count_printed);
}
