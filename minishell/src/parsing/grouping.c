/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grouping.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aremkrtc <aremkrtc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 16:21:40 by aremkrtc          #+#    #+#             */
/*   Updated: 2023/03/30 20:29:30 by aremkrtc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	args_len(t_token *token_list)
{
	int	len;

	len = 0;
	while (token_list && token_list->type != PIPE)
	{
		if (token_list->type != RD_IN && token_list->type != RD_OUT \
		&& token_list->type != RD_APPEND \
		&& token_list->type != RD_INSOURCE)
			len++;
		else
			token_list = token_list->next;
		token_list = token_list->next;
	}
	return (len);
}

t_groups	*init_group(void)
{
	t_groups	*new;

	new = malloc(sizeof(t_groups));
	new->fd_in = STDIN_FILENO;
	new->fd_out = STDOUT_FILENO;
	new->exit_status = 0;
	new->next = NULL;
	return (new);
}

int	grouping_loop(t_data *data)
{
	int	i;

	i = 0;
	while (data->token_list && data->token_list->type != PIPE)
	{
		if (data->token_list->type != RD_IN && data->token_list->type != \
			RD_OUT && data->token_list->type != RD_APPEND && \
			data->token_list->type != RD_INSOURCE)
		{
			if (data->token_list->type == WORD || \
				data->token_list->type == EXP_FIELD)
					data->groups->args[i] = \
					expanding_str(data, data->token_list->value);
			else
					data->groups->args[i] = ft_strdup(data->token_list->value);
				i++;
		}
		else
			if (grouping_4(data) != 0)
				return (1);
		data->token_list = data->token_list->next;
	}
	data->groups->args[i] = NULL;
	return (0);
}

void	zzveli_25(t_data *data)
{
	if (data->token_list && data->token_list->next)
	{
		data->groups->next = init_group();
		data->groups = data->groups->next;
	}
	if (data->token_list)
		data->token_list = data->token_list->next;
}

int	grouping(t_data *data)
{
	t_groups	*group_duplicate;
	t_token		*a;

	a = data->token_list;
	data->groups = init_group();
	group_duplicate = data->groups;
	while (data->token_list)
	{
		data->arg_len = args_len(data->token_list);
		data->groups->args = malloc(sizeof(char *) * (data->arg_len + 1));
		if (!data->groups->args)
			return (1);
		if (grouping_loop(data) != 0)
			return (1);
		zzveli_25(data);
	}
	if (a)
		free_token_list(a);
	data->groups = group_duplicate;
	return (0);
}
