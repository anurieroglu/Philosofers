/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeroglu <aeroglu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 17:45:45 by aeroglu           #+#    #+#             */
/*   Updated: 2023/05/22 17:33:31 by aeroglu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	handle_error(short error_code)
{
	if (error_code == ARGS_ERROR)
		printf("Argument is not a digit "
			"or it overflows int"
			"or it is negative"
			"or have two plus signs\n");
	else if (error_code == ARGS_NUM_ERROR)
		printf("Wrong number of arguments\n");
	return (1);
}
