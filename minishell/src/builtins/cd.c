/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aremkrtc <aremkrtc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 17:10:18 by aremkrtc          #+#    #+#             */
/*   Updated: 2023/03/30 04:09:27 by aremkrtc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	print_error(char **args)
{
	ft_putstr_fd("cd: ", 2);
	ft_putstr_fd(args[1], 2);
	ft_putstr_fd(": ", 2);
	ft_putendl_fd(strerror(errno), 2);
}

int	is_in_env2(t_env *env, char *args)
{
	while (env != NULL)
	{
		if (env->key == args)
			return (1);
		env = env->next;
	}
	return (0);
}

int	update_oldpwd(t_env *env)
{
	char	cwd[PATH_MAX];

	if (getcwd(cwd, PATH_MAX) == NULL)
		return (1);
	if (ft_gval(env, "OLDPWD"))
	{
		ft_set_env_node(env, "OLDPWD", cwd, ENV);
	}
	return (0);
}

int	gtp(char *env_path, t_env *env)
{
	int	ret;

	ret = chdir(env_path);
	if (!ret)
		ft_set_env_node(env, "PWD", env_path, ENV);
	return (ret);
}

int	go_to_path(int option, t_env *env)
{
	char	*env_path;

	env_path = NULL;
	if (option == 0)
	{
		update_oldpwd(env);
		env_path = ft_gval(env, "HOME");
		if (!env_path)
		{
			ft_putendl_fd("minishell : cd: HOME not set\n", 2);
			return (1);
		}
	}
	else if (option == 1)
	{
		env_path = ft_gval(env, "OLDPWD");
		if (!env_path)
		{
			ft_putendl_fd("minishell : cd: OLDPWD not set\n", 2);
			return (1);
		}
		update_oldpwd(env);
	}
	return (gtp(env_path, env));
}
