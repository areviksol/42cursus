/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grouping2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aremkrtc <aremkrtc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 14:58:52 by aremkrtc          #+#    #+#             */
/*   Updated: 2023/03/30 19:01:11 by aremkrtc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static char	*f(char *res, int iter_j, char *expand_str)
{
	res[iter_j] = '\0';
	free(expand_str);
	return (res);
}

void	dosomethinggreat_hdoc(char *expand_str, t_ij *iter, \
		char *res, t_data *data)
{
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
	if (expand_str[iter->i] != '\0' && expand_str[iter->i] != '$')
		res[iter->j++] = expand_str[iter->i++];
}

char	*expanding_str_hdoc(t_data *data, char *expand_str)
{
	t_ij	iter;
	char	*res;
	char	*tmp;

	iter.i = 0;
	iter.j = 0;
	if (ft_gval(data->env_list, "?"))
		expand_str = rep_s(expand_str, "$?", ft_gval(data->env_list, "?"));
	else
	{
		tmp = ft_itoa(data->error_status);
		expand_str = rep_s(expand_str, "$?", tmp);
		ft_set_env_node(data->env_list, "?", expand_str, ENV);
		free(tmp);
	}
	if (final_len(expand_str, data) == 0)
		return (free(expand_str), NULL);
	res = ft_calloc(sizeof(*res), (final_len(expand_str, data) + 1));
	if (!res)
		return (NULL);
	while (expand_str[iter.i])
		dosomethinggreat_hdoc(expand_str, &iter, res, data);
	return (f(res, iter.j, expand_str));
}

int	ajsdghhj(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '"' || s[i] == '\'')
			return (0);
		++i;
	}
	return (1);
}

void	h_h(t_data *data, char	*read_, char *delim)
{
	char	*tmp;

	if (ajsdghhj(delim))
	{
		tmp = read_;
		read_ = expanding_str_hdoc(data, read_);
		free(tmp);
	}
	write(data->groups->fd_in, read_, ft_strlen(read_));
	write(data->groups->fd_in, "\n", 1);
	free(read_);
}
