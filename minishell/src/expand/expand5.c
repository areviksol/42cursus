/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand5.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aremkrtc <aremkrtc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 12:43:37 by aremkrtc          #+#    #+#             */
/*   Updated: 2023/03/29 22:57:28 by aremkrtc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	dosomethinggreat(char *expand_str, t_ij *iter, char *res, t_data *data)
{
	if (expand_str[iter->i] == '\'')
	{
		while (expand_str[++iter->i] && expand_str[iter->i] != '\'')
			res[iter->j++] = expand_str[iter->i];
		iter->i += (expand_str[iter->i] != '\0');
	}
	if (expand_str[iter->i] == '"')
		dosomething(expand_str, iter, res, data);
	if (expand_str[iter->i] == '$')
	{
		if (var_len(expand_str, iter->i + 1, 0) == 0)
			res[iter->j++] = '$';
		else
		{
			strjoin_var(res, expanded_env(expand_str, iter->i + 1, 0, data));
			iter->j = ft_strlen(res);
		}
		iter->i += var_len(expand_str, iter->i + 1, 0) + 1;
	}
	if (expand_str[iter->i] != '\0' && expand_str[iter->i] != '"' && \
	expand_str[iter->i] != '\'' && expand_str[iter->i] != '$')
		res[iter->j++] = expand_str[iter->i++];
}
