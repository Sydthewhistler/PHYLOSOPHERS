/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scavalli <scavalli@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 15:34:19 by scavalli          #+#    #+#             */
/*   Updated: 2025/05/02 17:50:33 by scavalli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	thread_process(void *args)
{
	t_targs *thread_args;
	struct timeval meal_date;

	thread_args = (t_targs *)args;
	thread_args->data->fork_status = 1;

	while (1)
	{
		pthread_mutex_lock(&thread_args->data->mutex);
		pthread_mutex_lock(&thread_args->neighbor->data->mutex);
		gettimeofday(&meal_date, NULL);
		if ((meal_date.tv_sec * 1000000 + meal_date.tv_usec)
			- (thread_args->last_meal.tv_sec * 1000000
				+ thread_args->last_meal.tv_usec) >= thread_args->time_to_die)
			
			usleep((thread_args->time_to_eat) * 1000);
		pthread_mutex_unlock(&thread_args->neighbor->data->mutex);
		pthread_mutex_unlock(&thread_args->data->mutex);
		thread_args->last_meal =
	}
}