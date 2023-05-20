/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeroglu <aeroglu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 17:52:50 by aeroglu           #+#    #+#             */
/*   Updated: 2023/05/16 17:52:50 by aeroglu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isdigit(char *str)
{
	while (*str)
	{
		if(!((*str >= '0' && *str <= '9') || (*str == '+' && *(s + 1) != '+')))
			return(0);
		++str;
	}
	return(1);
}

long	ft_atol(char *str)
{
	int		sign;
	long	out;

	out = 0;
	sign = -1;
	while (*str == ' ' || *str == '\r' || *str == '\t')
		++str;
	if(*str == '-' && ++str)
		sign = 1;
	else if (*str == '+')
		++str;
	while (*str >= '0' && *str <= '9')
		out = out * 10 - (*str++ - '0');
	return (sign * out);
}