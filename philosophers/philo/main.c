/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aremkrtc <aremkrtc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 16:11:01 by aremkrtc          #+#    #+#             */
/*   Updated: 2022/11/16 18:50:37 by aremkrtc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*routine(void *arg)
{
	t_philo	*philo;
	t_time	current_time;

	philo = arg;
	gettimeofday(&current_time, NULL);
	philo->start = (current_time.tv_sec * 1000) + (current_time.tv_usec / 1000);
	if (philo->index % 2 == 0)
		usleep(200);
	while (1)
	{
		if (ft_eat(philo))
			return (arg);
		philo->eat_counter++;
		if (ft_sleep2(philo, philo->data->time_to_sleep))
			return (arg);
		if (ft_thinking(philo))
			return (arg);
	}
	return (arg);
}

int	ft_check_counter(t_philo *philo, int number)
{
	int	i;

	i = 0;
	while (i < philo->data->number_of_philosophers)
	{
		if (philo[i].eat_counter < number)
			return (0);
	}
	return (1);
}

int	is_dead_philosophers(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->data->number_of_philosophers)
	{
		if (ft_isdead(&philo[i]))
			return (1);
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_simulation	simulation;
	t_philo			*philo;
	int				counter;
	int				i;

	counter = 0;
	i = -1;
	if ((argc != 5 && argc != 6) || validation(argv))
		return (0);
	init(argv, &simulation, argc);
	philo = philosophers_init(&simulation);
	main_helper(simulation, philo, routine);
	while (1)
	{
		loop(simulation, argc, philo, counter);
		break ;
	}
	destroy_mutex(&simulation, philo);
	return (0);
}

void	simulation_arg_init(t_simulation *s, char **argv)
{
	s->number_of_philosophers = ft_atoi(argv[1]);
	s->threads = malloc(sizeof(pthread_t) * ft_atoi(argv[1]));
	s->forks = malloc(sizeof(pthread_mutex_t) * ft_atoi(argv[1]));
	s->thinking = malloc(sizeof(pthread_mutex_t));
	s->time_to_die = ft_atoi(argv[2]);
	s->time_to_eat = ft_atoi(argv[3]);
	s->time_to_sleep = ft_atoi(argv[4]);
}
