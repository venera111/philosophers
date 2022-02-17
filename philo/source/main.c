/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qestefan <qestefan@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:49:54 by qestefan          #+#    #+#             */
/*   Updated: 2022/02/16 10:56:10 by qestefan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

static void	join_philosophers(t_data *data)
{
	int		i;

	i = 0;
	while (i < data->num_of_philosophers)
	{
		pthread_join(data->philosophers[i].thread, NULL);
		pthread_mutex_destroy(&data->philosophers[i++].philo_mutex);
	}
	free(data->philosophers);
	i = 0;
	while (i < data->num_of_philosophers)
		pthread_mutex_destroy(&data->forks[i++]);
	free(data->forks);
}

static void	create_philosophers(t_data *data)
{
	int			i;
	pthread_t	thread;

	if (gettimeofday(&data->tv, NULL) != 0)
		ft_perror(ERROR_TV);
	i = 0;
	while (i < data->num_of_philosophers)
	{
		data->philosophers[i].last_meal = data->tv;
		pthread_create(&data->philosophers[i].thread, NULL, \
			action_philosopher, &data->philosophers[i]);
		pthread_create(&thread, NULL, waiter, &data->philosophers[i]);
		pthread_detach(thread);
		i++;
	}
	if (data->num_of_meals != 0)
	{
		pthread_create(&thread, NULL, waiter_each_meal, data);
		pthread_detach(thread);
	}
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 5 && argc != 6)
	{
		ft_perror(ERROR_ARGC);
		exit(1);
	}
	memset(&data, 0, sizeof(data));
	if (initialization_philosophers(&data, argc, argv))
		return (1);
	create_philosophers(&data);
	join_philosophers(&data);
	return (0);
}
