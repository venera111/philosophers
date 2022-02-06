/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qestefan <qestefan@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 12:18:22 by qestefan          #+#    #+#             */
/*   Updated: 2022/02/06 12:29:29 by qestefan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_perror(char *finish)
{
	char	*start;

	start = finish;
	while (*finish)
		finish++;
	write(2, start, finish - start);
	exit(EXIT_FAILURE);
}
