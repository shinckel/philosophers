/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_actions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinckel <shinckel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 19:24:43 by shinckel          #+#    #+#             */
/*   Updated: 2023/12/01 17:48:06 by shinckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    think(t_data *data)
{
    print_thread_execution(data, THINK);
}

// void	*routine(void *action)
// {
// 	// int		time_to_die;
// 	// int		time_to_eat;
// 	// int		time_to_sleep;
// }