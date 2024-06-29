/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main7.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aremkrtc <aremkrtc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 12:15:07 by aremkrtc          #+#    #+#             */
/*   Updated: 2023/03/29 14:45:46 by aremkrtc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_tenv(t_env *env)
{
	while (env != NULL)
	{	
		if (env->key)
			free(env->key);
		if (env->value)
			free(env->value);
		env = env->next;
	}
}
