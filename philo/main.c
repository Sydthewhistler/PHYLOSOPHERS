/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scavalli <scavalli@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 12:50:02 by scavalli          #+#    #+#             */
/*   Updated: 2025/05/06 17:28:52 by scavalli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	create_threads_args(t_targs *thread_args, int ac, char **av, bool end)
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
		thread_args[i].end = &end;
		if(i == ft_atoi(av[1]) - 1)
			thread_args[i].neighbor = &thread_args[0];
		else
			thread_args[i].neighbor = &thread_args[i+1];
		if (ac == 6)
			thread_args[i].number_of_times_each_philosopher_must_eat = ft_atoi(av[5]);
		thread_args[i].start_time = start;
		thread_args[i].last_meal = start;
		thread_args[i].data = malloc(sizeof(t_tdata));
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
	bool	end;

	end = false;
	create_threads_args(thread_args, ac, av, end);
	i = 0;
	while(i < ft_atoi(av[1]))
	{
		rc = pthread_create(&thread[i], NULL, thread_process, (void *) &thread_args[i]);
		if(rc)
			return (-1);
		i++;
	}
	i = 0;
	while(i < ft_atoi(av[1]))
	{
		pthread_join(thread[i], NULL);
		pthread_mutex_destroy(&thread_args->data->mutex);
		free(thread_args[i].data);
		i++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	if (ac < 5 || ac > 6)
	{
		error("Error : invalid input arguments");
		return (-1);
	}
	if(master(ac, av) == -1)
		return (-1);
	return (0);
}