/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qestefan <qestefan@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:49:54 by qestefan          #+#    #+#             */
/*   Updated: 2022/02/04 19:58:41 by qestefan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

void	*PrintHello(void *data)
{
	int	my_data;
	int	rc;
	my_data = (int)data;
	rc = pthread_detach(pthread_self()); // оператор отсоединяет вызывающий поток
	if (rc != 0)
	{
		printf("No thread with the ID thread could be found");
		exit(1);
	}
	printf("Hello from new thread - got %d\n", my_data);
	pthread_exit(NULL);
}

int	main(int rgc, char **argv)
{
	pthread_t	thread_id1, thread_id2; // ID потока
	int			result; // return функции pthread_creat, если != 0, то ошибка
	int			t1, t2; // для каждого потока создавать свои аргументы, чтобы избавиться от конфликта

	t1 = 11;
	/*
	** потоки могут создаться в разном порядке, нет гарантии последовательности
	** есть вероятность, что второй поток может запуститься раньше первого
	*/
	result = pthread_create(&thread_id1, NULL, PrintHello, (void *)t1); // функция запускает поток
	if (result != 0)
	{
		perror("Creating the first thread");
		return(EXIT_FAILURE);
	}
	t2 = 12;
	result = pthread_create(&thread_id2, NULL, PrintHello, (void *)t2); // функция запускает поток
	if (result != 0)
	{
		perror("Creating the first thread");
		return(EXIT_FAILURE);
	}
	/*
	** ожидает выполнение потока
	*/
	result = pthread_join(thread_id1, NULL);
	if (result != 0)
	{
		perror("Joining the first thread");
		return(EXIT_FAILURE);
	}
	/*
	** если к моменту уже завершился поток2, то функция ничего не ожидает и сразу отдает исполнение
	*/
	result = pthread_join(thread_id2, NULL);
	if (result != 0)
	{
		perror("Joining the second thread");
		return(EXIT_FAILURE);
	}
	printf("Done");
	pthread_exit(NULL);
}
