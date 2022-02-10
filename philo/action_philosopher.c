/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_philosopher.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qestefan <qestefan@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 20:33:25 by qestefan          #+#    #+#             */
/*   Updated: 2022/02/09 19:57:19 by qestefan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*action_philosopher(void *data)
{
	t_philosopher	*philosopher;

	philosopher = data;
	if (philosopher->n % 2 == 0) //если четный философ
		usleep(philosopher->data->time_to_eat * 1000); //устанавливаем в main структуре отрезок времени приема пищи в мс
	
}
