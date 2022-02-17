/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   waiter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qestefan <qestefan@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 10:56:35 by qestefan          #+#    #+#             */
/*   Updated: 2022/02/16 11:03:23 by qestefan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

void	*waiter(void *arg)
{
	t_philosopher	*philosopher;
	struct timeval	now;
	long long		time;

	philosopher = arg;
	while (!philosopher->data->finish)
	{
		pthread_mutex_lock(&philosopher->philo_mutex);
		pthread_mutex_lock(&philosopher->data->mutex);
		gettimeofday(&now, NULL);
		time = current_time(now) - current_time(philosopher->last_meal);
		gettimeofday(&now, NULL);
		if (time >= philosopher->data->time_to_die \
			&& philosopher->data->finish == 0)
		{
			printf("%lld\t%d\tdied\n", \
				current_time(now) - current_time(philosopher->data->tv), \
				philosopher->n + 1);
			philosopher->data->finish = 1;
		}
		pthread_mutex_unlock(&philosopher->data->mutex);
		pthread_mutex_unlock(&philosopher->philo_mutex);
	}
	return (NULL);
}

void	*waiter_each_meal(void *arg)
{
	t_data	*data;

	data = arg;
	while (!data->finish)
	{
		pthread_mutex_lock(&data->mutex);
		if (data->num_of_eat_finish == data->num_of_philosophers)
			data->finish = 1;
		pthread_mutex_unlock(&data->mutex);
	}
	return (NULL);
}
