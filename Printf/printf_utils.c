/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 19:24:34 by rcuminal          #+#    #+#             */
/*   Updated: 2021/11/20 02:25:57 by rcuminal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putchar_fd(char c, int fd, int *ct)
{
	write(fd, &c, 1);
	*ct += 1;
}

void	ft_putstr_fd(char *s, int fd, int *ct)
{
	int	i;

	i = 0;
	if (!fd)
		return ;
	if (!s)
	{
		write(fd, "(null)", 6);
		*ct += 6;
		return ;
	}
	while (s[i])
	{
		write(fd, &s[i], 1);
		*ct += 1;
		i++;
	}
}

void	ft_putnbr_fd(int n, int fd, int *ct)
{
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		*ct += 11;
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		*ct += 1;
		n = -n;
	}
	if (n < 10)
	{
		ft_putchar_fd(n + '0', fd, ct);
	}
	if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd, ct);
		ft_putchar_fd(n % 10 + '0', fd, ct);
	}
}

unsigned long long	ft_strlen(const char *theString)
{
	int	i;

	i = 0;
	while (theString[i])
	{
		i++;
	}
	return (i);
}
