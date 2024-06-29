/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aremkrtc <aremkrtc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 16:59:46 by aremkrtc          #+#    #+#             */
/*   Updated: 2022/11/16 18:52:53 by aremkrtc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	main_helper(t_simulation simulation, t_philo *philo, void *routine)
{	
	int	i;

	i = -1;
	while (++i < simulation.number_of_philosophers)
		pthread_mutex_init(&philo->data->forks[i], NULL);
	i = -1;
	while (++i < simulation.number_of_philosophers)
	{
		philo[i].start = get_milliseconds();
		pthread_create(&simulation.threads[i], NULL, routine, &philo[i]);
		pthread_detach(simulation.threads[i]);
	}
}

void	loop(t_simulation simulation, int argc, \
		t_philo *philo, int counter)
{
	int	i;

	i = -1;
	while (++i % simulation.number_of_philosophers \
			< simulation.number_of_philosophers)
	{
		if (argc == 6)
		{
			if (philo[i % simulation.number_of_philosophers].eat_counter \
					>= simulation.eat_counter)
				counter++;
			usleep(200);
			if (counter == simulation.number_of_philosophers)
				break ;
		}
		if (ft_isdead(&philo[i % simulation.number_of_philosophers]))
		{
			printf("%lu %d died\n", \
					get_milliseconds() - philo->start, philo->index);
			break ;
		}
	}
}
