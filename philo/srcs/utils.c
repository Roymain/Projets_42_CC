/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 20:32:25 by Romain            #+#    #+#             */
/*   Updated: 2022/05/09 22:40:35 by rcuminal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*z;
	size_t			i;

	z = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		z[i] = 0;
		i++;
	}
}

void	*ft_calloc( size_t elementCount, size_t elementSize)
{
	unsigned char		*tab;
	size_t				i;

	i = 0;
	tab = (void *)malloc(elementCount * elementSize);
	if (!tab)
		return (NULL);
	while (i < elementCount * elementSize)
	{
		tab[i] = 0;
		i++;
	}
	return (tab);
}

int	ft_atoi(char *str)
{
	long long int	sign;
	long long int	result;
	int				i;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i += 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i += 1;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - '0';
		i += 1;
	}
	return (sign * result);
}

void	*ft_memalloc(size_t size)
{
	void	*mem;

	mem = malloc(size);
	if (mem)
	{
		ft_bzero(mem, size);
		return (mem);
	}
	else
		return (NULL);
}

int	ft_free(t_val *val, t_philosopher *philo)
{
	int	i;

	i = val->tab[0] - 1;
	if (val->philo)
	{
		while (i != -1)
		{
			free (val->philo[i].f);
			i--;
		}
	}
	free(val->tab);
	if (val->philo)
		free(val->philo);
	free(val);
	return (0);
}
