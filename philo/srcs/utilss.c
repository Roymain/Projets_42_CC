/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilss.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 12:03:31 by rcuminal          #+#    #+#             */
/*   Updated: 2022/05/09 22:57:37 by rcuminal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	setval(t_philosopher *philo, t_val *val)
{
	int	i;

	i = 0;
	val->allalive = 1;
	val->philo = philo;
	val->numerus = 0;
	while (i < val->tab[0])
	{
		val->philo[i].id = i + 1;
		val->philo[i].meal = 0;
		val->philo[i].val = val;
		val->philo[i].dead = 0;
		val->philo[i].f = ft_memalloc(sizeof(t_forkette));
		i++;
	}
	return ;
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_parsarg(int argc, char **argv, t_val *val)
{
	int	i;

	i = 0;
	val->tab = ft_calloc(argc, sizeof(int));
	while (i < argc - 1)
	{
		val->tab[i] = ft_atoi(argv[1 + i]);
		if (val ->tab[i] == -2147483648 && argv[1 + i][0] == '-')
			val ->tab[i] = 0;
		if (val->tab[i] > 0)
		{
			if ((val->tab[i] % 10 + '0')
				!= argv[1 + i][ft_strlen(argv[i + 1]) - 1])
				return (1);
		}
		if (val->tab[i] < 0)
		{
			if ((val->tab[i] * -1 % 10 + '0')
				!= argv[1 + i][ft_strlen(argv[i + 1]) - 1])
				return (1);
		}
		i++;
	}
	return (0);
}

int	ft_num(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

int	ft_checkarg(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (ft_num(argv[i]) != 0)
			return (1);
		i++;
	}
	return (0);
}
