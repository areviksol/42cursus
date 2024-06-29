/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aremkrtc <aremkrtc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 17:05:55 by aremkrtc          #+#    #+#             */
/*   Updated: 2023/03/30 02:24:19 by aremkrtc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	check_errors(t_data *data, t_token *token_list)
{
	while (token_list)
	{
		if (token_list->type == RD_IN || token_list->type == RD_OUT \
		|| token_list->type == RD_APPEND || token_list->type == \
		RD_INSOURCE || token_list->type == PIPE)
		{
			if (!token_list->next)
			{
				ft_set_env_node(data->env_list, "?", "258", ENV);
				return (ft_print_error(data, "Invalid command\n"));
			}
		}
		token_list = token_list->next;
	}
	return (0);
}
