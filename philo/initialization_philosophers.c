/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization_philosophers.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qestefan <qestefan@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 14:25:56 by qestefan          #+#    #+#             */
/*   Updated: 2022/02/15 15:16:09 by qestefan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

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

static int	start_philosophers(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_of_philosophers)
	{
		data->philosophers[i].n = i;
		pthread_mutex_init(&data->forks[i], NULL);
		pthread_mutex_init(&data->philosophers[i].philo_mutex, NULL);
		if (i == 0)
		{
			data->philosophers[i].left \
				= &data->forks[data->num_of_philosophers - 1];
		}
		else
			data->philosophers[i].left = &data->forks[i - 1];
		data->philosophers[i].right = &data->forks[i];
		data->philosophers[i].data = data;
		i++;
	}
	return (0);
}

int	initialization_philosophers(t_data *data, int argc, char **argv)
{
	parsing_argv(data, argc, argv);
	if (check_data(data, argc))
		return (1);
	if (ft_allocate(&data->philosophers, sizeof(t_philosopher) \
		* data->num_of_philosophers) || ft_allocate(&data->forks, \
		sizeof(pthread_mutex_t) * data->num_of_philosophers))
		return (ft_perror(ERROR_MALLOC));
	if (start_philosophers(data))
		return (1);
	return (0);
}
