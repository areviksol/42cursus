/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aremkrtc <aremkrtc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 12:39:35 by aremkrtc          #+#    #+#             */
/*   Updated: 2023/03/30 03:43:01 by aremkrtc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_expand_string_len(char *token_value, int i)
{
	int		len;
	int		begin;
	char	c;

	begin = i;
	len = 0;
	if (token_value[i] == '$')
	{
		c = token_value[i];
		begin++;
		i++;
		len++;
		while (token_value[i] && token_value[i] != c && \
			!ft_is_space(token_value[i]) && token_value[i] != '/' \
			&& token_value[i] != '?')
		{
			i++;
			len++;
		}
		esl(token_value, i, len, c);
	}
	return (len);
}

int	is_a_valid_name(char c, int cond)
{
	if (cond)
		return ((ft_isalpha(c) || c == '_') && c != '$'
			&& c != '\'' && c != '"' && !ft_isspace(c));
	return ((ft_isalnum(c) || c == '_')
		&& c != '$' && c != '\'' && c != '"' && !ft_isspace(c) && c != '?');
}

int	ft_is_dollar(char c)
{
	return (c == '$');
}

int	get_expand_string_len(char *str, int i)
{
	int	len;

	len = 1;
	while (str[i + len] != '\0' && \
	!ft_isspace(str[i + len]) && str[i + len] != '$')
		len++;
	return (len);
}

char	*expand_string_with_variable(t_data *data, char *variable_name)
{
	char	*variable_value;

	variable_value = ft_gval(data->env_list, variable_name);
	if (variable_value == NULL)
		return (NULL);
	return (ft_strdup(variable_value));
}
