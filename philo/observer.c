/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   observer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qestefan <qestefan@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 14:47:21 by qestefan          #+#    #+#             */
/*   Updated: 2022/02/14 14:54:37 by qestefan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*observer(void *arg)
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
		
	}
}
