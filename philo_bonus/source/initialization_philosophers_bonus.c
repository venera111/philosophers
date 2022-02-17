/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization_philosophers_bonus.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qestefan <qestefan@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 10:11:48 by qestefan          #+#    #+#             */
/*   Updated: 2022/02/17 11:11:48 by qestefan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

static int	check_data(t_data *data, int argc)
{
	if (data->num_of_meals <= 0 && argc == 6)
		return (ft_perror(ERROR_MEAL));
	if (data->num_of_philosophers <= 0)
		return (ft_perror(ERROR_NUM));
	if (data->time_to_die <= 0)
		return (ft_perror(ERROR_DIE));
	if (data->time_to_eat <= 0)
		return (ft_perror(ERROR_EAT));
	if (data->time_to_sleep <= 0)
		return (ft_perror(ERROR_SLEEP));
	return (0);
}

static void	parsing_argv(t_data *data, int argc, char **argv)
{
	data->num_of_philosophers = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data->num_of_meals = ft_atoi(argv[5]);
}

static sem_t	*init_semaphore(const char *name, unsigned int value)
{
	sem_t	*sem;

	sem = sem_open(name, O_CREAT | O_EXCL, 0644, value);
	if (sem != SEM_FAILED)
		return (sem);
	sem_unlink(name);
	return (sem_open(name, O_CREAT | O_EXCL, 0644, value));
}

static int	start_philosophers(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_of_philosophers)
	{
		data->philosophers[i].name = making_name("philo", i);
		data->philosophers[i].sem \
			= init_semaphore(data->philosophers[i].name, 1);
		data->philosophers[i].n = i;
		data->philosophers[i].data = data;
		i++;
	}
	return (0);
}

int	initialization_philosophers(t_data *data, int argc, char *argv[])
{
	parsing_argv(data, argc, argv);
	if (check_data(data, argc))
		return (1);
	data->finish = init_semaphore("finish", 0);
	data->action = init_semaphore("action", 1);
	data->forks = init_semaphore("forks", data->num_of_philosophers + 1);
	data->num_of_eat_finish \
		= init_semaphore("num_of_eat_finish", 0);
	if (ft_allocate(&data->philosophers, sizeof(t_philosopher) \
		* data->num_of_philosophers))
		return (ft_perror(ERROR_MALLOC));
	if (start_philosophers(data))
		return (1);
	return (0);
}
