/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeroglu <aeroglu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 17:52:50 by aeroglu           #+#    #+#             */
/*   Updated: 2023/05/22 17:39:03 by aeroglu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	get_time(void)
{
	struct timeval	tv;
	size_t			ms;

	gettimeofday(&tv, NULL);
	ms = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	return (ms);
}

void	phsleep(size_t ms)
{
	size_t	start;

	start = get_time();
	while (get_time() - start < ms)
		usleep(100);
}

int	ft_isdigit(char *str)
{
	while (*str)
	{
		if (!((*str >= '0' && *str <= '9') || (*str == '+'
					&& *(str + 1) != '+')))
			return (0);
		++str;
	}
	return (1);
}

long	ft_atol(char *str)
{
	int		sign;
	long	out;

	out = 0;
	sign = -1;
	while (*str == ' ' || *str == '\r' || *str == '\t')
		++str;
	if (*str == '-' && ++str)
		sign = 1;
	else if (*str == '+')
		++str;
	while (*str >= '0' && *str <= '9')
		out = out * 10 - (*str++ - '0');
	return (sign * out);
}
