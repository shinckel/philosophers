/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinckel <shinckel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 19:25:45 by shinckel          #+#    #+#             */
/*   Updated: 2023/12/06 16:05:23 by shinckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// while philosopher 0 is thinking, philosophers 1 and 4 are eating, and
// ...philosophers 2 and 3 are hungry
// each philo thread will run this routine function
// loop that will break as soon as the dead flag is 1

void	*routine(void *philo)
{
    t_philo *philos;

    philos = (t_philo *)philo;
    if (philos->id % 2 == 0)
        ft_usleep(1);
    eat(philos);
    dream(philos);
    think(philos);
    return (NULL);
}

void    create_philos()
{
    int i;

    i = -1;
    if (pthread_create(&data()->observer, NULL, observe,
        (void *)&data()->philos) != 0)
        return ; // destroy_all(CREATION_ERROR, ...);
	while (++i < data()->num_of_philos)
    {
        if (philo_data(i) && pthread_create(&data()->philos[i].thread, NULL,
            routine, (void *)&data()->philos[i]) != 0)
            break ; // destroy_all(CREATION_ERROR, ...);
    }
    i = -1;
    if (pthread_join(data()->observer, NULL) != 0)
        return ; // destroy_all(CREATION_ERROR, ...
    while (++i < data()->num_of_philos)
    {
        if (pthread_join(data()->philos[i].thread, NULL) != 0)
            break ; // destroy_all(CREATION_ERROR, ...);
    }
}

int philo_data(int index)
{
    if (!index)
        data()->start_time = current_time(); //is it ok to start counting start time here?
    data()->philos[index].id = index + 1;
    data()->philos[index].eating_flag = 0;
    data()->philos[index].n_meals = 0;
    data()->philos[index].dead_flag = 0;
    data()->philos[index].last_meal = current_time();
    data()->philos[index].meal_lock = &data()->o_meal_lock;
    data()->philos[index].dead_lock = &data()->o_dead_lock;
    data()->philos[index].write_lock = &data()->o_write_lock;
    data()->philos[index].l_fork = &data()->forks[index];
    if (index == 0)
        data()->philos[index].r_fork = &data()->forks[data()->num_of_philos - 1];
    else
        data()->philos[index].r_fork = &data()->forks[index - 1];
    return (1);
}

// int	dead_loop(t_philo *philo)
// {
// 	pthread_mutex_lock(philo->dead_lock);
// 	if (*philo->dead == 1)
// 		return (pthread_mutex_unlock(philo->dead_lock), 1);
// 	pthread_mutex_unlock(philo->dead_lock);
// 	return (0);
// }
