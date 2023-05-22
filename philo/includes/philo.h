/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 20:22:58 by Romain            #+#    #+#             */
/*   Updated: 2022/05/10 00:00:10 by rcuminal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <sys/time.h>
# include <pthread.h>

struct	s_val;

typedef struct s_forkette
{
	int				on;
	pthread_mutex_t	forkette;
}			t_forkette;

typedef struct s_philosopher
{
	pthread_t		philosopher;
	struct timeval	start;
	struct timeval	end;
	int				state;
	int				id;
	int				dead;
	int				meal;
	struct s_val	*val;
	t_forkette		*f;
}			t_philosopher;

typedef struct s_val
{
	int				*tab;
	int				numerus;
	int				allalive;

	struct timeval	startprog;
	t_philosopher	*philo;
	pthread_mutex_t	write;
	pthread_mutex_t	dead;
}			t_val;

void	*ft_calloc( size_t elementCount, size_t elementSize);
void	*ft_memalloc(size_t size);
int		ft_atoi(char *str);
void	ft_printstate(t_philosopher *philosopher, t_val *val);
void	ft_initmutex(t_val *val);
void	ft_destroyallmutex(t_val *val);
int		time_diff(struct timeval *start, struct timeval *end);

int		ft_parsarg(int argc, char **argv, t_val *val);
int		ft_checkarg(char **argv);
void	setval(t_philosopher *philo, t_val *val);
void	ft_printstate(t_philosopher *philosopher, t_val *val);

void	ft_sleep(t_val *val, t_philosopher *philo);
void	philoeat(t_val *val, t_philosopher *philo);
void	ft_eat(t_val *val, t_philosopher *philo);
void	ft_dead(t_val *val, t_philosopher *philo);
int		ft_free(t_val *val, t_philosopher *philo);

#endif
