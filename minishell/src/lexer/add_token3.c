/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_token3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aremkrtc <aremkrtc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 15:39:58 by aremkrtc          #+#    #+#             */
/*   Updated: 2023/03/30 02:41:06 by aremkrtc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	check_f(t_ft_add_f_first *first, char **command, t_data *data)
{
	if (first->c == '"')
		data->token_list = ft_add_token_back(data->token_list, \
		*command, EXP_FIELD);
	else if (first->c == '\'')
		data->token_list = ft_add_token_back(data->token_list, *command, FIELD);
}

void	ft_add_f_second_if(t_data *data, \
t_ft_add_f_first *first, char **command)
{
	int	p;

	p = first->i;
	if (!isspace(data->command[p + 1]) && data->command[p + 1] != '\0')
	{
		first->flag = 1;
		while (data->command[p] && !isspace(data->command[p]) \
		&& data->command[p] != '\0' && data->command[p] != '\0')
		{
			first->i++;
			p++;
		}
		first->len = p - first->begin;
	}
	first->i++;
	*command = ft_substr(data->command, first->begin, first->len + 1);
	if (first->flag)
		data->token_list = ft_add_token_back(data->token_list, *command, WORD);
	else
		check_f(first, command, data);
}

int	ft_add_field(t_data *data, int i)
{
	char				*command;
	t_ft_add_f_first	first;

	first.len = 0;
	first.begin = i;
	first.c = 0;
	first.flag = 0;
	first.i = i;
	command = NULL;
	if (data->command[first.i] == '"' || data->command[first.i] == '\'')
		ft_add_f_first_if(data, &first);
	if (data->command[first.i] == first.c)
		ft_add_f_second_if(data, &first, &command);
	else
		ft_print_error(data, "Invalid chakert\n");
	if (data->command[first.begin] == '\0')
	{
		first.i--;
		return (first.i);
	}
	if (first.i > 0 && data->command[first.i -1] == '\0')
		first.i--;
	return (first.i);
}
