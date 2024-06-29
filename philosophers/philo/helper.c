/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aremkrtc <aremkrtc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 15:59:18 by aremkrtc          #+#    #+#             */
/*   Updated: 2022/11/16 18:39:57 by aremkrtc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_isdead(t_philo *philo)
{
	int	now;
	int	diff;

	now = get_milliseconds() - philo->start;
	diff = now - philo->last_meal;
	if (diff >= philo->data->time_to_die)
		return (1);
	return (0);
}

int	ft_sleep2(t_philo *philo, size_t ms)
{
	size_t	now;
	t_time	tv;

	printf("%lu %d is sleeping\n", \
			get_milliseconds() - philo->start, philo->index);
	pthread_mutex_unlock(&philo->data->forks[philo->right_hand]);
	pthread_mutex_unlock(&philo->data->forks[philo->left_hand]);
	gettimeofday(&tv, NULL);
	now = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	while ((get_milliseconds() - now) < ms)
		;
	return (ft_isdead(philo));
}

int	ft_thinking(t_philo *philo)
{
	pthread_mutex_lock(philo->data->thinking);
	if (ft_isdead(philo))
		return (1);
	printf("%lu %d is thinking\n", \
			get_milliseconds() - philo->start, philo->index);
	pthread_mutex_unlock(philo->data->thinking);
	return (0);
}
