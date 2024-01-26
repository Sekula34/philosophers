/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fseles <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 15:23:23 by fseles            #+#    #+#             */
/*   Updated: 2024/01/26 15:23:25 by fseles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

// void *my_thread(void *argp)
// {
// 	printf("cao ja sam dretva \n");
// 	return NULL;
// }

int main()
{
	struct timeval my_time;

	if(gettimeofday(&my_time, NULL) != 0)
	{
		perror("gettimeofday failed");
		return (FAIL);
	}
	printf("trenutno vrijeme je %ld sekundi i %ld mikrosekundi\n", my_time.tv_sec, my_time.tv_usec);
	//if(pthread_create())
	usleep(5 * MICRO);
	if(gettimeofday(&my_time, NULL) != 0)
	{
		perror("gettimeofday failed");
		return (FAIL);
	}
	printf("trenutno vrijeme je %ld sekundi i %ld mikrosekundi\n", my_time.tv_sec, my_time.tv_usec);
	printf("hello i am filip\n");
	return(OK);
}