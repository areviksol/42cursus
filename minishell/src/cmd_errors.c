/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_errors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aremkrtc <aremkrtc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 18:56:42 by aremkrtc          #+#    #+#             */
/*   Updated: 2023/03/30 18:56:43 by aremkrtc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	no_access(char *cmd, t_data *data)
{
	if (ft_strchr(cmd, '.'))
	{
		ft_putstr_fd_1(ft_strjoin_2("Minishell$ ", \
		ft_strjoin(cmd, NO_PERM)), 2, FREE_ON);
		data->error_status = 126;
	}
	else if (ft_strchr(cmd, '/'))
	{
		ft_putstr_fd_1(ft_strjoin_2("Minishell$ ", \
		ft_strjoin(cmd, NO_DIR)), 2, FREE_ON);
		data->error_status = 127;
	}
	else
	{
		ft_putstr_fd_1(ft_strjoin_2("Minishell$ ", \
		ft_strjoin(cmd, NOT_FOUND)), 2, FREE_ON);
		data->error_status = 127;
	}
}

int	cmd_errors_2(t_data *data, t_groups *tmp)
{
	if (access(*tmp->args, F_OK) != 0)
		no_dir(tmp, data);
	else if (access(*tmp->args, X_OK) != 0)
		no_perm(tmp, data);
	data->path = *tmp->args;
	return (1);
}

void	cmd_errors_1(t_data *data, t_groups *tmp)
{
	ft_putstr_fd_1(ft_strjoin(*tmp->args, FAR), 2, FREE_ON);
	ft_putstr_fd_1(ft_strjoin(*tmp->args, USAGE), 2, FREE_ON);
	data->error_status = 2;
}

char	*get_cmd(char **paths, char *cmd)
{
	char	*tmp;
	char	*command;

	tmp = 0;
	while (*paths)
	{
		tmp = ft_strjoin(*paths, "/");
		command = ft_strjoin(tmp, cmd);
		if (access(command, X_OK) == 0)
			return (command);
		paths++;
	}
	return (NULL);
}

void	check_path(t_data *data, t_groups *tmp, char *path, char **cmd_paths)
{
	if (ft_strchr(*tmp->args, '/') && access(*tmp->args, X_OK) == 0)
		path = *tmp->args;
	else if (path)
	{
		path = get_cmd(cmd_paths, *tmp->args);
		if (path == NULL)
			if (!(access(*tmp->args, X_OK) == 0))
				no_access(*tmp->args, data);
	}
	else if (access(*tmp->args, X_OK) != 0)
		not_found(tmp, data);
	else
		no_dir(tmp, data);
}
