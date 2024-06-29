/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aremkrtc <aremkrtc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 12:01:45 by aremkrtc          #+#    #+#             */
/*   Updated: 2023/03/30 12:15:26 by aremkrtc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	increment_shell_level(t_env *env)
{
	int		shell_level;
	char	*shlvl;
	char	*shell_lvl_value;

	shell_lvl_value = ft_gval(env, "SHLVL");
	if (!shell_lvl_value)
		return ;
	shell_level = ft_atoi(shell_lvl_value) + 1;
	free(shell_lvl_value);
	while (env && env->next)
	{
		if (ft_strcmp("SHLVL", env->key) == 0)
		{
			shlvl = ft_itoa(shell_level);
			env->value = shlvl;
			return ;
		}
		env = env->next;
	}
}

void	do_cmd(t_groups *groups, t_data *data)
{
	char	*tmp;

	data->path = ft_gval(data->env_list, "PATH");
	if (data->path)
		data->cmd_paths = ft_split(data->path, ':');
	if (is_builtin(groups->args[0]))
		data->error_status = execute(groups, data);
	else
	{
		if (execve(get_path(data->cmd_paths, data, groups), \
		groups->args, data->envp) == -1)
		{	
			data->error_status = 127;
			ft_set_env_node(data->env_list, "?", "127", ENV);
			perror("execve");
			exit(127);
		}
	}
	tmp = ft_itoa(data->error_status);
	ft_set_env_node(data->env_list, "?", tmp, ENV);
	free(tmp);
}
