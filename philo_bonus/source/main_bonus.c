/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qestefan <qestefan@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 11:02:09 by qestefan          #+#    #+#             */
/*   Updated: 2022/02/17 11:18:43 by qestefan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

static void	join_philosophers(t_data *data)
{
	int	i;
	int	status;

	i = 0;
	while (i < data->num_of_philosophers)
	{
		waitpid(data->philosophers[i].pid, &status, 0);
		sem_close(data->philosophers[i].sem);
		free(data->philosophers[i].name);
		i++;
	}
	free(data->philosophers);
	sem_close(data->finish);
	sem_close(data->action);
	sem_close(data->forks);
	sem_close(data->num_of_eat_finish);
}

static void	fork_philosophers(t_data *data)
{
	int			i;

	gettimeofday(&data->tv, NULL);
	i = 0;
	while (i < data->num_of_philosophers)
	{
		data->philosophers[i].last_meal = data->tv;
		data->philosophers[i].pid = fork();
		if (data->philosophers[i].pid == 0)
			return (action_philosopher(&data->philosophers[i]));
		else if (data->philosophers[i].pid < 0)
		{
			ft_perror(ERROR_FORK);
			exit(1);
		}
		++i;
	}
}

int	main(int argc, char *argv[])
{
	t_data		data;
	pthread_t	thread;

	if (argc != 5 && argc != 6)
	{
		ft_perror(ERROR_ARGC);
		exit(1);
	}
	memset(&data, 0, sizeof(data));
	if (initialization_philosophers(&data, argc, argv))
		return (1);
	fork_philosophers(&data);
	if (data.num_of_meals != 0)
		pthread_create(&thread, NULL, waiter_each_meal, &data);
	pthread_create(&thread, NULL, waiter_finish, &data);
	join_philosophers(&data);
	return (0);
}
