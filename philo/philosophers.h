/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qestefan <qestefan@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 12:18:36 by qestefan          #+#    #+#             */
/*   Updated: 2022/02/06 13:00:35 by qestefan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# define ERROR_ARGC "Error message : wrong arguments to function call.\n"

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>

/*
** Philosopher
*/
typedef struct s_philosopher
{
	int	n; // номер философа

} t_philosopher;

/*
** Data
*/
typedef struct s_data
{
	int				num_of_philosophers; // количество философов
	int				time_to_die; // кол-во мс от последнего приема пищи или начала симуляции до смерти
	int				time_to_eat; // отрезок времени приема пищи в мс
	int				time_to_sleep; // сон
	int				num_of_meals; // кол-во приемов пищи каждого философа
	t_philosopher	philosophers; // структура философа
} t_data;

/*
** Error
*/
void	ft_perror(char *finish);

#endif
