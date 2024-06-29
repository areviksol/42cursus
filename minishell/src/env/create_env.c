/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aremkrtc <aremkrtc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 18:57:16 by aremkrtc          #+#    #+#             */
/*   Updated: 2023/03/30 18:57:19 by aremkrtc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_create_env_list(t_env **env_list, char **envp)
{
	int		i;
	int		j;
	char	*current_key;
	char	*current_value;

	current_key = NULL;
	current_value = NULL;
	i = 0;
	*env_list = NULL;
	while (envp[i])
	{
		j = 0;
		while (envp[i][j] && envp[i][j] != '=')
			j++;
		current_key = ft_substr(envp[i], 0, j);
		j++;
		if (envp[i][j])
			current_value = ft_substr(envp[i], j, ft_strlen(envp[i]) - j);
		*env_list = ft_add_env_back(*env_list, current_key, current_value, ENV);
		free(current_key);
		free(current_value);
		current_key = NULL;
		current_value = NULL;
		i++;
	}
}
