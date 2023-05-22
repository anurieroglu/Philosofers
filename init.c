/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeroglu <aeroglu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 15:29:00 by aeroglu           #+#    #+#             */
/*   Updated: 2023/05/22 17:33:58 by aeroglu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	**init_philo(t_arg *arg)
{
	t_philo	**philo;
	int		i;

	i = -1;
	philo = (t_philo **)malloc(sizeof(t_philo *) * (arg->nb_philo + 1));
	philo[arg->nb_philo] = NULL;
	while (++i < arg->nb_philo)
	{
		philo[i] = (t_philo *)malloc(sizeof(t_philo));
		memset(philo[i], 0, sizeof(t_philo));
		philo[i]->num = i;
		philo[i]->args = arg;
		philo[i]->nb_eat = 0;
		philo[i]->is_finished = 0;
		philo[i]->r_fork = i;
		philo[i]->l_fork = (i + 1) % (arg->nb_philo);
	}
	return (philo);
}

void	init_mutex(t_arg *arg)
{
	int	i;

	i = -1;
	arg->forks = (pthread_mutex_t *)malloc(sizeof(*arg->forks) * arg->nb_philo);
	while (++i < arg->nb_philo)
		pthread_mutex_init(&arg->forks[i], NULL);
	pthread_mutex_init(&arg->print_lock, NULL);
	pthread_mutex_init(&arg->check_lock, NULL);
	pthread_mutex_init(&arg->nb_lock, NULL);
	pthread_mutex_init(&arg->death_lock, NULL);
}
