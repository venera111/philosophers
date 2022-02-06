/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qestefan <qestefan@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 12:18:22 by qestefan          #+#    #+#             */
/*   Updated: 2022/02/06 15:51:05 by qestefan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_perror(char *finish)
{
	char	*start;

	start = finish;
	while (*finish)
		finish++;
	write(2, start, finish - start);
	return (1);
}

int	ft_atoi(const char *str)
{
	long	num;
	char	sign;

	num = 0;
	sign = 1;
	while (*str == ' ' || (*str <= '\r' && *str >= '\t'))
		str++;
	if ((*str == '-') || (*str == '+'))
		if (*str++ == '-')
			sign = -1;
	while (*str >= '0' && *str <= '9')
	{
		num = 10 * num + (*str++ - '0');
		if (num < 0)
		{
			if (sign < 0)
				return (0);
			else
				return (-1);
		}
	}
	return (sign * num);
}
