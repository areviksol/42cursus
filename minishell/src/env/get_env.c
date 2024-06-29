/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aremkrtc <aremkrtc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 17:08:32 by aremkrtc          #+#    #+#             */
/*   Updated: 2023/03/30 03:00:39 by aremkrtc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*trimstring(char *str)
{
	char	*end;

	while (isspace((unsigned char)*str))
		str++;
	if (*str == 0)
		return (str);
	end = str + ft_strlen(str) - 1;
	while (end > str && isspace((unsigned char)*end))
		end--;
	end[1] = '\0';
	return (str);
}

char	*ft_gval(t_env *env_list, char *key)
{
	t_env	*current;

	if (!key || key[0] == '$')
		return (NULL);
	current = env_list;
	while (current && ft_strcmp(current->key, key))
	{
		current = current->next;
	}
	if (!current)
		return (NULL);
	return (current->value);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*res;
	size_t	i;

	res = malloc(count * size);
	if (!res)
		return (NULL);
	i = 0;
	while (i < (count * size))
	{
		((char *)res)[i] = 0;
		i++;
	}
	return (res);
}

int	ft_isspace(char c)
{
	return (c == '\r' || c == '\t'
		|| c == '\v' || c == '\n'
		|| c == '\f' || c == ' ');
}
