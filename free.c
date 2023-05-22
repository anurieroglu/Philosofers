/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeroglu <aeroglu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 17:27:22 by aeroglu           #+#    #+#             */
/*   Updated: 2023/05/22 17:33:46 by aeroglu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_philo(t_philo **ph)
{
	t_philo	**head;

	head = ph;
	while (ph && *ph)
		free(*ph++);
	free(head);
}

void	free_arg(t_arg *arg)
{
	int	i;

	i = -1;
	while (++i < arg->nb_philo)
		pthread_mutex_destroy(&arg->forks[i]);
	free(arg->forks);
	pthread_mutex_destroy(&arg->print_lock);
	pthread_mutex_destroy(&arg->check_lock);
	pthread_mutex_destroy(&arg->nb_lock);
	pthread_mutex_destroy(&arg->death_lock);
	free(arg);
}
