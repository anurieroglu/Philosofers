/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeroglu <aeroglu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 16:14:27 by aeroglu           #+#    #+#             */
/*   Updated: 2023/05/22 17:35:05 by aeroglu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_forks(t_philo *ph)
{
	if (ph->num % 2 == 1)
	{
		pthread_mutex_lock(&ph->args->forks[ph->r_fork]);
		pthread_mutex_lock(&ph->args->forks[ph->l_fork]);
	}
	else
	{
		pthread_mutex_lock(&ph->args->forks[ph->r_fork]);
		pthread_mutex_lock(&ph->args->forks[ph->l_fork]);
	}
	if (!check_death(ph))
	{
		pthread_mutex_lock(&ph->args->print_lock);
		printf("%-5ld %d has taken a fork\n", get_time() - ph->start_time,
			ph->num + 1);
		printf("%-5ld %d has taken a fork\n", get_time() - ph->start_time,
			ph->num + 1);
		pthread_mutex_unlock(&ph->args->print_lock);
	}
}

void	eat_time(t_philo *ph)
{
	take_forks(ph);
	if (!check_death(ph))
	{
		printf("%-5ld %d is eating\n", get_time() - ph->start_time, ph->num + 1);
		set_meals(ph);
		set_nb(ph);
		phsleep(ph->args->eat_time);
	}
	pthread_mutex_unlock(&ph->args->forks[ph->l_fork]);
	pthread_mutex_unlock(&ph->args->forks[ph->r_fork]);
}

void	sleep_time(t_philo *ph)
{
	if (!check_death(ph))
	{
		pthread_mutex_lock(&ph->args->print_lock);
		printf("%-5ld %d is sleeping\n", get_time() - ph->start_time,
			ph->num + 1);
		pthread_mutex_unlock(&ph->args->print_lock);
		phsleep(ph->args->sleep_time);
	}
}

void	think_time(t_philo *ph)
{
	if (!check_death(ph))
	{
		pthread_mutex_lock(&ph->args->print_lock);
		printf("%-5ld %d is thinking\n", get_time() - ph->start_time,
			ph->num + 1);
		pthread_mutex_unlock(&ph->args->print_lock);
		usleep(500);
	}
}

void	die_time(t_philo *ph)
{
	pthread_mutex_lock(&ph->args->print_lock);
	printf("%-5ld %d died\n", get_time() - ph->start_time, ph->num + 1);
	pthread_mutex_unlock(&ph->args->print_lock);
	set_death(ph);
}
