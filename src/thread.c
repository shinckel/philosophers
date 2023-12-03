/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinckel <shinckel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 19:25:45 by shinckel          #+#    #+#             */
/*   Updated: 2023/12/02 23:43:59 by shinckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// while philosopher 0 is thinking, philosophers 1 and 4 are eating, and
// ...philosophers 2 and 3 are hungry
// each philo thread will run this routine function
// loop that will break as soon as the dead flag is 1
void	*routine(void *philo)
{
    t_philo *philosopher;

    philosopher = (t_philo *)philo;
    if (philosopher->id % 2 == 0)
        think(philosopher);
    if (philosopher->id % 2)
        eat(philosopher);
    return (NULL);
}

void    create_philos()
{
    int i;

    i = -1;
	while (++i < data()->num_of_philos)
    {
        if (philo_data(i) && pthread_create(&data()->philos[i].thread, NULL,
            routine, (void *)&data()->philos[i]) != 0)
            break ; // destroy_all(CREATION_ERROR, ...);
    }
    i = -1;
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
    data()->philos[index].n_meals = 0;
    return (1);
}

// check if anyone died
