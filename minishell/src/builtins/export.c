/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aremkrtc <aremkrtc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 18:24:35 by aremkrtc          #+#    #+#             */
/*   Updated: 2023/03/30 19:05:09 by aremkrtc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ps_env_1(t_env	*env_duplicate)
{
	if (env_duplicate->value)
	{
		ft_putstr_fd("\"", 1);
		ft_putstr_fd(env_duplicate->value, 1);
		ft_putstr_fd("\"", 1);
	}
}

void	ps_env_2(t_env	*env_duplicate)
{
	t_env	*temp;
	char	*temp_key;
	char	*temp_value;

	temp = NULL;
	while (env_duplicate != NULL)
	{
		temp = env_duplicate;
		while (temp->next != NULL)
		{
			if (ft_strcmp(temp->key, temp->next->key) > 0)
			{
				temp_key = temp->key;
				temp_value = temp->value;
				temp->key = temp->next->key;
				temp->value = temp->next->value;
				temp->next->key = temp_key;
				temp->next->value = temp_value;
			}
			temp = temp->next;
		}
		env_duplicate = env_duplicate->next;
	}	
}

void	print_sorted_env(t_env *env)
{
	t_env	*env_duplicate;
	t_env	*head;

	env_duplicate = env;
	head = env_duplicate;
	ps_env_2(env_duplicate);
	env_duplicate = head;
	while (env_duplicate)
	{
		if (ft_strcmp(env_duplicate->key, "?"))
		{			
			ft_putstr_fd("declare -x ", 1);
			ft_putstr_fd(env_duplicate->key, 1);
			if (env_duplicate->value)
				ft_putstr_fd("=", 1);
			if (env_duplicate->value && env_duplicate->value[0] == '\0')
				ft_putstr_fd("\"\"", 1);
			else
				ps_env_1(env_duplicate);
			write(1, "\n", 1);
		}
		env_duplicate = env_duplicate->next;
	}
}

int	is_valid_args(char *args, t_data *data)
{
	int		pop;
	int		flag;

	data->f = 0;
	pop = last_char(args, '=');
	flag = 0;
	data->i = 0;
	if (pop != -1 && pop != 0 && args[pop - 1] == '+')
		flag = 1;
	while ((args[data->i] && args[data->i] != '='))
	{
		if (data->i == pop - 1 && flag == 1)
			(data->i)++;
		if (args[data->i] == '=')
			break ;
		if ((!ft_isalnum(args[data->i]) && args[data->i] != '_') || \
		(ft_is_digit(args[data->i]) && data->i == 0))
		{
			ft_print_error(data, "not a valid identifier");
			data->f = 1;
		}
		(data->i)++;
	}
	return (data->f);
}

int	last_char(char *str, char c)
{
	int	i;
	int	d;

	i = 0;
	d = -1;
	if (!str)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (d);
}
