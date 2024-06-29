/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fix_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aremkrtc <aremkrtc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 16:20:46 by aremkrtc          #+#    #+#             */
/*   Updated: 2023/03/22 16:21:17 by aremkrtc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	command_len(char *command)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (command[i])
	{
		if (command[i] != '\'' && command[i] != '\"')
			len++;
		i++;
	}
	return (len);
}

char	*fix_command(char *command)
{
	int		i;
	int		j;
	int		len;
	char	*fixed_command;

	i = 0;
	j = 0;
	len = command_len(command);
	fixed_command = (char *)malloc((len + 1) * sizeof(char));
	if (fixed_command)
		return (NULL);
	while (command[i])
	{
		if (command[i] != '\'' && command[i] != '\"')
		{
			fixed_command[j] = command[i];
			j++;
		}
		i++;
	}
	return (fixed_command);
}
