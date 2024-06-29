/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aremkrtc <aremkrtc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 16:31:24 by aremkrtc          #+#    #+#             */
/*   Updated: 2022/11/16 18:22:09 by aremkrtc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_philo	*philosophers_init(t_simulation *simulation)
{
	t_philo	*philo;
	int		i;

	i = -1;
	philo = malloc(sizeof(t_philo) * (simulation->number_of_philosophers + 1));
	if (!philo)
		return (NULL);
	while (++i < simulation->number_of_philosophers)
		ft_for_each_philo(simulation, philo, i);
	return (philo);
}

void	ft_for_each_philo(t_simulation *simulation, t_philo *philo, int i)
{
	philo[i].last_meal = 0;
	philo[i].index = i;
	philo[i].left_hand = i;
	philo[i].right_hand = (i + 1) % simulation->number_of_philosophers;
	philo[i].is_dead = 0;
	philo[i].data = simulation;
	philo[i].eat = malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(philo[i].eat, NULL);
	if (simulation->eat_counter == -1)
		philo[i].eat_counter = -1;
	philo[i].eat_counter = 0;
}

void	init(char **argv, t_simulation *simulation, int argc)
{
	int	num;
	int	i;

	i = 1;
	simulation_arg_init(simulation, argv);
	if (argc == 6)
	{
		num = ft_atoi(argv[5]);
		if (num == 0)
		{
			simulation->eat_counter = -1;
			simulation->current_eat = -1;
			simulation->max_eat = -1;
		}
		else
		{
			simulation->eat_counter = num;
			simulation->current_eat = 0;
			simulation->max_eat = num * simulation->number_of_philosophers;
		}
	}
	simulation->start = get_milliseconds();
}
