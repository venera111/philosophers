/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   waiter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qestefan <qestefan@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 10:56:35 by qestefan          #+#    #+#             */
/*   Updated: 2022/02/15 14:32:43 by qestefan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*waiter(void *arg) // функция которую выполняет официант
{
	t_philosopher	*philosopher;
	struct timeval	now;
	long long		ms;

	philosopher = arg;
	while (!philosopher->data->finish)
	{
		pthread_mutex_lock(&philosopher->philo_mutex);
		pthread_mutex_lock(&philosopher->data->mutex);
		gettimeofday(&now, NULL);
		ms = time_in_ms(now) - time_in_ms(philosopher->last_meal);
		gettimeofday(&now, NULL);
		if (ms >= philosopher->data->time_to_die \
			&& philosopher->data->finish == 0)
		{
			printf("%lld\t%d\t%s", \
				time_in_ms(now) - time_in_ms(philosopher->data->tv), \
				philosopher->n + 1, "died");
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
