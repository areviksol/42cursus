/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aremkrtc <aremkrtc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 18:57:11 by aremkrtc          #+#    #+#             */
/*   Updated: 2023/03/30 18:57:12 by aremkrtc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	is_valid_key(char *key)
{
	int	i;

	i = -1;
	if (key && *key && (*key == '_' || (*key >= 'a' && *key <= 'z') \
	|| (*key >= 'A' && *key <= 'Z')))
	{
		while (key && key[++i])
			if (!(key[i] == '_' || (key[i] >= 'a' && key[i] <= 'z') || \
				(key[i] >= 'A' && key[i] <= 'Z') || (key[i] >= '0' && \
				key[i] <= '9')))
				return (1);
	}
	else
		return (1);
	return (0);
}

int	unset(char **command, t_env *env)
{
	int	i;
	int	flag;

	flag = 0;
	i = 1;
	while (command && command[i])
	{
		if (is_valid_key(command[i]) == 0)
		{
			ft_delete_env_node(env, command[i]);
			i++;
		}
		else
		{
			flag = 1;
			ft_putstr_fd("invalid args\n", 2);
			i++;
		}
	}
	return (flag);
}
