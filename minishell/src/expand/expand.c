/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aremkrtc <aremkrtc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 17:04:57 by aremkrtc          #+#    #+#             */
/*   Updated: 2023/03/30 04:00:33 by aremkrtc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	esl(char *token_value, int i, int len, char c)
{
	if (token_value[i])
	{	
		if (!token_value[i] || token_value[i] == c || \
			!ft_is_space(token_value[i]) || token_value[i] == '"')
		{
			i++;
			if (len == 1)
				len++;
		}
	}
}

int	fl_2(char *s, t_data *data, int i, int *len)
{
	int	quote;

	if (s[i] == '$')
	{
		quote = 0;
		if (s[i + 1] == '\"')
		{
			quote = 1;
			i++;
		}
		if (var_len(s, i + 1, quote) == 0)
			*len += 1;
		else
		{
			if (expanded_len(s, i + 1, quote, data) < 0)
				return (-1);
			*len += expanded_len(s, i + 1, quote, data);
		}
		i += var_len(s, i + 1, quote);
	}
	else
		(*len)++;
	return (*len);
}

int	final_len(char *s, t_data *data)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (s[i])
	{
		if (s[i] == '\'')
		{
			while (s[++i] && s[i] != '\'')
				len++;
			i += (s[i] != '\0');
		}
		if (s[i] == '"')
		{
			while (s[++i] && s[i] != '"')
				fl_2(s, data, i, &len);
			i += (s[i] != '\0');
		}
		fl_1(s, data, &i, &len);
	}
	return (len);
}

int	expanded_len(char *cmd, int i, int quote, t_data *data)
{
	int		j;
	char	*env;
	char	*var;

	j = 0;
	var = malloc(sizeof (*var) * (var_len(cmd, i, quote) + 1));
	if (!var)
		return (-1);
	while (cmd[i] && is_a_valid_name(cmd[i], i > 0 && cmd[i - 1] == '$'))
	{
		if (quote && cmd[i] == '"')
			break ;
		var[j++] = cmd[i++];
	}
	var[j] = '\0';
	env = ft_gval(data->env_list, var);
	if (!env)
	{
		free(var);
		return (0);
	}
	free(var);
	return (ft_strlen(env));
}

char	*expanded_env(char *cmd, int i, int quote, t_data *data)
{
	int		j;
	char	*env;
	char	*var;

	j = 0;
	var = malloc(sizeof (*var) * (var_len(cmd, i, quote) + 1));
	if (!var)
	{
		perror("expanded_env(): ");
		return (NULL);
	}
	while (cmd[i] && is_a_valid_name(cmd[i], i > 0 && cmd[i - 1] == '$'))
	{
		if (quote && cmd[i] == '"')
			break ;
		var[j++] = cmd[i++];
	}
	var[j] = '\0';
	env = ft_gval(data->env_list, var);
	free(var);
	return (env);
}
