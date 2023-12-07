/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinckel <shinckel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 11:07:00 by shinckel          #+#    #+#             */
/*   Updated: 2023/12/07 21:28:36 by shinckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_died(t_philo *philo)
{
	pthread_mutex_lock(philo->meal_lock);
	if (current_time() - philo->last_meal >= data()->time_to_die
		&& philo->eating_flag == 0)
		return (pthread_mutex_unlock(philo->meal_lock), 1);
	return (pthread_mutex_unlock(philo->meal_lock), 0);
}

static int	check_if_dead(t_philo *philos)
{
	int	i;

	i = -1;
	while (++i < data()->num_of_philos)
	{
		if (philo_died(&philos[i]))
		{
			print_thread_execution(&philos[i], DEAD, RED);
			pthread_mutex_lock(philos[0].dead_lock);
			*philos->dead_flag = 1;
			pthread_mutex_unlock(philos[0].dead_lock);
			return (1);
		}
	}
	return (0);
}

static int	check_if_full(t_philo *philos)
{
	int	i;
	int	finished_eating;

	i = -1;
	finished_eating = 0;
	if (data()->num_times_to_eat == -1)
		return (0);
	while (++i < data()->num_of_philos)
	{
		pthread_mutex_lock(philos[i].meal_lock);
		if (philos[i].n_meals >= data()->num_times_to_eat)
			finished_eating++;
		pthread_mutex_unlock(philos[i].meal_lock);
	}
	if (finished_eating == data()->num_of_philos)
	{
		pthread_mutex_lock(philos->dead_lock);
		*philos->dead_flag = 1;
		pthread_mutex_unlock(philos->dead_lock);
		return (1);
	}
	return (0);
}

//monitor thread routine
void	*observe(void *philo)
{
	t_philo	*philo_routine;

	philo_routine = (t_philo *)philo;
	while (1)
	{
		if (check_if_dead(philo_routine) || check_if_full(philo_routine))
			break ;
	}
	return (philo_routine);
}
