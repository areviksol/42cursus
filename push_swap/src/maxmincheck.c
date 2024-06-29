/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maxmincheck.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aremkrtc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 17:08:17 by aremkrtc          #+#    #+#             */
/*   Updated: 2022/09/12 17:17:23 by aremkrtc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/stack.h"

int	maxmincheck(t_stack *a)
{
	while (a != NULL)
	{
		if (a->value > 2147483647 || a->value < -2147483647 - 1)
		{
			return (0);
		}
		a = a->next;
	}
	return (1);
}

int	a(char **av, int i)
{
	if (ft_strlen(av[i]) > 10 && av[i][0] != '-')
		return (0);
	if (ft_strlen(av[i]) > 11 && (av[i][0] == '-' || av[i][0] == '+'))
		return (0);
	if (av[i][0] != '-' && ft_strcmp("2147483647", av[i]) < 0
			&& ft_strlen(av[i]) >= 10)
		return (0);
	if (av[i][0] == '-' && ft_strcmp("-2147483648", av[i]) < 0
			&& ft_strlen(av[i]) >= 11)
		return (0);
	return (1);
}
