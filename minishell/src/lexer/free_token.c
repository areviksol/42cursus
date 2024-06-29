/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_token.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aremkrtc <aremkrtc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 17:39:21 by aremkrtc          #+#    #+#             */
/*   Updated: 2023/03/22 17:39:27 by aremkrtc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	free_data(t_data *data)
{
	t_token	*token;

	token = data->token_list;
	while (data->token_list)
	{
		token = data->token_list->next;
		free(data->token_list->value);
		free(data->token_list);
		data->token_list = token;
	}
	data->token_list = NULL;
	free(data->command);
}
