/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_philosopher.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qestefan <qestefan@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 20:33:25 by qestefan          #+#    #+#             */
/*   Updated: 2022/02/14 11:54:56 by qestefan         ###   ########.fr       */
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

static void	eating(t_philosopher *philosopher)
{
	long long	ms;

	pthread_mutex_lock(&philosopher->philo_mutex); // блокируем выполнение кода для одного философа
	gettimeofday(&philosopher->last_meal, NULL); // время последнего приема пищи
	ms = time_in_ms(philosopher->last_meal) - \
		time_in_ms(philosopher->data->tv); //количество времени между последним приемом и созданием
	pthread_mutex_lock(&philosopher->data->mutex);
	if (!philosopher->data->finish)
		printf("%lld\t%d\t%s\n", ms, philosopher->n + 1, "is eating.");
	philosopher->num_of_meals += 1; //как только философ поел, увеличиваем счетчик
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
	print_philosophers(philosopher, "is sleeping.");
	usleep(philosopher->data->time_to_sleep * 1000);
}

static void	thinking(t_philosopher *philosopher)
{
	print_philosophers(philosopher, "is thinking.");
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
		sleeping(philosopher); // спать
		thinking(philosopher);
	}
	return (NULL);
}
