/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_death.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jokang <jokang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 17:32:51 by jokang            #+#    #+#             */
/*   Updated: 2022/10/01 23:02:56 by jokang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ph_check_monitor(t_philo *philo)
{
	int	ret;

	pthread_mutex_lock(&philo->monitor->end);
	ret = false;
	if (philo->monitor->is_end_check)
		ret = true;
	pthread_mutex_unlock(&philo->monitor->end);
	return (ret);
}

void	ph_dead(t_philo *philo)
{
	pthread_mutex_lock(&philo->status_mtx);
	philo->status = DEATH;
	pthread_mutex_unlock(&philo->status_mtx);
	ph_print_state(philo);
}

int	ph_is_dead(t_philo *philo)
{
	int				ret;
	unsigned long	current;

	pthread_mutex_lock(&philo->life);
	ret = false;
	current = get_current_time() - philo->init_time;
	if (current > philo->life_count)
		ret = true;
	pthread_mutex_unlock(&philo->life);
	return (ret);
}

void	ph_print_state(t_philo *philo)
{
	t_monitor	*m;

	m = philo->monitor;
	pthread_mutex_lock(&m->end);
	if (m->is_end_check == true)
	{
		m->is_end = true;
		pthread_mutex_unlock(&m->end);
		return ;
	}
	pthread_mutex_unlock(&m->end);
	pthread_mutex_lock(&m->end);
	if (m->is_end_check == false)
	{
		if (philo->status == DEATH)
		{
			m->is_end_check = true;
		}
		pthread_mutex_unlock(&m->end);
		ph_print_helper(m, philo);
	}
	else
	{
		pthread_mutex_unlock(&m->end);
	}
}

void	ph_print_helper(t_monitor *m, t_philo *philo)
{
	unsigned long	time;

	time = get_current_time() - philo->init_time;
	pthread_mutex_lock(&m->speak);
	pthread_mutex_lock(&philo->status_mtx);
	if (philo->status == SLEEP)
		printf("%lu ms  %d  %s\n", time, philo->id + 1, "is sleeping");
	else if (philo->status == EAT)
		printf("%lu ms  %d  %s\n", time, philo->id + 1, "is eating");
	else if (philo->status == THINK)
		printf("%lu ms  %d  %s\n", time, philo->id + 1, "is thinking");
	else if (philo->status == FORK)
		printf("%lu ms  %d  %s\n", time, philo->id + 1, "has taken a fork");
	else if (philo->status == DEATH)
		printf("%lu ms  %d  %s\n", time, philo->id + 1, "died");
	else
		printf("%lu ms  %d  %s\n", time, philo->id + 1, "error!");
	pthread_mutex_unlock(&philo->status_mtx);
	pthread_mutex_unlock(&m->speak);
}
