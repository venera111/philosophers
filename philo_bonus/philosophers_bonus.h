/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_bonus.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qestefan <qestefan@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 11:05:07 by qestefan          #+#    #+#             */
/*   Updated: 2022/02/17 11:19:12 by qestefan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_BONUS_H
# define PHILOSOPHERS_BONUS_H

# define ERROR_ARGC "Error message : wrong arguments to function call.\n"
# define ERROR_MEAL "Error message : wrong num of meal.\n"
# define ERROR_NUM "Error message : wrong num of philosophers.\n"
# define ERROR_DIE "Error message : wrong time to die.\n"
# define ERROR_EAT "Error message : wrong time to eat.\n"
# define ERROR_SLEEP "Error message : wrong time to sleep.\n"
# define ERROR_MALLOC "Error message : not allocated with malloc.\n"
# define ERROR_FORK "Error message : fork error.\n"
# define ERROR_INT "Error message : exceeding the int range.\n"
# define ERROR_ARG "Error message : number error.\n"

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <pthread.h>
# include <sys/time.h>
# include <semaphore.h>
# include <signal.h>

/*
** Philosopher
*/
typedef struct s_philosopher
{
	int				n;
	int				num_of_meals;
	char			*name;
	struct s_data	*data;
	struct timeval	last_meal;
	sem_t			*sem;
	pid_t			pid;
}	t_philosopher;

/*
** Data
*/
typedef struct s_data
{
	int				num_of_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_of_meals;
	t_philosopher	*philosophers;
	sem_t			*forks;
	struct timeval	tv;
	sem_t			*action;
	sem_t			*num_of_eat_finish;
	sem_t			*finish;
}	t_data;

/*
** Init and parsing
*/
int			initialization_philosophers(t_data *data, int argc, char **argv);

/*
** Action
*/
void		action_philosopher(t_philosopher *philosopher);

/*
** Utils
*/
int			ft_atoi(char *str);
int			ft_allocate(void *arg, size_t size);
char		*making_name(char *str, int n);
void		print_status(t_philosopher *philosopher, char *str);
uint64_t	current_time(struct timeval now);

/*
** Waiter
*/
void		*waiter(void *argv);
void		*waiter_each_meal(void *arg);
void		*waiter_finish(void *arg);

/*
** Error
*/
int			ft_perror(char *str);

#endif
