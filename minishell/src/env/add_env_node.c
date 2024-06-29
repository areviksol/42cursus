/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_env_node.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aremkrtc <aremkrtc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 17:07:22 by aremkrtc          #+#    #+#             */
/*   Updated: 2023/03/29 14:19:21 by aremkrtc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_env	*ft_add_new_env(char *key, char *value, int flag)
{
	t_env	*node;

	node = malloc(sizeof(t_env));
	if (!node)
		return (NULL);
	node->key = strdup(key);
	if (value)
		node->value = strdup(value);
	else
		node->value = NULL;
	node->flag = flag;
	node->next = NULL;
	return (node);
}

t_env	*ft_add_env_back(t_env *env_list, char *key, char *value, int flag)
{
	t_env	*node;
	t_env	*env_list_duplicate;

	if (!key)
		return (NULL);
	node = ft_add_new_env(key, value, flag);
	if (!node)
		exit(1);
	env_list_duplicate = env_list;
	if (env_list == NULL)
		return (node);
	while (env_list_duplicate->next != NULL)
		env_list_duplicate = env_list_duplicate->next;
	env_list_duplicate->next = node;
	return (env_list);
}
