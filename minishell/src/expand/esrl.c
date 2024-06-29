/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   esrl.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aremkrtc <aremkrtc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 03:43:13 by aremkrtc          #+#    #+#             */
/*   Updated: 2023/03/30 03:52:25 by aremkrtc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	esrl(t_data *data, char *expand_str, int i, int real_len)
{
	char	*variable_name;
	char	*variable_value;

	data->esrl_len = 0;
	if (!ft_is_dollar(expand_str[i]))
		return ;
	data->esrl_len = get_expand_string_len(expand_str, i);
	if (ft_strlen(expand_str) == 1 && expand_str[0] == '$')
		real_len = 1;
	else
	{
		variable_name = ft_substr(expand_str, i + 1, data->esrl_len - 1);
		variable_value = expand_string_with_variable(data, variable_name);
		free (variable_name);
		if (variable_value != NULL)
		{
			real_len += ft_strlen(variable_value);
			i += data->esrl_len;
			free(variable_value);
			return ;
		}
		real_len += data->esrl_len;
		i = i + data->esrl_len;
	}
}

int	expanding_str_real_len(t_data *data, char *expand_str)
{
	int		i;
	int		len1;
	int		real_len;

	i = 0;
	real_len = 0;
	len1 = ft_strlen(expand_str);
	while (expand_str[i] != '\0')
	{
		while (expand_str[i] != '\0' && !ft_is_dollar(expand_str[i]))
		{
			real_len++;
			i++;
		}
		esrl(data, expand_str, i, real_len);
		if (i > len1)
			break ;
	}
	return (real_len);
}
