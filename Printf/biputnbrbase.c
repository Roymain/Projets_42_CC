/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   biputnbrbase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 23:38:27 by rcuminal          #+#    #+#             */
/*   Updated: 2021/11/20 02:26:07 by rcuminal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putunsnbr_base(unsigned int nbr, char *base, int *ct)
{
	if (nbr >= ft_strlen(base))
		ft_putunsnbr_base(nbr / ft_strlen(base), base, ct);
	ft_putchar_fd(base[nbr % (ft_strlen(base))], 1, ct);
}

void	ft_putunslongnbr_base(unsigned long nbr, char *base, int *ct)
{
	if (nbr >= ft_strlen(base))
		ft_putunslongnbr_base(nbr / ft_strlen(base), base, ct);
	ft_putchar_fd(base[nbr % (ft_strlen(base))], 1, ct);
}
