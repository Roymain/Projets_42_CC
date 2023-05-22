/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Romain <Romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 05:19:29 by rcuminal          #+#    #+#             */
/*   Updated: 2022/10/10 17:43:16 by Romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>
#include <string.h>

void	ft_tri(char c, va_list ap, int *ct)
{
	if (c == 'c')
		ft_putchar_fd(va_arg(ap, int), 1, ct);
	if (c == 's')
		ft_putstr_fd(va_arg(ap, char *), 1, ct);
	if (c == 'p')
	{
		write(1, "0x", 2);
		*ct += 2; 
		ft_putunslongnbr_base(va_arg(ap, unsigned long),
			"0123456789abcdef", ct);
	}
	if (c == 'd' || c == 'i')
		ft_putnbr_fd(va_arg(ap, int), 1, ct);
	if (c == 'u')
		ft_putunsnbr_base(va_arg(ap, unsigned int), "0123456789", ct);
	if (c == 'x')
		ft_putunsnbr_base(va_arg(ap, unsigned int), "0123456789abcdef", ct);
	if (c == 'X')
		ft_putunsnbr_base(va_arg(ap, unsigned int), "0123456789ABCDEF", ct);
	if (c == '%')
		ft_putchar_fd('%', 1, ct);
}

int	ft_printf(const char *print, ...)
{
	va_list	ap;
	size_t	i;
	int		ct;

	i = 0;
	ct = 0;
	va_start(ap, print);
	while (print[i])
	{
		if (print[i] != '%')
		{
			ft_putchar_fd((char)print[i], 1, &ct);
			i++;
		}
		if (print[i] == '%')
		{
			i++;
			ft_tri(print[i], ap, &ct);
			i++;
		}
	}
	return (ct);
}

int main()
{
	char* machin = strdup("roger");
	int a = 145;
	printf("%d\n", ft_printf("le chiffre est %d %s\n", a,  "roger"));
	printf("%s\n", machin);
	printf("%d\n", printf("le chiffre est %d %s\n", a, "roger"));
	return (0);
}
