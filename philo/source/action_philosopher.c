/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_philosopher.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qestefan <qestefan@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 20:33:25 by qestefan          #+#    #+#             */
/*   Updated: 2022/02/17 10:36:35 by qestefan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

static void	take_fork(t_philosopher *philosopher)
{
	pthread_mutex_lock(philosopher->right);
	print_status(philosopher, "the fork was taken");
	pthread_mutex_lock(philosopher->left);
	print_status(philosopher, "the fork was taken");
}

static void	eating(t_philosopher *philosopher)
{
	uint64_t	time;

	pthread_mutex_lock(&philosopher->philo_mutex);
	gettimeofday(&philosopher->last_meal, NULL);
	time = current_time(philosopher->last_meal) - \
		current_time(philosopher->data->tv);
	pthread_mutex_lock(&philosopher->data->mutex);
	if (!philosopher->data->finish)
		printf("%lld\t%d\tis eating\n", time, philosopher->n + 1);
	philosopher->num_of_meals += 1;
	if (philosopher->num_of_meals == philosopher->data->num_of_meals)
		philosopher->data->num_of_eat_finish += 1;
	pthread_mutex_unlock(&philosopher->data->mutex);
	usleep(philosopher->data->time_to_eat * 1000);
	pthread_mutex_unlock(philosopher->right);
	pthread_mutex_unlock(philosopher->left);
	pthread_mutex_unlock(&philosopher->philo_mutex);
}

static void	sleeping(t_philosopher *philosopher)
{
	print_status(philosopher, "is sleeping");
	usleep(philosopher->data->time_to_sleep * 1000);
}

static void	thinking(t_philosopher *philosopher)
{
	print_status(philosopher, "is thinking");
}

void	*action_philosopher(void *data)
{
	t_philosopher	*philosopher;

	philosopher = data;
	if (philosopher->n % 2 == 0)
		usleep(philosopher->data->time_to_eat * 1000);
	while (!philosopher->data->finish)
	{
		take_fork(philosopher);
		eating(philosopher);
		sleeping(philosopher);
		thinking(philosopher);
	}
	return (NULL);
}
