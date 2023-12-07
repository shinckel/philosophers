/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinckel <shinckel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 19:25:45 by shinckel          #+#    #+#             */
/*   Updated: 2023/12/07 12:46:54 by shinckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// while philosopher 0 is thinking, philosophers 1 and 4 are eating, and
// ...philosophers 2 and 3 are hungry
// each philo thread will run this routine function
// loop that will break as soon as the dead flag is 1

int	dead_loop(t_philo *philo)
{
	pthread_mutex_lock(philo->dead_lock);
	if (*philo->dead_flag == 1)
		return (pthread_mutex_unlock(philo->dead_lock), 1);
	return (pthread_mutex_unlock(philo->dead_lock), 0);
}

void	*routine(void *philo)
{
    t_philo *philo_routine;

    philo_routine = (t_philo *)philo;
    if (philo_routine->id % 2 == 0)
        ft_usleep(1);
    while(!dead_loop(philo_routine))
    {
        eat(philo_routine);
        dream(philo_routine);
        think(philo_routine);
    }
    return (philo_routine);
}

void    create_philos()
{
    int i;

    i = -1;
    if (pthread_create(&data()->observer, NULL, &observe, (void *)data()->philos) != 0)
    {
        destory_all(CREATION_ERROR);
    }
	while (++i < data()->num_of_philos)
    {
        if (pthread_create(&data()->philos[i].thread, NULL, &routine, (void *)&data()->philos[i]) != 0)
            destory_all(CREATION_ERROR);
    }
    i = -1;
    if (pthread_join(data()->observer, NULL) != 0)
        destory_all(CREATION_ERROR);
    while (++i < data()->num_of_philos)
    {
        if (pthread_join(data()->philos[i].thread, NULL) != 0)
            destory_all(CREATION_ERROR);
    }
}

void    philo_data()
{
    int i;

    i = -1;
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
        if (!i)
        {
            data()->start_time = current_time();
            data()->philos[i].r_fork = &data()->forks[data()->num_of_philos - 1];
        }
        else
            data()->philos[i].r_fork = &data()->forks[i - 1];
    }
}
