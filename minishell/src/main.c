/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aremkrtc <aremkrtc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 15:33:19 by aremkrtc          #+#    #+#             */
/*   Updated: 2023/03/30 19:47:47 by aremkrtc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	g_status;

void	ft_putendl_fd(char *s, int fd)
{
	int		i;
	char	c;

	c = '\n';
	if (s)
	{
		i = 0;
		while (s[i])
		{
			write(fd, &s[i], 1);
			i++;
		}
	}
	write(fd, &c, 1);
}

void	ft_skip_spacenl(char *str, int *i)
{
	while ((str[*i] == ' ' || str[*i] == '\t' || str[*i] == '\n') || (str[*i] \
	== '\r' || str[*i] == '\v' || str[*i] == '\f'))
		(*i)++;
}

char	*get_env_value(char *key, t_env *env)
{
	t_env	*cur;

	cur = env;
	while (cur)
	{
		if (cur->key == key)
			return (cur->key);
		cur = cur->next;
	}
	return (NULL);
}

void	main4(t_data *data)
{
	while (1)
	{
		main3(data);
		if (!ft_strcmp(data->command, ""))
		{
			free(data->command);
			continue ;
		}
		if (check_errors(data, data->token_list) || data->error_status == 1)
		{
			check_er_h(data);
			continue ;
		}
		if (data->token_list)
		{
			if (grouping(data))
			{
				free(data->command);
				continue ;
			}
			if (g_status_ma(data))
				continue ;
		}
		free(data->command);
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_data		data;
	int			ex;

	(void)argv;
	(void)argc;
	data.error_status = 0;
	g_status = 0;
	data.token_list = NULL;
	ft_create_env_list(&(data.env_list), envp);
	data.envp = env_from_list(data.env_list);
	increment_shell_level(data.env_list);
	ft_signal(0);
	main4(&data);
	ex = ft_atoi(ft_gval(data.env_list, "?"));
	free_ptr_arr(data.envp);
	free_tenv(data.env_list);
	exit(ex);
	return (0);
}
