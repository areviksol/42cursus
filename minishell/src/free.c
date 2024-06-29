/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aremkrtc <aremkrtc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 16:40:24 by aremkrtc          #+#    #+#             */
/*   Updated: 2023/03/30 11:27:00 by aremkrtc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	free_arr(char **arr)
{
	if (*arr)
	{
		free(*arr);
		*arr = NULL;
	}
	return (0);
}

void	free_ptr_arr(char **arr)
{
	int	i;

	i = 0;
	if (!arr)
		return ;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	free_char_array_1(char **arr)
{
	int	count;
	int	i;

	count = 0;
	while (arr && arr[count] != NULL)
		count++;
	i = 0;
	while (i < count)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	free_groups(t_groups *group)
{
	t_groups	*next;

	while (group != NULL)
	{
		next = group->next;
		if (group->args != NULL)
			free_ptr_arr(group->args);
		free(group);
		group = next;
	}
}

void	free_token_list(t_token *token_list)
{
	t_token	*curr;

	while (token_list != NULL)
	{
		curr = token_list;
		token_list = token_list->next;
		if (curr->value)
			free(curr->value);
		if (curr)
			free(curr);
	}
}
