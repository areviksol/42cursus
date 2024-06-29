/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grouping3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aremkrtc <aremkrtc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 15:02:48 by aremkrtc          #+#    #+#             */
/*   Updated: 2023/03/30 15:33:10 by aremkrtc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	grouping_4(t_data *data)
{
	if (data->token_list->type == RD_IN)
		return (grouping_1(data));
	else if (data->token_list->type == RD_APPEND)
		return (grouping_2(data));
	else if (data->token_list->type == RD_OUT)
		return (grouping_3(data));
	else if (data->token_list->type == RD_INSOURCE)
		return (ft_herdoc(data, data->token_list->next->value));
	return (0);
}

void	heredoc_sig(int sig)
{
	(void)sig;
	ioctl(STDIN_FILENO, TIOCSTI, "\n");
	rl_replace_line("", 0);
	rl_on_new_line();
	g_status = 10;
}

void	inthandle(int sig)
{
	(void)sig;
	write(1, "\n", 1);
	rl_on_new_line();
	rl_redisplay();
}

void	ft_signal(int handle)
{
	handleterm(handle);
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, inthandle);
}

void	handleterm(int sig)
{
	struct termios	term;

	tcgetattr(0, &term);
	if (sig == 0)
	{
		term.c_lflag &= ~ECHOCTL;
		tcsetattr(0, TCSANOW, &term);
	}
}
