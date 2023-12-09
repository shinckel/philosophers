/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinckel <shinckel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 19:25:45 by shinckel          #+#    #+#             */
/*   Updated: 2023/12/09 18:48:35 by shinckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// loop that will break as soon as the dead flag is 1
int	dead_loop(t_philo *philo)
{
	pthread_mutex_lock(philo->dead_lock);
	if (*philo->dead_flag == 1)
		return (pthread_mutex_unlock(philo->dead_lock), 1);
	return (pthread_mutex_unlock(philo->dead_lock), 0);
}

void	*routine(void *philos)
{
	t_philo	*philo;

	philo = (t_philo *)philos;
	if (philo->id % 2 != 0)
	{
		think(philo);
		ft_usleep(10);
	}
	while (!dead_loop(philo))
	{
		eat(philo);
		dream(philo);
		think(philo);
	}
	return (NULL);
}

void	create_philos(void)
{
	int	i;

	i = -1;
	while (++i < data()->num_of_philos)
	{
		if (pthread_create(&data()->philos[i].thread, NULL, &routine,
				(void *)&data()->philos[i]) != 0)
			destory_all(CREATION_ERROR);
	}
	if (pthread_create(&data()->observer, NULL, &observe,
			(void *)data()->philos) != 0)
		destory_all(CREATION_ERROR);
	i = -1;
	while (++i < data()->num_of_philos)
	{
		if (pthread_join(data()->philos[i].thread, NULL) != 0)
			destory_all(CREATION_ERROR);
	}
	if (pthread_join(data()->observer, NULL) != 0)
		destory_all(CREATION_ERROR);
}

void	philo_data(void)
{
	int	i;
	int	end;

	i = -1;
	end = data()->num_of_philos - 1;
	data()->start_time = current_time();
	while (++i < data()->num_of_philos)
	{
		data()->philos[i].id = i + 1;
		data()->philos[i].eating_flag = 0;
		data()->philos[i].n_meals = 0;
		data()->philos[i].dead_flag = &data()->dead_flag;
		data()->philos[i].last_meal = current_time();
		data()->philos[i].meal_lock = &data()->o_meal_lock;
		data()->philos[i].dead_lock = &data()->o_dead_lock;
		data()->philos[i].write_lock = &data()->o_write_lock;
		data()->philos[i].l_fork = &data()->forks[i];
		data()->philos[i].r_fork = &data()->forks[(i + 1) % (end + 1)];
		if (data()->philos[i].id % 2 != 0)
		{
			data()->philos[i].r_fork = &data()->forks[i];
			data()->philos[i].l_fork = &data()->forks[(i + 1) % (end + 1)];
		}
	}
}
