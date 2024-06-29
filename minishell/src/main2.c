/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aremkrtc <aremkrtc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 11:53:39 by aremkrtc          #+#    #+#             */
/*   Updated: 2023/03/30 22:24:17 by aremkrtc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	env_init(t_data *mini, char **env_array)
{
	t_env	*env;
	t_env	*new;
	int		i;

	new = NULL;
	env = NULL;
	if (!(env == malloc(sizeof(t_env))))
		return (1);
	env->value = ft_strdup(env_array[0]);
	env->next = NULL;
	mini->env_list = env;
	i = 1;
	while (env_array && env_array[0] && env_array[i])
	{
		if (!(new == malloc(sizeof(t_env))))
			return (1);
		new->key = ft_split(env_array[i], '=')[0];
		new->value = ft_split(env_array[i], '=')[1];
		new->next = NULL;
		env->next = new;
		env = new;
		i++;
	}
	return (0);
}

int	help(char **envp_array, int i)
{
	if (!envp_array[i])
	{
		while (i > 0)
			free(envp_array[--i]);
		return (1);
	}
	return (0);
}

char	**env_f_l(t_env *envp, int count)
{
	int		i;
	int		length;
	t_env	*env;
	char	*tmp1;
	char	**envp_array;

	i = 0;
	length = 0;
	envp_array = (char **)malloc((count + 1) * sizeof(char *));
	envp_array[count] = NULL;
	env = envp;
	while (env != NULL)
	{
		if (env->value)
			length = ft_strlen(env->key) + ft_strlen(env->value) + 2;
		else
			length = ft_strlen(env->key) + 2;
		tmp1 = ft_strjoin(env->key, "=");
		envp_array[i] = ft_strjoin(tmp1, env->value);
		free(tmp1);
		env = env->next;
		i++;
	}
	return (envp_array);
}

char	**env_from_list(t_env *envp)
{
	int		count;
	t_env	*env;

	env = envp;
	count = 0;
	while (env != NULL)
	{
		env = env->next;
		count++;
	}
	return (env_f_l(envp, count));
}

int	close_fds(int (*fds)[2], int psize)
{
	int	i;

	i = -1;
	while (++i < psize - 1)
	{
		close(fds[i][1]);
		close(fds[i][0]);
	}
	free(fds);
	return (0);
}
