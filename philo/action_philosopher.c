/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_philosopher.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qestefan <qestefan@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 20:33:25 by qestefan          #+#    #+#             */
/*   Updated: 2022/02/12 10:12:09 by qestefan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	take_fork(t_philosopher *philosopher)
{
	pthread_mutex_lock(philosopher->left);
	pthread_mutex_lock(philosopher->right);
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
	}
}
