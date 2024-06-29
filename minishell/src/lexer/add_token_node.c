/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_token_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aremkrtc <aremkrtc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 16:26:20 by aremkrtc          #+#    #+#             */
/*   Updated: 2023/03/22 16:26:53 by aremkrtc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_token	*ft_add_new_token(char *str, int type)
{
	t_token	*node;

	node = NULL;
	if (!str)
		return (NULL);
	node = malloc(sizeof(t_token));
	if (!node)
		exit(1);
	node->value = str;
	node->type = type;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

t_token	*ft_add_token_back(t_token *token, char *str, int type)
{
	t_token	*node;
	t_token	*token_duplicate;

	if (!str)
		return (NULL);
	node = ft_add_new_token(str, type);
	if (!node)
		exit(1);
	if (token == NULL)
		return (node);
	token_duplicate = token;
	while (token_duplicate->next != NULL)
		token_duplicate = token_duplicate->next;
	token_duplicate->next = node;
	node->next = NULL;
	node->prev = token_duplicate;
	return (token);
}
