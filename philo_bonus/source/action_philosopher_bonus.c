/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_philosopher_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qestefan <qestefan@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 10:32:05 by qestefan          #+#    #+#             */
/*   Updated: 2022/02/17 11:43:52 by qestefan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

static void	take_fork(t_philosopher *philosopher)
{
	sem_wait(philosopher->data->forks);
	print_status(philosopher, "the fork was taken");
	sem_wait(philosopher->data->forks);
	print_status(philosopher, "the fork was taken");
}

static void	eating(t_philosopher *philosopher)
{
	sem_wait(philosopher->sem);
	gettimeofday(&philosopher->last_meal, NULL);
	print_status(philosopher, "is eating");
	philosopher->num_of_meals += 1;
	if (philosopher->num_of_meals == philosopher->data->num_of_meals)
		sem_post(philosopher->data->num_of_eat_finish);
	usleep(philosopher->data->time_to_eat * 1000);
	sem_post(philosopher->data->forks);
	sem_post(philosopher->data->forks);
	sem_post(philosopher->sem);
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

void	action_philosopher(t_philosopher *philosopher)
{
	pthread_t	thread;

	pthread_create(&thread, NULL, waiter, philosopher);
	if (philosopher->n % 2 == 0)
		usleep(philosopher->data->time_to_eat * 1000);
	while (1)
	{
		take_fork(philosopher);
		eating(philosopher);
		sleeping(philosopher);
		thinking(philosopher);
	}
	exit(0);
}
