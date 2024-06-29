/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aremkrtc <aremkrtc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 17:07:51 by aremkrtc          #+#    #+#             */
/*   Updated: 2023/03/29 14:34:11 by aremkrtc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_delete_env_node(t_env *env_list, char *key)
{
	t_env	*temp;
	t_env	*prev;

	temp = env_list;
	while (temp != NULL && ft_strcmp(temp->key, key))
	{
		prev = temp;
		temp = temp->next;
	}
	if (temp == NULL)
		return ;
	prev->next = temp->next;
	free(temp->key);
	free(temp->value);
	free(temp);
}

void	ft_set_env_node(t_env *env_list, char *key, char *new_value, int flag)
{
	t_env	*current;

	current = env_list;
	while (current != NULL && ft_strcmp(current->key, key))
		current = current->next;
	if (current && key)
	{
		if (new_value)
		{
			free(current->value);
			current->value = ft_strdup(new_value);
		}
		current->flag = flag;
	}
	else if (!current)
		env_list = ft_add_env_back(env_list, key, new_value, flag);
}
