/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grouping4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aremkrtc <aremkrtc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 14:39:30 by aremkrtc          #+#    #+#             */
/*   Updated: 2023/03/31 14:39:31 by aremkrtc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	ankap(t_data *data, t_hdoc	*hdoc)
{
	close(data->groups->fd_in);
	data->groups->fd_in = hdoc->file_descriptor;
	data->token_list = data->token_list->next;
}

int	ft_herdoc(t_data *data, char *delimiter)
{
	t_hdoc	hdoc;
	char	*read_;

	ft_h_init(data, &hdoc);
	signal(SIGINT, heredoc_sig);
	while (1)
	{
		read_ = readline("> ");
		if (g_status == 10)
		{
			g_status = 0;
			free_ptr_arr(data->groups->args);
			free_token_list(data->token_list);
			return (free(read_), 1);
		}
		if (!read_)
			break ;
		if (ft_strcmp(read_, delimiter) == 0)
		{
			free(read_);
			break ;
		}
		h_h(data, read_, delimiter);
	}
	return (ankap(data, &hdoc), 0);
}

int	grouping_1(t_data *data)
{
	if (data->groups->fd_in != 0)
		close(data->groups->fd_in);
	data->token_list = data->token_list->next;
	data->groups->fd_in = \
	open(data->token_list->value, O_RDONLY);
	if (data->groups->fd_in == -1)
	{
		ft_set_env_node(data->env_list, "?", "1", ENV);
		return (ft_print_error(data, "invalid \n"));
	}
	return (0);
}

int	grouping_2(t_data *data)
{
	data->token_list = data->token_list->next;
	data->groups->fd_out = open(data->token_list->value, \
	O_CREAT | O_APPEND | O_RDWR, 0777);
	if (data->groups->fd_out == -1)
	{
		ft_set_env_node(data->env_list, "?", "1", ENV);
		return (ft_print_error(data, "invalid file\n"));
	}
	return (0);
}

int	grouping_3(t_data *data)
{
	data->token_list = data->token_list->next;
	data->groups->fd_out = open(data->token_list->value, \
	O_CREAT | O_TRUNC | O_RDWR, 0644);
	if (data->groups->fd_out == -1)
	{
		ft_set_env_node(data->env_list, "?", "1", ENV);
		return (ft_print_error(data, "invalid file\n"));
	}
	return (0);
}
