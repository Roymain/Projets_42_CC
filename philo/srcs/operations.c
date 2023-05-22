/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 11:49:17 by rcuminal          #+#    #+#             */
/*   Updated: 2022/05/12 22:24:49 by rcuminal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_sleep(t_val *val, t_philosopher *philo)
{
	struct timeval	start;
	struct timeval	end;

	gettimeofday(&start, NULL);
	gettimeofday(&end, NULL);
	while (val->allalive == 1 && time_diff(&start, &end) < val->tab[3]
		&& time_diff(&(philo->start), &(end)) <= val->tab[1])
	{
		usleep(100);
		gettimeofday(&end, NULL);
	}
	return ;
}

void	philoeat(t_val *val, t_philosopher *philo)
{
	struct timeval	end;

	gettimeofday(&(end), NULL);
	while (val->allalive && time_diff(&(philo->start), &(end)) < val->tab[2]
		&& time_diff(&(philo->start), &(end)) <= val->tab[1])
	{
		usleep(100);
		gettimeofday(&(end), NULL);
	}
	philo->meal += 1;
}

void	ft_eat(t_val *val, t_philosopher *philo)
{
	philo->f->on = 1;
	pthread_mutex_lock(&(philo->val->philo[philo->id - 1].f->forkette));
	if (philo->id != 1)
		pthread_mutex_lock(&(philo->val->philo[philo->id - 2].f->forkette));
	else
		pthread_mutex_lock(&(philo->val->philo[val->tab[0] - 1].f->forkette));
	gettimeofday(&(philo->start), NULL);
	philo->state = 2;
	ft_printstate(philo, val);
	philo->state = 1;
	ft_printstate(philo, val);
	philoeat(val, philo);
	if (philo->id != 1)
		pthread_mutex_unlock(&(philo->val->philo[philo->id - 2].f->forkette));
	else
		pthread_mutex_unlock(&(philo->val->philo[val->tab[0] - 1].f->forkette));
	pthread_mutex_unlock(&(philo->f->forkette));
	philo->f->on = 0;
	return ;
}
