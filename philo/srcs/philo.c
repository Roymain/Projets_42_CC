/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 20:32:57 by Romain            #+#    #+#             */
/*   Updated: 2022/05/12 22:25:22 by rcuminal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_checktable(t_philosopher *philo)
{
	if (philo->val->tab[0] == 1)
		return (1);
	if (philo->id != 1 && philo->id != philo->val->tab[0])
	{
		if (philo->val->philo[philo->id - 2].f->on == 0
			&& philo->val->philo[philo->id].f->on == 0)
			return (0);
	}
	if (philo->id == 1)
	{
		if (philo->val->philo[philo->val->tab[0] - 1].f->on == 0
			&& philo->val->philo[philo->id].f->on == 0)
			return (0);
	}
	if (philo->id == philo->val->tab[0])
	{
		if (philo->val->philo[philo->id - 2].f->on == 0
			&& philo->val->philo[0].f->on == 0)
			return (0);
	}
	return (1);
}

void	ft_pattern(t_val *val, t_philosopher *philo)
{
	philo->state = 0;
	gettimeofday(&(philo->end), NULL);
	ft_printstate(philo, val);
	while (val->allalive == 1
		&& time_diff(&(philo->start), &(philo->end)) <= val->tab[1])
	{
		if (ft_checktable(philo) == 0)
		{
			ft_eat(val, philo);
			gettimeofday(&(philo->end), NULL);
			philo->state = 3;
			ft_printstate(philo, val);
			ft_sleep(val, philo);
			philo->state = 0;
			ft_printstate(philo, val);
		}
		usleep(10);
		gettimeofday(&(philo->end), NULL);
	}
	return ;
}

void	ft_patternmeal(t_val *val, t_philosopher *philo)
{
	philo->state = 0;
	gettimeofday(&(philo->end), NULL);
	ft_printstate(philo, val);
	while (val->allalive == 1 && philo->meal != val->tab[4]
		&& time_diff(&(philo->start), &(philo->end)) <= val->tab[1])
	{
		if (ft_checktable(philo) == 0)
		{
			ft_eat(val, philo);
			if (philo->meal == val->tab[4])
				return ;
			gettimeofday(&(philo->end), NULL);
			philo->state = 3;
			ft_printstate(philo, val);
			ft_sleep(val, philo);
			philo->state = 0;
			ft_printstate(philo, val);
		}
		usleep(10);
		gettimeofday(&(philo->end), NULL);
	}
}

void	*ft_recherche(void *arg)
{
	t_philosopher	*philo;
	t_val			*val;
	int				numerus;

	philo = (t_philosopher *)arg;
	val = philo->val;
	gettimeofday(&(philo->start), NULL);
	if (val->tab[4] != 0)
		ft_patternmeal(val, philo);
	else
		ft_pattern(val, philo);
	if (val->allalive == 0)
		return (arg);
	if (time_diff(&(philo->start), &(philo->end)) >= val->tab[1]
		&& val->allalive == 1)
	{
		pthread_mutex_lock(&(val->dead));
		philo->val->allalive = 0;
		philo->dead = 1;
		pthread_mutex_unlock(&(val->dead));
	}
	if (philo->dead == 1)
		ft_dead(val, philo);
	return (arg);
}

int	main(int argc, char **argv)
{
	t_val			*val;
	t_philosopher	*philo;

	if (argc > 4 && argc < 7 && ft_checkarg(argv) == 0)
	{
		val = ft_memalloc(sizeof(t_val));
		if (ft_parsarg(argc, argv, val) == 1)
			return (write(1, "Invalid arguments.", 19) + ft_free(val, philo));
		philo = ft_memalloc(sizeof(t_philosopher) * val->tab[0]);
		setval(philo, val);
		ft_initmutex(val);
		gettimeofday(&val->startprog, NULL);
		while (val->numerus < val->tab[0])
		{
			pthread_create(&(val->philo[val->numerus].philosopher),
				NULL, &ft_recherche, (void *)&(val->philo[val->numerus]));
			val->numerus++;
		}
		val->numerus++;
		while (val->numerus != -1)
			pthread_join(val->philo[val->numerus--].philosopher, NULL);
		return (ft_free(val, philo));
	}
	return (write(1, "Invalid arguments.", 19));
}
