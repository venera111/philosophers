/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qestefan <qestefan@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 12:18:36 by qestefan          #+#    #+#             */
/*   Updated: 2022/02/06 15:54:02 by qestefan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# define ERROR_ARGC "Error message : wrong arguments to function call.\n"
# define ERROR_MEAL "Error message : wrong num of meal.\n"
# define ERROR_NUM "Error message : wrong num of philosophers.\n"
# define ERROR_DIE "Error message : wrong time to die.\n"
# define ERROR_EAT "Error message : wrong time to eat.\n"
# define ERROR_SLEEP "Error message : wrong time to sleep.\n"

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
** Init and parsing
*/
int	initialization_philosophers(t_data *data, int argc, char **argv);
void	parsing_argv(t_data *data, int argc, char **argv);

/*
** Utils
*/
int		ft_atoi(const char *str);

/*
** Error
*/
int		ft_perror(char *finish);

#endif
