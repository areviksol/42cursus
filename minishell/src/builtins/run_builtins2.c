/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_builtins2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aremkrtc <aremkrtc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 18:57:07 by aremkrtc          #+#    #+#             */
/*   Updated: 2023/03/30 18:57:08 by aremkrtc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	cmd_errors(t_data *data, t_groups *tmp)
{
	if (*tmp->args[0] == 0)
		not_found(tmp, data);
	else if (tmp->args[0][0] == '.' && !tmp->args[0][1])
		cmd_errors_1(data, tmp);
	else if (opendir(*tmp->args) && ft_strchr(*(tmp->args), '/'))
		is_dir(tmp, data);
	else if (tmp->args[0][0] == '/' || (tmp->args[0][1] == '.' \
		&& tmp->args[0][1] == '/') || (tmp->args[0][0] == '.' \
		&& tmp->args[0][1] == '/') || (tmp->args[0][0] == '.' \
		&& tmp->args[0][1] == '.' && tmp->args[0][2] == '/')
		|| (!data->path && !ft_strchr(*tmp->args, '/')))
	{
		cmd_errors_2(data, tmp);
		data->path = ft_strdup(*tmp->args);
		return (1);
	}
	else if (tmp->args[0][0] == '.')
		not_found(tmp, data);
	else
	{
		check_path(data, tmp, data->path, data->cmd_paths);
		return (1);
	}
	return (0);
}

void	execute_builtin(t_groups *group, t_data *data)
{
	char	*tmp;
	int		i;

	data->path = ft_gval(data->env_list, "PATH");
	if (data->path)
		data->cmd_paths = ft_split(data->path, ':');
	if (is_builtin(group->args[0]))
		ft_builtin(group, data);
	else
		ft_exec(group, data);
	ft_set_env_node(data->env_list, "?", \
	tmp = ft_itoa(data->error_status % 255), ENV);
	free_ptr_arr(data->envp);
	data->envp = env_from_list(data->env_list);
	free(tmp);
	i = -1;
	if (data->cmd_paths)
		while (data->cmd_paths[++i])
			free(data->cmd_paths[i]);
	free(data->cmd_paths);
	data->cmd_paths = NULL;
}

int	execute(t_groups *group, t_data *data)
{
	if (is_builtin(group->args[0]))
		ft_builtin(group, data);
	wait(NULL);
	exit(data->error_status);
}
