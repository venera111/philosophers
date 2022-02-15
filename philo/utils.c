/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qestefan <qestefan@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 12:18:22 by qestefan          #+#    #+#             */
/*   Updated: 2022/02/15 15:25:29 by qestefan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_allocate(void *arg, size_t size)
{
	*(void **)arg = malloc(size);
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

void	print_status(t_philosopher *philosopher, char *str)
{
	uint64_t		cur_time;
	struct timeval	now;

	pthread_mutex_lock(&philosopher->data->mutex);
	gettimeofday(&now, NULL);
	cur_time = current_time(now) - current_time(philosopher->data->tv);
	if (!philosopher->data->finish)
		printf("%lld\t%d\t%s\n", cur_time, philosopher->n + 1, str);
	pthread_mutex_unlock(&philosopher->data->mutex);
}

uint64_t	current_time(struct timeval now)
{
	uint64_t	cur_time;

	cur_time = now.tv_sec * 1000;
	cur_time += now.tv_usec / 1000;
	return (cur_time);
}
