/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aremkrtc <aremkrtc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 12:41:57 by aremkrtc          #+#    #+#             */
/*   Updated: 2023/03/30 02:55:30 by aremkrtc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	fl_1(char *s, t_data *data, int *i, int *len)
{
	if (s[*i] == '$')
	{
		if (var_len(s, *i + 1, 0) == 0)
			*len += 1;
		else
		{
			if (expanded_len(s, *i + 1, 0, data) < 0)
				return (-1);
			*len += expanded_len(s, *i + 1, 0, data);
		}
		*i += var_len(s, *i + 1, 0) + 1;
	}
	*len += (s[*i] != '\0' && s[*i] != '"' && s[*i] != '\'' && s[*i] != '$');
	*i += (s[*i] != '\0' && s[*i] != '"' && s[*i] != '\'' && s[*i] != '$');
	return (*len);
}

void	dosomething(char *expand_str, t_ij *iter, char *res, t_data *data)
{
	while (expand_str[++iter->i] && expand_str[iter->i] != '"')
	{
		if (expand_str[iter->i] == '$')
		{
			if (var_len(expand_str, iter->i + 1, 1) == 0)
				res[iter->j++] = '$';
			else
			{
				strjoin_var(res, \
				expanded_env(expand_str, iter->i + 1, 1, data));
				iter->j = ft_strlen(res);
			}
			iter->i += var_len(expand_str, iter->i + 1, 1);
		}
		else
			res[iter->j++] = expand_str[iter->i];
	}
	iter->i += (expand_str[iter->i] != '\0');
}

void	r_str(t_expand	*ex, const char *new_str)
{
	strncpy(ex->temp_str, ex->result_str, ex->i);
	strncpy(&ex->temp_str[ex->i], new_str, ex->new_len);
	strncpy(&ex->temp_str[ex->i + ex->new_len], \
		&ex->result_str[ex->i + ex->old_len], \
		ex->main_len - ex->i - ex->old_len);
	ex->temp_str[ex->main_len + ex->new_len - ex->old_len] = '\0';
	free (ex->result_str);
	ex->result_str = ex->temp_str;
	ex->main_len += ex->new_len - ex->old_len;
	ex->i += ex->new_len - 1;
}

int	r_str_init(t_expand	*ex, char *main_str, char *old_str, char *new_str)
{
	ex->main_len = ft_strlen(main_str);
	ex->old_len = ft_strlen(old_str);
	ex->new_len = ft_strlen(new_str);
	ex->result_str = malloc(ex->main_len + 1);
	ex->i = -1;
	if (!ex->result_str)
		return (0);
	return (1);
}
