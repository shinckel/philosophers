/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinckel <shinckel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 18:21:15 by shinckel          #+#    #+#             */
/*   Updated: 2023/11/17 20:09:19 by shinckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
// create threads
#include <pthread.h>

// memset, printf, malloc, free, write,
// usleep, gettimeofday, pthread_create,
// pthread_detach, pthread_join, pthread_mutex_init,
// pthread_mutex_destroy, pthread_mutex_lock,
// pthread_mutex_unlock
void	*computation(void *add)
{
	long sum = 0;
	long *add_num = (long *)add;
	for (long i = 0; i < 1000000000; i++)
		sum += *add_num;
	printf("Add: %ld\n", sum);
	return (NULL);
}

int main(void)
{
	// pthread_t	thread1;
	// pthread_t	thread2;

	long	value1 = 1;
	long	value2 = 2;

	computation((void *) &value1);
	computation((void *) &value2);


	// pthread_create(&thread1, NULL, computation, (void *)&value1);
	// pthread_create(&thread2, NULL, computation, (void *)&value2);

	// pthread_join(thread1, NULL);
	// pthread_join(thread2, NULL);

	
	return(0);

}





