/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fseles <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:45:39 by fseles            #+#    #+#             */
/*   Updated: 2024/01/30 15:45:40 by fseles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

//option 1 first fork
//option 2 second fork
static pthread_mutex_t	*get_fork(t_eater *diogen, int id, int option)
{
	pthread_mutex_t	*first;

	if (option == 2)
		id++;
	if (id % 2 == 1)
		first = &diogen->philo->fork_num[diogen->person->left_fork];
	else
		first = &diogen->philo->fork_num[diogen->person->right_fork];
	return (first);
}

static void	set_forks(t_eater *diogen)
{
	diogen->first_fork = get_fork(diogen, diogen->person->id, 1);
	diogen->second_fork = get_fork(diogen, diogen->person->id, 2);
}

time_t	get_relative_time(t_eater *diogen)
{
	time_t	current_time;
	time_t	relative_time;

	current_time = get_time_in_milisec();
	relative_time = current_time - diogen->philo->start_time;
	return (relative_time);
}

//0 continue
//1 break
int	loop_function(t_eater *diogen, int *i, int *loop_cond)
{
	if (eating_func(diogen) == 0)
		return (1);
	if (sleeping(diogen) == 0)
		return (1);
	if (diogen->philo->meals != -1)
		*i = *i + 1;
	if (*i == diogen->philo->meals)
	{
		pthread_mutex_lock(&diogen->philo->meal_mut);
		*loop_cond = 0;
		pthread_mutex_unlock(&diogen->philo->meal_mut);
	}
	pthread_mutex_lock(&diogen->philo->meal_mut);
	if (diogen->philo->stop_simulation == 1)
		*loop_cond = 0;
	pthread_mutex_unlock(&diogen->philo->meal_mut);
	return (0);
}

void	*philo_func(void *pointer)
{
	t_eater	*diogen;
	int		i;
	int		loop_cond;

	diogen = (t_eater *)pointer;
	set_forks(diogen);
	i = 0;
	loop_cond = 1;
	if (diogen->philo->meals == 0)
		loop_cond = 0;
	while (loop_cond)
	{
		if (loop_function(diogen, &i, &loop_cond) == 1)
			break ;
	}
	return (NULL);
}
