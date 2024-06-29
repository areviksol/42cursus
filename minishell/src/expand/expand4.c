/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aremkrtc <aremkrtc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 12:42:51 by aremkrtc          #+#    #+#             */
/*   Updated: 2023/03/30 16:35:48 by aremkrtc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*f(char *res, int iter_j, char *expand_str)
{
	res[iter_j] = '\0';
	free(expand_str);
	return (res);
}

char	*expanding_str(t_data *data, char *expand_str)
{
	t_ij	iter;
	char	*res;
	char	*tmp;

	iter.i = 0;
	iter.j = 0;
	if (ft_strcmp (expand_str, "\"\"") == 0 || ft_strcmp (expand_str, "\'\'") == 0)
		return (ft_strdup(""));
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
		dosomethinggreat(expand_str, &iter, res, data);
	return (f(res, iter.j, expand_str));
}

int	ft_isalpha(int c)
{
	return ((c >= 65 && c <= 90)
		|| (c >= 97 && c <= 122));
}

void	strjoin_var(char *s1, char *s2)
{
	int		i;
	int		j;

	i = ft_strlen(s1);
	j = 0;
	while (s2 && s2[j])
	{
		s1[i] = s2[j];
		j++;
		i++;
	}
}

int	var_len(char *s, int i, int quote)
{
	int		len;

	len = 0;
	while (s[i] && is_a_valid_name(s[i], i > 0 && s[i - 1] == '$'))
	{
		if (quote && s[i] == '"')
			break ;
		i++;
		len++;
	}
	return (len);
}
