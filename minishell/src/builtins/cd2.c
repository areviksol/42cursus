/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd2.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aremkrtc <aremkrtc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 00:54:50 by aremkrtc          #+#    #+#             */
/*   Updated: 2023/03/29 16:45:11 by aremkrtc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	cd_helper(t_env *env, int cd_ret)
{
	char	*tmp;

	tmp = ft_itoa(cd_ret);
	ft_set_env_node(env, "?", tmp, ENV);
	free(tmp);
}

int	cd(char **command, t_env *env)
{
	char	cwd[1024];
	int		cd_ret;

	if (command[1] == NULL)
		return (go_to_path(0, env));
	if (ft_strcmp(command[1], "-") == 0)
		cd_ret = go_to_path(1, env);
	else
	{
		update_oldpwd(env);
		cd_ret = chdir(command[1]);
		if (cd_ret < 0)
			cd_ret *= -1;
		if (cd_ret != 0)
			print_error(command);
		if (!cd_ret)
		{
			getcwd(cwd, 1024);
			ft_set_env_node(env, "PWD", cwd, ENV);
		}
	}
	return (cd_ret);
}
