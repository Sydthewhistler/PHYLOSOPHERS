/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scavalli <scavalli@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 12:50:12 by scavalli          #+#    #+#             */
/*   Updated: 2025/05/02 17:32:33 by scavalli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
#include <sys/time.h>

typedef struct s_tdata
{
	int				fork_status;
	int				last_time_eat;

	pthread_mutex_t	mutex;
}					t_tdata;

typedef struct s_targs
{
	int				id;
	int				number_of_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_times_each_philosopher_must_eat;
	struct timeval	start_time;
	struct timeval	last_meal;
	t_tdata			*data;
	t_targs			*neighbor;
}					t_targs;

void				error(char *str);
int					ft_atoi(const char *str);

void				thread_process(void *args);

#endif