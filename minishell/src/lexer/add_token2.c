/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_token2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aremkrtc <aremkrtc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 15:29:43 by aremkrtc          #+#    #+#             */
/*   Updated: 2023/03/29 15:47:34 by aremkrtc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	get_end_index(t_data *data, int i)
{
	char	c;

	c = data->command[i];
	i++;
	while (data->command[i] && data->command[i] != c)
		i++;
	if (data->command[i] == c)
		return (i);
	return (-1);
}

int	check_flag(t_data *data, int begin, int end)
{
	int	p;

	p = begin;
	while (p <= end)
	{
		if (!isspace(data->command[p]) && data->command[p] != '\0')
			return (1);
		p++;
	}
	return (0);
}

void	ft_add_f_first_if(t_data *data, t_ft_add_f_first *first)
{
	if (data->command[first->i] && !isspace(data->command[first->i]) && \
	data->command[first->i] != '$')
	{
		first->flag = 1;
		while (first->begin > 0 && !isspace(data->command[first->begin - 1]))
			first->begin--;
		first->len = first->i - first->begin;
	}
	first->c = data->command[first->i];
	first->i++;
	first->len++;
	while (data->command[first->i] && data->command[first->i] != first->c)
	{
		first->i++;
		first->len++;
	}
}
