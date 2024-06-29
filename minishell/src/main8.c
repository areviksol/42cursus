/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main8.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aremkrtc <aremkrtc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 12:18:52 by aremkrtc          #+#    #+#             */
/*   Updated: 2023/03/30 03:00:56 by aremkrtc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	sig_wait(t_groups *tmp, t_data *data)
{
	char	*i;

	while (tmp)
	{
		waitpid(tmp->pid, &data->error_status, 0);
		tmp = tmp->next;
	}
	if (data->fork_res == -1)
		return ;
	else if (WIFEXITED(data->error_status))
		data->error_status = WEXITSTATUS(data->error_status);
	else if (WIFSIGNALED(data->error_status))
	{
		data->error_status = WTERMSIG(data->error_status) + 128;
		if (WTERMSIG(data->error_status) == SIGQUIT)
			ft_putstr_fd("Quit: 3\n", 2);
		if (WTERMSIG(data->error_status) == SIGINT)
			write(1, "\n", 1);
	}
	i = ft_itoa(data->error_status);
	ft_set_env_node(data->env_list, "?", i, ENV);
	free(i);
}

void	execute_pipeline(t_groups *groups, t_data *data)
{
	int		num_cmds;
	int		(*fd_pipe)[2];

	num_cmds = ft_lstsize(groups);
	groups->fds = -1;
	fd_pipe = malloc(sizeof (*fd_pipe) * (num_cmds - 1));
	if (fd_pipe == NULL)
		exit (1);
	forking(groups, num_cmds, fd_pipe, data);
	close_fds(fd_pipe, num_cmds);
	signal(SIGINT, SIG_IGN);
	sig_wait(groups, data);
	hook_signals();
}
