/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeroglu <aeroglu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 17:51:12 by aeroglu           #+#    #+#             */
/*   Updated: 2023/05/22 17:33:05 by aeroglu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_arg(char **s)
{
	char	**p;

	p = s;
	while (*p)
	{
		if (!ft_isdigit(*p) || ft_atol(*p) < 0 || ft_atol(*p) > INT_MAX)
			return (1);
		++p;
	}
	return (0);
}

int	check_death(t_philo *ph)
{
	int	i;

	pthread_mutex_lock(&ph->args->death_lock);
	i = ph->args->stop_sim;
	pthread_mutex_unlock(&ph->args->death_lock);
	return (i);
}

int	check_nb(t_philo *ph)
{
	int	i;

	pthread_mutex_lock(&ph->args->nb_lock);
	i = ph->nb_eat;
	pthread_mutex_unlock(&ph->args->nb_lock);
	return (i);
}

size_t	check_meals(t_philo *ph)
{
	size_t	i;

	pthread_mutex_lock(&ph->args->check_lock);
	i = ph->last_meal;
	pthread_mutex_unlock(&ph->args->check_lock);
	return (i);
}

int	check_philo(t_philo **ph, t_arg *arg)
{
	int	i;

	i = -1;
	while (++i < arg->nb_philo)
	{
		if (check_meals(ph[i]) != 0
			&& get_time() - check_meals(ph[i]) > arg->die_time)
		{
			die_time(ph[i]);
			return (1);
		}
		if (!ph[i]->is_finished && check_nb(ph[i]) == arg->max_eat
			&& ++arg->philo_ate)
			++ph[i]->is_finished;
		if (arg->philo_ate == arg->nb_philo)
		{
			set_death(ph[i]);
			return (1);
		}
	}
	return (0);
}
