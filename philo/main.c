/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scavalli <scavalli@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 12:50:02 by scavalli          #+#    #+#             */
/*   Updated: 2025/05/02 17:35:04 by scavalli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	create_threads_args(t_targs *thread_args, int ac, char **av)
{
	int	i;
	struct timeval start;

	i = 0;
	gettimeofday(&start, NULL);
	while (i < ft_atoi(av[1]))
	{
		thread_args[i].id = i;
		thread_args[i].number_of_philosophers = ft_atoi(av[1]);
		thread_args[i].time_to_die = ft_atoi(av[2]);
		thread_args[i].time_to_eat = ft_atoi(av[3]);
		thread_args[i].time_to_sleep = ft_atoi(av[4]);
		thread_args[i].number_of_times_each_philosopher_must_eat = -1;
		if(i = ft_atoi(av[i]) - 1)
			thread_args[i].neighbor = &thread_args[0];
		else
			thread_args[i].neighbor = &thread_args[i+1];
		if (ac == 6)
			thread_args[i].number_of_times_each_philosopher_must_eat = ft_atoi(av[5]);
		thread_args[i].start_time = start;
		pthread_mutex_init(&thread_args[i].data->mutex, NULL);
		i++;
	}
}

int	master(int ac, char **av)
{
	pthread_t thread[ft_atoi(av[1])];
	t_targs	thread_args[ft_atoi(av[1])];
	int		i;
	int		rc;

	create_threads_args(thread_args, ac, av);
	i = 0;
	while(i < ft_atoi(av[1]))
	{
		rc = pthread_create(&thread[i], NULL, ........., (void *) thread_args);
		i++;
	}
	while(i < ft_atoi(av[1]))
	{
		pthread_join(thread[i], NULL);
		pthread_mutex_destroy(&thread_args->data->mutex);
		i++;
	}
 
}

int	main(int ac, char **av)
{
	if (ac < 5 || ac > 6)
	{
		error("Error : invalid input arguments");
		return (-1);
	}
	master(ac, av);
}