/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_philosopher.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qestefan <qestefan@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 20:33:25 by qestefan          #+#    #+#             */
/*   Updated: 2022/02/14 10:56:52 by qestefan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	take_fork(t_philosopher *philosopher)
{
	pthread_mutex_lock(philosopher->right); // блокируем  вилку
	print_philosophers(philosopher, "the fork was taken");// функция печати
	pthread_mutex_lock(philosopher->left); // блокируем  вилку
	print_philosophers(philosopher, "the fork was taken");// функция печати
}

void	eating(t_philosopher *philosopher)
{
	long long	ms;

	pthread_mutex_lock(&philosopher->philo_mutex); // блокируем выполнение кода для одного философа

}

void	*action_philosopher(void *data)
{
	t_philosopher	*philosopher;

	philosopher = data; //сохраняем указатель на философа
	if (philosopher->n % 2 == 0) //если четный философ
		usleep(philosopher->data->time_to_eat * 1000); //устанавливаем в main структуре отрезок времени приема пищи в мс
	while (!philosopher->data->finish)
	{
		take_fork(philosopher); //взять вилки
		eating(philosopher); // есть
	}
}
