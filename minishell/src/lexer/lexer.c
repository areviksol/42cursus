/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aremkrtc <aremkrtc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 17:38:44 by aremkrtc          #+#    #+#             */
/*   Updated: 2023/03/30 22:32:05 by aremkrtc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_lexer(t_data *data)
{
	int	i;

	i = 0;
	data->token_list = NULL;
	while (data->command[i])
	{
		while (ft_is_space(data->command[i]))
			i++;
		if (!data->command[i])
			return ;
		if (data->command[i] == '"' || data->command[i] == '\'' )
			i = ft_handle_quotes(data, i);
		else if (ft_is_word(data->command[i]))
			i = ft_handle_word(data, i);
		else if (ft_is_redirection_in(data->command[i]))
			i = ft_handle_redirection_in(data, i);
		else if (ft_is_redirection_out(data->command[i]))
			i = ft_handle_redirection_out(data, i);
		else if (data->command[i] == '|')
			i = ft_handle_pipe(data, i);
		else
			return ;
	}
}

int	ft_handle_quotes(t_data *data, int i)
{
	int	start;

	start = i;
	i = ft_add_field(data, i);
	if (i == start)
		return (i);
	return (i);
}

int	ft_handle_word(t_data *data, int i)
{
	i = ft_add_word(data, i);
	return (i);
}

int	ft_handle_redirection_in(t_data *data, int i)
{
	i = ft_add_redirection_in(data, i);
	return (i);
}

int	ft_handle_redirection_out(t_data *data, int i)
{
	i = ft_add_redirection_out(data, i);
	return (i);
}
