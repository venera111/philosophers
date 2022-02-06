/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization_philosophers.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qestefan <qestefan@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 14:25:56 by qestefan          #+#    #+#             */
/*   Updated: 2022/02/06 15:56:11 by qestefan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	check_data(t_data *data, int argc)
{
	if (data->num_of_meals <= 0 && argc == 6)
		return (ft_perror(ERROR_MEAL));
	if (data->num_of_philosophers < 0)
		return (ft_perror(ERROR_NUM));
	if (data->time_to_die < 0)
		return (ft_perror(ERROR_DIE));
	if (data->time_to_eat < 0)
		return (ft_perror(ERROR_EAT));
	if (data->time_to_sleep < 0)
		return (ft_perror(ERROR_SLEEP));
	return (0);
}

void	parsing_argv(t_data *data, int argc, char **argv)
{
	data->num_of_philosophers = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data->num_of_meals = ft_atoi(argv[5]);
}

int	initialization_philosophers(t_data *data, int argc, char **argv)
{
	parsing_argv(data, argc, argv); // парсим аргументы программы в структуру
	if (check_data(data, argc)) // проверяем числа
		return (1);
	return (0);
}
