/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinckel <shinckel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 11:07:00 by shinckel          #+#    #+#             */
/*   Updated: 2023/12/06 16:11:53 by shinckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "monitor.h"

// int	philo_died(t_philo *philo, size_t time_to_die)
// {
// 	pthread_mutex_lock(philo->meal_lock);
// 	if (current_time() - philo->last_meal >= data()->time_to_die
// 		&& philo->eating_flag == 0)
// 		return (pthread_mutex_unlock(philo->meal_lock), 1);
// 	pthread_mutex_unlock(philo->meal_lock);
// 	return (0);
// }

// int check_if_dead()
// {
//     int i;

//     i = -1;
//     while (++i < data()->num_of_philos)
//     {
//         if (philo_died(&data()->philos[i], data()->time_to_die))

//         {
//             print_thread_execution(&data()->philos[i], DEAD, RED);
//             pthread_mutex_lock(data()->philos[0].dead_lock);
//             data()->philos[0].dead_flag = 1;
//             pthread_mutex_unlock(data()->philos[0].dead_lock);
//             return (1);
//         }
//     }
//     return (0);
// }

// int	check_if_all_ate(t_philo *philos)
// {
// 	int	i;
// 	int	finished_eating;

// 	i = 0;
// 	finished_eating = 0;
// 	if (philos[0].num_times_to_eat == -1)
// 		return (0);
// 	while (i < philos[0].num_of_philos)
// 	{
// 		pthread_mutex_lock(philos[i].meal_lock);
// 		if (philos[i].meals_eaten >= philos[i].num_times_to_eat)
// 			finished_eating++;
// 		pthread_mutex_unlock(philos[i].meal_lock);
// 		i++;
// 	}
// 	if (finished_eating == philos[0].num_of_philos)
// 	{
// 		pthread_mutex_lock(philos[0].dead_lock);
// 		*philos->dead = 1;
// 		pthread_mutex_unlock(philos[0].dead_lock);
// 		return (1);
// 	}
// 	return (0);
// }

//monitor thread routine
void    *observe(void *philo)
{
    t_philo *philos;

    philos = (t_philo *)philo;
    // while(1)
    // {
    //     if (check_if_dead(philos) || check_if_full(philos))
    //         break ;
    // }
    return (philos);
}
