/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 00:27:31 by Romain            #+#    #+#             */
/*   Updated: 2022/05/09 23:04:05 by rcuminal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	time_diff(struct timeval *start, struct timeval *end)
{
	return (((end->tv_sec - start->tv_sec)
			+ 1e-6 * (end->tv_usec - start->tv_usec)) * 1000);
}

void	ft_initmutex(t_val *val)
{
	int	i;

	i = 0;
	while (i < val->tab[0])
	{
		if (pthread_mutex_init(&(val->philo[i].f->forkette), NULL) != 0)
			return ;
		i++;
	}
	if (pthread_mutex_init(&(val->write), NULL) != 0)
		return ;
	if (pthread_mutex_init(&(val->dead), NULL) != 0)
		return ;
	return ;
}

void	ft_destroyallmutex(t_val *val)
{
	int	i;

	i = 0;
	while (i < val->tab[0])
	{
		if (pthread_mutex_destroy(&(val->philo[i].f->forkette)) != 0)
			return ;
		i++;
	}
	pthread_mutex_destroy(&(val->write));
	pthread_mutex_destroy(&(val->dead));
	return ;
}

void	ft_printstate(t_philosopher *philosopher, t_val *val)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	if (val->allalive == 1)
	{
		pthread_mutex_lock(&(val->write));
		if (philosopher->state == 0)
			printf("%d %d is thinking\n",
				time_diff(&(val->startprog), &time), philosopher->id);
		if (philosopher->state == 1)
			printf("%d %d is eating\n",
				time_diff(&(val->startprog), &time), philosopher->id);
		if (philosopher->state == 2)
		{
			printf("%d %d has taken a fork\n",
				time_diff(&(val->startprog), &time), philosopher->id);
			printf("%d %d has taken a fork\n",
				time_diff(&(val->startprog), &time), philosopher->id);
		}
		if (philosopher->state == 3)
			printf("%d %d is sleeping\n",
				time_diff(&(val->startprog), &time), philosopher->id);
		pthread_mutex_unlock(&(val->write));
	}
}

void	ft_dead(t_val *val, t_philosopher *philo)
{
	pthread_mutex_lock(&(val->dead));
	printf("%d %d died\n", time_diff(&(val->startprog),
			&(philo->end)), philo->id);
	pthread_mutex_unlock(&(val->dead));
}
