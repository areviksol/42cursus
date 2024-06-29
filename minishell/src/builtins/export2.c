/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aremkrtc <aremkrtc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 00:56:45 by aremkrtc          #+#    #+#             */
/*   Updated: 2023/03/30 08:11:58 by aremkrtc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	e_v1(char **command, t_env *env)
{
	env->pop = last_char(command[env->i], '=');
	if (env->pop != -1 && env->pop != 0 && command[env->i][env->pop - 1] == '+')
		env->exflag = 1;
	if (env->pop != -1)
	{
		if (env->exflag == 1)
		{
			env->tmp0 = ft_substr(command[env->i], 0, env->pop - 1);
			env->tmp1 = ft_substr(command[env->i], env->pop + 1, \
			ft_strlen(command[1]) - env->pop - 1);
		}
		else
		{
			env->tmp0 = ft_substr(command[env->i], 0, env->pop);
			env->tmp1 = ft_substr(command[env->i], env->pop + 1, \
			ft_strlen(command[1]) - env->pop);
		}
	}
	else
		env->tmp0 = command[env->i];
}

void	e_v2_helper(t_env *env)
{
	if (env->pop != -1)
		ft_set_env_node(env, env->tmp0, env->tmp1, ENV);
	else
		ft_set_env_node(env, env->tmp0, NULL, EXPORT);
}

void	free_e(t_env *env)
{
	free(env->tmp0);
	free(env->tmp1);
}

void	e_v2(t_data *data, t_env *env)
{
	char	*a;

	a = NULL;
	if (env->exflag == 0)
		e_v2_helper(env);
	else
	{
		if (env->pop != -1)
		{
			env->tmp2 = ft_gval(data->env_list, env->tmp0);
			if (!env->tmp2)
				ft_set_env_node(env, env->tmp0, env->tmp1, ENV);
			else if (env->exflag == 1)
			{
				a = ft_strjoin(env->tmp2, env->tmp1);
				ft_set_env_node(env, env->tmp0, a, ENV);
				free(a);
			}
			else
				ft_set_env_node(env, env->tmp0, env->tmp1, ENV);
		}
		else
			ft_set_env_node(env, env->tmp0, NULL, EXPORT);
	}	
	free_e(env);
}

int	export_value(char **command, t_env *env, t_data *data)
{
	env->i = 1;
	env->exflag = 0;
	env->tmp0 = NULL;
	env->tmp1 = NULL;
	while (command && command[env->i])
	{
		if (is_valid_args(command[env->i], data) == 0)
		{
			e_v1(command, env);
			if (!env->tmp0 || env->tmp0[0] == '\0' || env->tmp0[0] == '=')
			{
				free_e(env);
				ft_print_error(data, "not a valid identifier\n");
				break ;
				return (1);
			}
			if (env->tmp1)
				e_v2(data, env);
			else
				ft_set_env_node(env, env->tmp0, NULL, EXPORT);
		}
		env->i++;
	}
	return (0);
}
