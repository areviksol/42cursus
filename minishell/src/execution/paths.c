/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aremkrtc <aremkrtc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 18:57:23 by aremkrtc          #+#    #+#             */
/*   Updated: 2023/03/30 18:57:24 by aremkrtc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	not_found(t_groups *tmp, t_data *data)
{
	ft_putstr_fd_1(ft_strjoin_2("Minishell$ ", \
	ft_strjoin(*tmp->args, NOT_FOUND)), 2, FREE_ON);
	data->error_status = 127;
}

void	is_dir(t_groups *tmp, t_data *data)
{
	ft_putstr_fd_1(ft_strjoin_2("Minishell$ ", \
	ft_strjoin(*tmp->args, IS_DIR)), 2, FREE_ON);
	data->error_status = 126;
}

void	no_dir(t_groups *tmp, t_data *data)
{
	ft_putstr_fd_1(ft_strjoin_2("Minishell$ ", \
	ft_strjoin(*tmp->args, NO_DIR)), 2, FREE_ON);
	data->error_status = 127;
}

void	no_perm(t_groups *tmp, t_data *data)
{
	ft_putstr_fd_1(ft_strjoin_2("Minishell$ ", \
	ft_strjoin(*tmp->args, NO_PERM)), 2, FREE_ON);
	data->error_status = 126;
}

char	*get_path(char **cmd_paths, t_data *data, t_groups *groups)
{
	char	**imputs;
	char	*tmp;
	char	*result;

	data->cmd_paths = cmd_paths;
	result = NULL;
	imputs = ft_split(groups->args[0], ' ');
	if (!imputs)
		return (NULL);
	while (*cmd_paths)
	{
		tmp = ft_strjoin(*cmd_paths, "/");
		result = ft_strjoin(tmp, imputs[0]);
		free(tmp);
		if (access(result, R_OK) == 0)
		{
			free_ptr_arr(imputs);
			return (result);
		}
		free(result);
		cmd_paths++;
	}
	free_ptr_arr(imputs);
	return (NULL);
}
