/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qestefan <qestefan@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:49:54 by qestefan          #+#    #+#             */
/*   Updated: 2022/02/06 16:16:42 by qestefan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 5 && argc != 6)
	{
		ft_perror(ERROR_ARGC);
		exit(1);
	}
	memset(&data, 0, sizeof(data)); // заполняем нулями поля структуры
	if (initialization_philosophers(&data, argc, argv))
		return (1);
	return (0);
}
