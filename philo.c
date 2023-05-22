/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeroglu <aeroglu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 17:31:31 by aeroglu           #+#    #+#             */
/*   Updated: 2023/05/22 17:36:00 by aeroglu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*only(t_philo *ph)
{
	pthread_mutex_lock(&ph->args->forks[ph->r_fork]);
	printf("%-5ld %d has taken a fork\n", get_time() - ph->start_time,
		ph->num + 1);
	pthread_mutex_unlock(&ph->args->forks[ph->r_fork]);
	return (NULL);
}

void	*start(void *philo)
{
	t_philo	*ph;

	ph = (t_philo *)philo;
	ph->start_time = get_time();
	set_meals(ph);
	if (ph->args->nb_philo == 1)
		return (only(ph));
	if (ph->num % 2 == 1)
		phsleep(1);
	while (!check_death(ph))
	{
		eat_time(ph);
		sleep_time(ph);
		think_time(ph);
	}
	return (NULL);
}

int	main(int ac, char **av)
{
	t_philo	**philo;
	t_arg	*arg;
	int		i;

	if (ac < 5 || ac > 6)
		return (handle_error(ARGS_NUM_ERROR));
	i = -1;
	if (check_arg(++av))
		return (handle_error(ARGS_ERROR));
	arg = parse_arg(av);
	philo = init_philo(arg);
	init_mutex(arg);
	while (++i < arg->nb_philo)
		pthread_create(&(philo[i]->tid), NULL, start, philo[i]);
	while (!check_philo(philo, arg))
		phsleep(1);
	i = -1;
	while (++i < arg->nb_philo)
		pthread_join(philo[i]->tid, NULL);
	system("leaks philo");
	return (0);
}
