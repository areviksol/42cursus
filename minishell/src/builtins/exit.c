/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aremkrtc <aremkrtc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 18:57:00 by aremkrtc          #+#    #+#             */
/*   Updated: 2023/03/30 18:57:01 by aremkrtc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	str_is_valid_num_helper(int i, int j, char *tmp, int flag)
{
	if ((i - j) > 19)
		return (1);
	if ((i - j) < 19)
		return (0);
	if (flag == 1 || flag == 0)
		if (ft_strcmp(tmp + j, L_MAX) > 0)
			return (1);
	if (flag == -1)
		if (ft_strcmp(tmp + j, L_MIN) > 0)
			return (1);
	return (0);
}

int	str_is_valid_num(char *str)
{
	int		i;
	int		j;
	int		flag;
	char	*tmp;

	i = 0;
	flag = 0;
	tmp = ft_strtrim_1(str, SPACES);
	if ((((tmp[i] == '+' && ++flag) || (tmp[i] == '-' && --flag))
			&& ++i) || tmp[i])
		while (tmp[i] && tmp[i + 1] && tmp[i] == '0')
			i++;
	j = i;
	if (str && tmp[i] == '\0' && !free_arr(&tmp))
		return (1);
	while (tmp[i])
	{
		if (!ft_isdigit_1(tmp[i]) && !free_arr(&tmp))
			return (1);
		i++;
	}
	if ((str_is_valid_num_helper(i, j, tmp, flag) != 0 && !free_arr(&tmp)))
		return (1);
	return (free_arr(&tmp));
}

int	ex(t_groups *cur)
{
	if (ft_lstsize(cur) == 1)
		ft_putstr_fd_1("exit\n", cur->fd_out, FREE_OFF);
	return (1);
}

void	ft_exit(t_data *data, char **args, t_groups *cur)
{
	if (!args[1] && ft_lstsize(cur) > 1)
		exit (0);
	else if (!args[1] && ex(cur))
		data->error_status = ft_atoi(ft_gval(data->env_list, "?"));
	else if (args[1] && str_is_valid_num(args[1]))
	{
		ex(cur);
		ft_putstr_fd_1("Minishell$ : exit: ", 2, FREE_OFF);
		ft_putstr_fd_1(args[1], 2, FREE_OFF);
		ft_putstr_fd_1(": numeric argument required\n", 2, FREE_OFF);
		data->error_status = 255;
	}
	else if (args && args[1] && args[2])
	{
		ex(cur);
		ft_putstr_fd_1(EXIT_ARG, 2, FREE_OFF);
		data->error_status = 1;
		return ;
	}
	else if (ex(cur))
		data->error_status = ft_atoi(args[1]);
	exit(data->error_status);
}
