/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aremkrtc <aremkrtc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 16:44:43 by aremkrtc          #+#    #+#             */
/*   Updated: 2022/11/16 18:54:11 by aremkrtc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>

typedef struct timeval	t_time;

typedef struct s_simulation
{
	pthread_t			*threads;
	pthread_mutex_t		*forks;
	pthread_mutex_t		*thinking;
	unsigned long		start;
	int					number_of_philosophers;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					eat_counter;
	int					max_eat;
	int					is_dead;
	int					current_eat;
}				t_simulation;

typedef struct s_philo
{
	pthread_mutex_t	*eat;
	t_simulation	*data;
	unsigned int	eating_time;
	unsigned int	last_meal;
	int				index;
	int				right_hand;
	int				left_hand;
	int				is_dead;
	int				eat_counter;
	unsigned long	start;
}				t_philo;

int				ft_atoi(char *str);
int				is_num(char *arg);
int				validarg(char *arg);
int				validation(char **argv);
int				ft_strlen(char *str);
void			simulation_arg_init(t_simulation *s, char **argv);
void			init(char **argv, t_simulation *simulation, int argc);
void			ft_for_each_philo(t_simulation *simulation, \
						t_philo *philo, int i);
t_philo			*philosophers_init(t_simulation *simulation);
void			create_mutex(t_simulation *simulation);
void			destroy_mutex(t_simulation *simulation, t_philo *philo);
unsigned long	get_milliseconds(void);
void			ft_sleep(size_t ms);
int				ft_thinking(t_philo *philo);
int				ft_sleep2(t_philo *philo, size_t ms);
int				ft_eat(t_philo *philo);
int				ft_isdead(t_philo *philo);
void			status(t_philo *philo, char *str);
int				ft_isdead(t_philo *philo);
void			main_helper(t_simulation simulation, \
								t_philo *philo, void *routine);
void			loop(t_simulation simulation, int argc, \
								t_philo *philo, int counter);

#endif