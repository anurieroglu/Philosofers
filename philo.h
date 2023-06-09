/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeroglu <aeroglu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 17:31:43 by aeroglu           #+#    #+#             */
/*   Updated: 2023/05/22 17:37:35 by aeroglu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

# define ARGS_ERROR 1
# define ARGS_NUM_ERROR 2

typedef struct s_arg
{
	int				nb_philo;
	int				max_eat;
	int				philo_ate;
	size_t			die_time;
	int				eat_time;
	int				sleep_time;
	int				stop_sim;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_lock;
	pthread_mutex_t	check_lock;
	pthread_mutex_t	nb_lock;
	pthread_mutex_t	death_lock;
}				t_arg;

typedef struct s_philo
{
	pthread_t	tid;
	t_arg		*args;
	int			num;
	size_t		start_time;
	size_t		last_meal;
	int			nb_eat;
	short		is_finished;
	int			r_fork;
	int			l_fork;
}				t_philo;

int		handle_error(short error_code);
int		ft_isdigit(char *str);
long	ft_atol(char *str);
int		check_arg(char **s);
t_arg	*parse_arg(char **str);
t_philo	**init_philo(t_arg *arg);
void	init_mutex(t_arg *arg);
size_t	get_time(void);
void	set_meals(t_philo *ph);
void	phsleep(size_t ms);
int		check_death(t_philo *ph);
void	set_nb(t_philo *ph);
void	eat_time(t_philo *ph);
void	sleep_time(t_philo *ph);
void	think_time(t_philo *ph);
void	die_time(t_philo *ph);
void	set_death(t_philo *ph);
int		check_philo(t_philo **ph, t_arg *arg);

#endif
