/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   waiter_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qestefan <qestefan@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 10:04:15 by qestefan          #+#    #+#             */
/*   Updated: 2022/02/17 10:41:46 by qestefan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	*waiter(void *argv)
{
	t_philosopher	*philosopher;
	struct timeval	now;
	long long		time;

	philosopher = argv;
	while (1)
	{
		sem_wait(philosopher->sem);
		sem_wait(philosopher->data->action);
		gettimeofday(&now, NULL);
		time = current_time(now) - current_time(philosopher->last_meal);
		gettimeofday(&now, NULL);
		if (time >= philosopher->data->time_to_die)
		{
			printf("%lld\t%d\tdied\n", \
				current_time(now) - current_time(philosopher->data->tv), \
				philosopher->n + 1);
			sem_post(philosopher->data->finish);
			return (NULL);
		}
		sem_post(philosopher->data->action);
		sem_post(philosopher->sem);
	}
	return (NULL);
}

void	*waiter_each_meal(void *arg)
{
	t_data	*data;
	int		i;

	data = arg;
	i = 0;
	while (i++ < data->num_of_philosophers)
		sem_wait(data->num_of_eat_finish);
	sem_post(data->finish);
	return (NULL);
}

void	*waiter_finish(void *arg)
{
	int		i;
	t_data	*data;

	data = arg;
	sem_wait(data->finish);
	i = 0;
	while (i < data->num_of_philosophers)
		kill(data->philosophers[i++].pid, SIGTERM);
	return (NULL);
}
