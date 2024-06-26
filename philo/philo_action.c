/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jokang <jokang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 17:32:48 by jokang            #+#    #+#             */
/*   Updated: 2022/10/01 23:08:14 by jokang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ph_wait(t_philo *philo)
{
	pthread_mutex_lock(&philo->status_mtx);
	philo->status = THINK;
	pthread_mutex_unlock(&philo->status_mtx);
	ph_print_state(philo);
	ph_spend(philo, philo->time_to_eat);
}

void	ph_think(t_philo *philo)
{
	pthread_mutex_lock(&philo->status_mtx);
	philo->status = THINK;
	pthread_mutex_unlock(&philo->status_mtx);
	ph_print_state(philo);
}

void	ph_eat(t_philo *philo)
{
	unsigned long	init_to_eat;

	pthread_mutex_lock(&philo->status_mtx);
	philo->status = EAT;
	pthread_mutex_unlock(&philo->status_mtx);
	init_to_eat = get_current_time() - philo->init_time;
	pthread_mutex_lock(&philo->life);
	philo->life_count = init_to_eat + philo->time_to_die;
	pthread_mutex_unlock(&philo->life);
	ph_print_state(philo);
	ph_spend(philo, philo->time_to_eat);
	pthread_mutex_unlock(philo->left);
	pthread_mutex_unlock(philo->right);
	philo->eat_count += 1;
}

void	ph_sleep(t_philo *philo)
{
	pthread_mutex_lock(&philo->status_mtx);
	philo->status = SLEEP;
	pthread_mutex_unlock(&philo->status_mtx);
	ph_print_state(philo);
	ph_spend(philo, philo->time_to_sleep);
}

void	ph_spend(t_philo *philo, unsigned long time)
{
	unsigned long	target;

	target = get_current_time() + time;
	while (true)
	{
		if (ph_is_dead(philo))
		{
			ph_dead(philo);
			break ;
		}
		if (get_current_time() >= target)
			break ;
		usleep(300);
	}
}
