/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aremkrtc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 16:06:07 by aremkrtc          #+#    #+#             */
/*   Updated: 2022/11/16 16:06:09 by aremkrtc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	destroy_mutex(t_simulation *simulation, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < simulation->number_of_philosophers)
	{
		pthread_mutex_destroy(simulation->forks + i);
		i++;
	}
	free(philo);
	free(simulation->forks);
	free(simulation->threads);
	free(simulation->thinking);
	pthread_mutex_destroy(simulation->thinking);
}
