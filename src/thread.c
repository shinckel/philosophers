/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinckel <shinckel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 19:25:45 by shinckel          #+#    #+#             */
/*   Updated: 2023/12/02 17:17:03 by shinckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *data)
{
    t_data  *structure;

    structure = (t_data *)data;
    think(structure);
    return (NULL);
}

// create threads
// ok. So I have to create the thread and a structure for each thread. How?
// using pthread_create?
// yes
// pthread_create(&thread, NULL, routine, NULL);
// but how to create a structure for each thread? using the same loop
// I have to create a structure for each thread and associate it with the thread
// 
// void    create_philos(t_data *data)
// {
//     int i;

//     i = -1;
// 	while (++i < data->num_of_philos)
//     {
//         if (pthread_create(&data->philos[i].thread, NULL, (void *)routine, (void *)data)
//             && philo_meta_data(data) != 0)
//             break ; // destroy_all(CREATION_ERROR, ...);
//     }
//     i = -1;
//     while (++i < data->num_of_philos)
//     {
//         if (pthread_join(data->philos[i].thread, NULL) != 0)
//             break ; // destroy_all(CREATION_ERROR, ...);
//     }
// }

void    create_philos()
{
    int i;

    i = -1;
	while (++i < data()->num_of_philos)
    {
        if (pthread_create(&data()->philos[i].thread, NULL, (void *)routine, (void *)data)
            && philo_meta_data(i) != 0)
            break ; // destroy_all(CREATION_ERROR, ...);
    }
    i = -1;
    while (++i < data()->num_of_philos)
    {
        if (pthread_join(data()->philos[i].thread, NULL) != 0)
            break ; // destroy_all(CREATION_ERROR, ...);
    }
}

int philo_meta_data(int index)
{
    if (index == 1)
        data()->start_time = current_time(); //is it ok to start counting start time here?
    data()->philos[index].id = index + 1;
    data()->philos[index].n_meals = 0;
    return (1);
}

// int philo_meta_data(int index)
// {
//     int i;

//     i = -1;

//     data->start_time = current_time(); //is it ok to start counting start time here?
//     while (++i < data->num_of_philos)
//     {
//         data->philos[index].id = i + 1;
//         data->philos[index].n_meals = 0;
//     }
//     return (1);
// }

// establish the routine
// function for thread to execute
// void    *routine(void *add)
// { 
    
// }

// check if anyone died
