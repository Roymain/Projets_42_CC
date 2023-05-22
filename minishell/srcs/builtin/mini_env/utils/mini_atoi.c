/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_atoi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Romain <Romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 23:20:43 by mathmart          #+#    #+#             */
/*   Updated: 2023/05/16 22:03:20 by Romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/mini_exec.h"

uint64_t	mini_atoi(const char *str)
{
	size_t		i;
	long long	result;
	short		signe;

	i = 0;
	signe = 1;
	result = 0;
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
		i++;
	if (str[i] == '-')
		signe = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	if (signe == -1)
		return (0);
	return (result);
}
