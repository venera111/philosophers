/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qestefan <qestefan@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:49:54 by qestefan          #+#    #+#             */
/*   Updated: 2022/02/14 08:41:04 by qestefan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	create_philosophers(t_data *data)
{
	int			i;
	pthread_t	thread;

	gettimeofday(&data->tv, NULL); // устанавливает время
	i = 0;
	while (i < data->num_of_philosophers)
	{
		data->philosophers[i].last_meal = data->tv; // присваиваем время последнего приема пищи философа/время создания
		pthread_create(&data->philosophers[i].thread, NULL, \
			action_philosopher, &data->philosophers[i]); // создаем потоки, передавая функцию действий философа
		i++;
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
	memset(&data, 0, sizeof(data)); // заполняем нулями поля структуры
	if (initialization_philosophers(&data, argc, argv))
		return (1);
	create_philosophers(&data);
	return (0);
}
