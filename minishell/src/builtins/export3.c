/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aremkrtc <aremkrtc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 00:57:44 by aremkrtc          #+#    #+#             */
/*   Updated: 2023/03/29 00:57:58 by aremkrtc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	export(char **command, t_env *env, t_data *data)
{
	int	i;

	i = 0;
	if (command && !command[++i])
	{
		print_sorted_env(env);
		return (0);
	}
	else
	{
		return (export_value(command, env, data));
	}
}
