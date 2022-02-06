/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qestefan <qestefan@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 12:18:22 by qestefan          #+#    #+#             */
/*   Updated: 2022/02/06 21:18:54 by qestefan         ###   ########.fr       */
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

int	ft_perror(char *finish)
{
	char	*start;

	start = finish;
	while (*finish)
		finish++;
	write(2, start, finish - start);
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
			ft_perror("Error message : exceeding the int range");
	}
	if (!(str[i] >= '0' && str[i] <= '9') && str[i] != '\0')
		ft_perror("Error message : number error");
	return (res);
}
