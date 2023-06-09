/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeroglu <aeroglu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 15:23:48 by aeroglu           #+#    #+#             */
/*   Updated: 2023/05/22 17:35:20 by aeroglu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_arg	*parse_arg(char **str)
{
	t_arg	*arg;

	arg = (t_arg *)malloc(sizeof(t_arg));
	arg->nb_philo = ft_atol(*str++);
	arg->die_time = ft_atol(*str++);
	arg->eat_time = ft_atol(*str++);
	arg->sleep_time = ft_atol(*str++);
	if (*str)
		arg->max_eat = ft_atol(*str++);
	else
		arg->max_eat = -1;
	arg->philo_ate = 0;
	arg->stop_sim = 0;
	return (arg);
}
