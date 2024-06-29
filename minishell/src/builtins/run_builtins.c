/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_builtins.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aremkrtc <aremkrtc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 18:57:05 by aremkrtc          #+#    #+#             */
/*   Updated: 2023/03/30 18:57:06 by aremkrtc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	is_builtin(char *arg)
{
	if (arg)
	{
		if ((ft_strcmp(arg, "cd") == 0) || (ft_strcmp(arg, "echo") == 0) || \
			(ft_strcmp(arg, "env") == 0) || (ft_strcmp(arg, "exit") == 0) || \
			(ft_strcmp(arg, "export") == 0) || (ft_strcmp(arg, "pwd") == 0) || \
			(ft_strcmp(arg, "unset") == 0))
			return (1);
	}
	return (0);
}

void	chgitem(t_data *data)
{
	ft_set_env_node(data->env_list, "?", "127", ENV);
	free_ptr_arr(data->envp);
	data->envp = env_from_list(data->env_list);
	exit(data->error_status);
}

void	wait_1(t_data *data)
{
	char	*tmp;

	wait(&data->error_status);
	if (WIFSIGNALED(data->error_status))
	{
		data->error_status = WTERMSIG(data->error_status) + 128;
		if (WTERMSIG(data->error_status) == SIGQUIT)
			ft_putstr_fd("Quit: 3\n", 1);
		if (WTERMSIG(data->error_status) == SIGINT)
			write(1, "\n", 1);
	}
	ft_set_env_node(data->env_list, "?", \
	tmp = ft_itoa(data->error_status % 255), ENV);
	free (tmp);
	signal(SIGINT, handler);
}

void	ft_exec(t_groups *groups, t_data *data)
{
	int		id;

	signal(SIGINT, SIG_IGN);
	id = fork();
	if (data->cmd_paths)
		data->path = get_path(data->cmd_paths, data, groups);
	if (id == 0)
	{
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
		cmd_errors(data, groups);
		execve(groups->args[0], groups->args, data->envp);
		if (data->path)
		{
			if ((execve(data->path, groups->args, data->envp)) == -1)
				chgitem(data);
		}
		else
			chgitem(data);
	}
	wait_1(data);
	free(data->path);
}

void	ft_builtin(t_groups *group, t_data *data)
{
	if (!ft_strcmp(group->args[0], "cd"))
		data->error_status = cd(group->args, data->env_list);
	else if (!ft_strcmp(group->args[0], "echo"))
		data->error_status = echo(group->args);
	else if (!ft_strcmp(group->args[0], "env"))
		data->error_status = env(data->env_list);
	else if (!ft_strcmp(group->args[0], "exit"))
		ft_exit(data, group->args, group);
	else if (!ft_strcmp(group->args[0], "export"))
		data->error_status = export(group->args, data->env_list, data);
	else if (!ft_strcmp(group->args[0], "pwd"))
		data->error_status = pwd();
	else if (!ft_strcmp(group->args[0], "unset"))
		data->error_status = unset(group->args, data->env_list);
}
