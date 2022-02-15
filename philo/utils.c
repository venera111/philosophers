/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qestefan <qestefan@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 12:18:22 by qestefan          #+#    #+#             */
/*   Updated: 2022/02/15 12:28:52 by qestefan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_allocate(void *arg, size_t size)
{
	*(void **)arg = malloc(size); // выделение памяти для нескольких философов
	if (*(void **)arg == NULL)
		return (1);
	memset(*(void **)arg, 0, size);
	return (0);
}

int	ft_perror(char *str)
{
	printf("%s", str);
	return (1);
}

int	ft_atoi(char *str)
{
	int			i;
	int			neg;
	long long	res;

	i = 0;
	res = 0;
	neg = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + neg * (str[i] - 48);
		i++;
		if (res > 2147483647 || res < -2147483648)
			ft_perror(ERROR_INT);
	}
	if (!(str[i] >= '0' && str[i] <= '9') && str[i] != '\0')
		ft_perror(ERROR_ARG);
	return (res);
}

void	print_philosophers(t_philosopher *philosopher, char *str)
{
	long long		ms;
	struct timeval	now;

	pthread_mutex_lock(&philosopher->data->mutex);
	gettimeofday(&now, NULL);
	ms = time_in_ms(now) - time_in_ms(philosopher->data->tv);
	if (!philosopher->data->finish)
		printf("%lld\t%d\t%s\n", ms, philosopher->n + 1, str);
	pthread_mutex_unlock(&philosopher->data->mutex);
}

long long	time_in_ms(struct timeval now)
{
	long long	ms;

	ms = now.tv_sec * 1000; // получаем время в мс из структуры timeval
	ms += now.tv_usec / 1000;
	return (ms);
}
