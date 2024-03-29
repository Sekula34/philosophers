/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fseles <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 15:23:02 by fseles            #+#    #+#             */
/*   Updated: 2024/01/26 15:23:04 by fseles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# define OK 0
# define FAIL 1
# define MICRO 1000000
# define MILI 1000

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_person
{
	int		id;
	int		left_fork;
	int		right_fork;
	time_t	last_meal_time;
	int		dead_flag;
	int		number_of_meals;
}	t_person;

typedef struct s_philosophers
{
	int				num_of_philos;
	time_t			time_to_die;
	time_t			time_to_eat;
	time_t			time_to_sleep;
	time_t			start_time;
	int				meals;
	pthread_mutex_t	*fork_num;
	pthread_mutex_t	write_mut;
	pthread_mutex_t	meal_mut;
	t_person		*person;
	void			*eaters;
	pthread_t		*eaters2;
	int				stop_simulation;
	int				thread_number;
}	t_philosophers;

typedef struct s_eater
{
	int				id;
	t_philosophers	*philo;
	t_person		*person;
	pthread_mutex_t	*first_fork;
	pthread_mutex_t	*second_fork;
}	t_eater;

int		am_i_dead(t_eater *diogen, int number_of_mutex);
int		eating_func(t_eater *diogen);
int		ft_atoi(const char *nptr);
int		ft_isdigit(int c);
time_t	get_relative_time(t_eater *diogen);
time_t	get_time_in_milisec(void);
void	gravedigger(t_eater *diogen);
int		input_checker(int argc, char **argv);
void	kill_all(t_eater *diogen);
void	kill_all_protected(t_eater *diogen, int not);
int		make_philos(t_philosophers *philo);
int		mutex_init(t_philosophers *philo);
void	only_one(t_philosophers *philo);
void	philo_end(t_philosophers *philo);
void	*philo_func(void *pointer);
int		philo_init(int argc, char **argv, t_philosophers *philo);
int		sleeping(t_eater *diogen);

#endif
