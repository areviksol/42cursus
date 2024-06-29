/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aremkrtc <aremkrtc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 17:14:57 by aremkrtc          #+#    #+#             */
/*   Updated: 2023/03/29 11:21:50 by aremkrtc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static	int	nb_args(char **args)
{
	int		size;

	size = 0;
	while (args[size])
		size++;
	return (size);
}

static int	isnnn(char *str)
{
	int	i;

	i = 2;
	if (str[0] != '-' && str[1] != 'n')
		return (0);
	if (str[i] != '\0')
	{
		if (str[i] != 'n')
			return (0);
		i++;
	}
	return (1);
}

int	check_condition(char **command, int i)
{
	if (command[i] && command[i][0] != '\0' && \
	((ft_strcmp(command[i], "-n") == 0) || isnnn(command[i])))
		return (1);
	else
		return (0);
}

int	echo(char **command)
{
	int		i;
	int		n_option;

	i = 1;
	n_option = 0;
	if (nb_args(command) > 1)
	{
		while (check_condition(command, i))
		{
			n_option = 1;
			i++;
		}
		while (command[i])
		{
			if (command[i] && command[i][0] != '\0')
				ft_putstr_fd(command[i], 1);
			if (command[i + 1] && command[i][0] != '\0')
				write(1, " ", 1);
			i++;
		}
	}
	if (n_option == 0)
		write(1, "\n", 1);
	return (0);
}
