/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main6.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aremkrtc <aremkrtc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 12:05:19 by aremkrtc          #+#    #+#             */
/*   Updated: 2023/03/30 18:58:48 by aremkrtc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	main2(t_data *data)
{
	data->in = 0;
	data->out = 1;
	data->dup0 = dup(STDIN_FILENO);
	data->dup1 = dup(STDOUT_FILENO);
	if (ft_lstsize(data->groups) == 1)
	{
		free_ptr_arr(data->envp);
		data->envp = NULL;
		dup2(data->groups->fd_in, STDIN_FILENO);
		dup2(data->groups->fd_out, STDOUT_FILENO);
		execute_builtin(data->groups, data);
		dup2(data->dup0, STDIN_FILENO);
		dup2(data->dup1, STDOUT_FILENO);
		close(data->dup0);
		close(data->dup1);
	}
	else
	{
		free_ptr_arr(data->envp);
		data->envp = env_from_list(data->env_list);
		execute_pipeline(data->groups, data);
		wait(NULL);
	}
}

void	main3(t_data *data)
{
	signal_call(1);
	if (g_status == 1234)
	{
		ft_set_env_node(data->env_list, "?", "1", ENV);
		g_status = 0;
	}
	data->error_status = 0;
	data->command = readline("Minishell$ ");
	if (!data->command)
	{
		write(1, "exit\n", 5);
		exit(ft_atoi(ft_gval(data->env_list, "$")));
	}
	ft_lexer(data);
	if (ft_strcmp(data->command, ""))
		add_history(data->command);
}

void	check_er_h(t_data *data)
{
	free(data->command);
	free_token_list(data->token_list);
	ft_set_env_node(data->env_list, "?", "258", ENV);
}

int	g_status_ma(t_data *data)
{
	data->cmd_paths = NULL;
	data->path = NULL;
	if (g_status == 10)
	{
		g_status = 0;
		free(data->command);
		return (1);
	}
	if (data->groups->args && data->groups->args[0])
		main2(data);
	if (data->groups)
		free_groups(data->groups);
	return (0);
}
