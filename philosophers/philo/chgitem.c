/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chgitem.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aremkrtc <aremkrtc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 19:46:59 by aremkrtc          #+#    #+#             */
/*   Updated: 2022/11/16 16:05:20 by aremkrtc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

unsigned long	get_milliseconds(void)
{
	t_time	current_time;

	gettimeofday(&current_time, NULL);
	return ((current_time.tv_sec * 1000) + (current_time.tv_usec / 1000));
}

void	ft_sleep(size_t ms)
{
	t_time	tv;
	size_t	now;

	gettimeofday(&tv, NULL);
	now = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	while ((get_milliseconds() - now) < ms)
		usleep(100);
}

void	status(t_philo *philo, char *str)
{
	pthread_mutex_lock(philo->data->thinking);
	printf("%lu %d %s\n", get_milliseconds() - \
			philo->start, philo->index + 1, str);
	pthread_mutex_unlock(philo->data->thinking);
}

void	my_sleep(unsigned long time)
{
	unsigned long	i;

	i = get_milliseconds();
	while (1)
		if ((get_milliseconds() - i) >= time)
			break ;
}

int	ft_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->forks[philo->left_hand]);
	printf("%lu %d has taken a fork\n", \
			get_milliseconds() - philo->start, philo->index);
	pthread_mutex_lock(&philo->data->forks[philo->right_hand]);
	printf("%lu %d has taken a fork\n", \
			get_milliseconds() - philo->start, philo->index);
	philo->last_meal = get_milliseconds() - philo->start;
	if (ft_isdead(philo))
		return (1);
	printf("%lu %d is eating\n", \
			get_milliseconds() - philo->start, philo->index);
	my_sleep(philo->data->time_to_eat);
	return (0);
}
