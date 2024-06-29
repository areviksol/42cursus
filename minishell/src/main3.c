/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aremkrtc <aremkrtc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 11:55:17 by aremkrtc          #+#    #+#             */
/*   Updated: 2023/03/29 16:39:36 by aremkrtc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	multipipe(int i, int num_cmds, t_groups *groups, \
	int (*fd_pipe)[2], t_data *data)
{
	signal(SIGQUIT, SIG_DFL);
	if (groups->fd_in != STDIN_FILENO)
		dup2(groups->fd_in, STDIN_FILENO);
	if (groups->fd_out != STDOUT_FILENO)
		dup2(groups->fd_out, STDOUT_FILENO);
	if (num_cmds != 1)
	{
		if (i == 0)
			dup2(fd_pipe[0][1], groups->fd_out);
		else if (i == num_cmds - 1)
			dup2(fd_pipe[i - 1][0], groups->fd_in);
		else
		{
			dup2(fd_pipe[i - 1][0], groups->fd_in);
			dup2(fd_pipe[i][1], groups->fd_out);
		}
		close_fds(fd_pipe, num_cmds);
		do_cmd(groups, data);
	}
}

void	kill_process(t_groups *groups)
{
	while (groups && groups->pid != -1)
	{
		kill (groups->pid, SIGKILL);
		waitpid(groups->pid, 0, 0);
		groups = groups->next;
	}
}

void	helper_f_err(t_data *data, t_groups *cur)
{
	kill_process(cur);
	perror("❌ fork failed");
	data->error_status = 1;
	data->fork_res = -1;
}

void	last_command(int (*fd_pipe)[2], int i)
{
	perror("pipe");
	close_fds(fd_pipe, i + 1);
}

void	forking(t_groups *groups, int num_cmds, int (*fd_pipe)[2], t_data *data)
{
	int			i;
	t_groups	*cur;

	cur = groups;
	i = -1;
	while (++i < num_cmds -1)
	{
		if (pipe(fd_pipe[i]) == -1)
			last_command(fd_pipe, i);
	}
	i = -1;
	while (++i < num_cmds)
	{
		data->fork_res = 0;
		groups->pid = fork();
		if (groups->pid == -1)
		{
			helper_f_err(data, cur);
			break ;
		}
		else if (groups->pid == 0)
			multipipe(i, num_cmds, groups, fd_pipe, data);
		groups = groups->next;
	}
}
