/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_group.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aremkrtc <aremkrtc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 16:21:24 by aremkrtc          #+#    #+#             */
/*   Updated: 2023/03/22 16:21:34 by aremkrtc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	free_group(t_data *data)
{
	int			i;
	t_groups	*group;

	i = 0;
	group = data->groups;
	while (data->groups)
	{
		group = data->groups->next;
		while (data->groups->args[i])
		{
			free(data->groups->args[i]);
			i++;
		}
		free(data->groups->args);
		data->groups = group;
	}
	data->groups = NULL;
}
