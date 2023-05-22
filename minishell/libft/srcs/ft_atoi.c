/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 08:51:19 by rcuminal          #+#    #+#             */
/*   Updated: 2022/01/03 19:59:45 by rcuminal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_atoi(const char *str, int *i)
{
	long long int	sign;
	long long int	result;

	sign = 1;
	result = 922337203685477580;
	if (!str[*i])
		return (result);
	while (str[*i] == ' ' || (str[*i] >= 9 && str[*i] <= 13))
	{
		*i += 1;
	}
	if (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			sign = -1;
		*i += 1;
	}
	if (str[*i] >= '0' && str[*i] <= '9')
		result = 0;
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		result = result * 10 + str[*i] - '0';
		*i += 1;
	}
	return (sign * result);
}
