/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qestefan <qestefan@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:49:54 by qestefan          #+#    #+#             */
/*   Updated: 2022/02/04 13:11:00 by qestefan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <pthread.h>

void	*PrintHello(void *data)
{
	int	my_data;
	int	rc;

	my_data = (int)data;
	rc = pthread_detach(pthread_self()); // оператор отсоединяет вызывающий поток
	if (rc)
	{
		printf("No thread with the ID thread could be found");
		exit(1);
	}
	printf("Hello from new thread - got %d\n", my_data);
	pthread_exit(NULL);
}

int	main(int rgc, char **argv)
{
	pthread_t	thread_id;
	int			rc;
	int			t;

	t = 11;
	rc = pthread_create(&thread_id, NULL, PrintHello, (void *)t);
	if (rc)
	{
		printf("\n ERROR: return code from pthread_create is %d \n", rc);
		exit(1);
	}
	printf("\n Created new thread (%u) ... \n", thread_id);
	pthread_exit(NULL);
}
