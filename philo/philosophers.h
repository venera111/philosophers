/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qestefan <qestefan@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 12:18:36 by qestefan          #+#    #+#             */
/*   Updated: 2022/02/15 14:19:44 by qestefan         ###   ########.fr       */
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
# define ERROR_MALLOC "Error message : not allocated with malloc.\n"
# define ERROR_INT "Error message : exceeding the int range.\n"
# define ERROR_ARG "Error message : number error.\n"

# include <stdio.h> // printf
# include <stdlib.h> // malloc
# include <unistd.h> // write
# include <string.h> // memset
# include <pthread.h> // threads
# include <sys/time.h> //gettimeofday

/*
** Philosopher
*/
typedef struct s_philosopher
{
	int				n; // номер философа
	int				num_of_meals;
	pthread_mutex_t	philo_mutex;
	pthread_mutex_t	*left;
	pthread_mutex_t	*right;
	struct s_data	*data; //указатель на общие данные
	struct timeval	last_meal; // время последнего приема пищи
	pthread_t		thread;
} t_philosopher;

/*
** Data
*/
typedef struct s_data
{
	int				num_of_philosophers; // количество философов
	int				num_of_eat_finish;
	int				time_to_die; // кол-во мс от последнего приема пищи или начала симуляции до смерти
	int				time_to_eat; // отрезок времени приема пищи в мс
	int				time_to_sleep; // сон
	int				num_of_meals; // кол-во приемов пищи каждого философа
	t_philosopher	*philosophers; // структура философа
	pthread_mutex_t	mutex; // mutex
	pthread_mutex_t	*forks; // вилки
	struct timeval	tv; // create time, является структурой
	int				finish;
}	t_data;

/*
** Init and parsing
*/
int			initialization_philosophers(t_data *data, int argc, char **argv);

/*
** Action
*/
void		*action_philosopher(void *data);

/*
** Utils
*/
int			ft_atoi(char *str);
int			ft_allocate(void *arg, size_t size);
void		print_philosophers(t_philosopher *philosopher, char *str);
long long	time_in_ms(struct timeval now);

/*
** Waiter
*/
void		*waiter(void *arg);
void		*waiter_each_meal(void *arg);

/*
** Error
*/
int			ft_perror(char *str);

#endif
