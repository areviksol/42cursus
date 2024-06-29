/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_token.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aremkrtc <aremkrtc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 18:57:26 by aremkrtc          #+#    #+#             */
/*   Updated: 2023/03/30 18:57:27 by aremkrtc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_add_word(t_data *data, int i)
{
	char	*command;

	command = ft_substr(data->command, i, ft_word_len(data->command, i));
	i += ft_word_len(data->command, i);
	data->token_list = ft_add_token_back(data->token_list, command, WORD);
	return (i);
}

int	ft_add_redirection_in(t_data *data, int i)
{
	char	*command;
	int		len;

	data->begin_in = i;
	len = 0;
	command = NULL;
	while (data->command[i] && ft_is_redirection_in(data->command[i]))
	{
		i++;
		len++;
	}
	command = ft_substr(data->command, data->begin_in, len);
	if (len == 1)
		data->token_list = \
		ft_add_token_back(data->token_list, command, RD_IN);
	else if (len == 2)
		data->token_list = \
		ft_add_token_back(data->token_list, command, RD_INSOURCE);
	else
	{
		ft_set_env_node(data->env_list, "$", "258", ENV);
		ft_print_error(data, "Invalid redirects\n");
		free(command);
	}
	return (i);
}

int	ft_add_redirection_out(t_data *data, int i)
{
	char	*command;
	int		len;

	data->begin_out = i;
	len = 0;
	command = NULL;
	while (data->command[i] && ft_is_redirection_out(data->command[i]))
	{
		i++;
		len++;
	}
	command = ft_substr(data->command, data->begin_out, len);
	if (len == 1)
		data->token_list = \
		ft_add_token_back(data->token_list, command, RD_OUT);
	else if (len == 2)
		data->token_list = \
		ft_add_token_back(data->token_list, command, RD_APPEND);
	else
	{
		ft_set_env_node(data->env_list, "$", "258", ENV);
		ft_print_error(data, "Invalid redirects\n");
		free(command);
	}
	return (i);
}

int	ft_add_pipe(t_data *data, int i)
{
	int		begin;
	char	*command;
	int		len;

	begin = i;
	command = NULL;
	len = 0;
	while (data->command[i] && data->command[i] == '|')
	{
		i++;
		len++;
	}
	command = ft_substr(data->command, begin, len);
	if (len == 1)
		data->token_list = ft_add_token_back(data->token_list, command, PIPE);
	else
		ft_print_error(data, "Invalid pipes");
	return (i);
}

int	get_begin_index(t_data *data, int i)
{
	int	begin;

	begin = i;
	if (data->command[begin] && !isspace(data->command[begin]) \
	&& data->command[begin] != '$')
	{
		while (begin > 0 && !isspace(data->command[begin - 1]))
			begin--;
	}
	return (begin);
}
