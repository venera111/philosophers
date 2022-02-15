/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qestefan <qestefan@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 12:18:36 by qestefan          #+#    #+#             */
/*   Updated: 2022/02/15 15:24:05 by qestefan         ###   ########.fr       */
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
# define ERROR_TV "tv pointer outside the accessible address space.\n"

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <pthread.h>
# include <sys/time.h>

/*
** Philosopher
*/
typedef struct s_philosopher
{
	int				n;
	int				num_of_meals;
	pthread_mutex_t	philo_mutex;
	pthread_mutex_t	*left;
	pthread_mutex_t	*right;
	struct s_data	*data;
	struct timeval	last_meal;
	pthread_t		thread;
} t_philosopher;

/*
** Data
*/
typedef struct s_data
{
	int				num_of_philosophers;
	int				num_of_eat_finish;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_of_meals;
	t_philosopher	*philosophers;
	pthread_mutex_t	mutex;
	pthread_mutex_t	*forks;
	struct timeval	tv;
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
void		print_status(t_philosopher *philosopher, char *str);
uint64_t	current_time(struct timeval now);

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
