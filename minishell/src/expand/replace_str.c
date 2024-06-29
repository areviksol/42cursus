/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aremkrtc <aremkrtc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 02:54:48 by aremkrtc          #+#    #+#             */
/*   Updated: 2023/03/30 02:56:01 by aremkrtc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*rep_s(char *main_str, char *old_str, char *new_str)
{
	t_expand	*ex;
	char		*str;

	ex = malloc(sizeof(t_expand));
	if (!r_str_init(ex, main_str, old_str, new_str))
		return (frre_r(ex), free(ex), NULL);
	ft_strcpy(ex->result_str, main_str);
	while (ex->i++ <= ex->main_len - ex->old_len)
	{
		if (ft_strncmp(&ex->result_str[ex->i], old_str, ex->old_len) == 0)
		{
			if (ft_strcmp(old_str, new_str) == 0)
			{
				ex->i += ex->old_len - 1;
				continue ;
			}
			ex->temp_str = malloc(ex->main_len + ex->new_len - ex->old_len + 1);
			if (!ex->temp_str)
				return (free_ex(ex), NULL);
			r_str(ex, new_str);
		}
	}
	str = ex->result_str;
	return (free(ex), str);
}

void	frre_r(t_expand	*ex)
{
	free(ex->result_str);
	free(ex);
}
