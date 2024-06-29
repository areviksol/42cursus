/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_helper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aremkrtc <aremkrtc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 17:28:29 by aremkrtc          #+#    #+#             */
/*   Updated: 2023/03/23 14:26:53 by aremkrtc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	env_list_to_array(t_data *data)
{
	int	len;
	int	i;

	i = 0;
	len = ft_lstsize_env(data->env_list);
	if (data->envp)
		free(data->envp);
	data->envp = malloc(sizeof(char *) * (len + 1));
	if (!data->envp)
		return ;
	while (data->env_list)
	{
		data->envp[i] = strdup(data->env_list->value);
		i++;
		data->env_list = data->env_list->next;
	}
}
