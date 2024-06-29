/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main5hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aremkrtc <aremkrtc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 12:03:45 by aremkrtc          #+#    #+#             */
/*   Updated: 2023/03/30 02:43:09 by aremkrtc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	sig_term(int signum)
{
	(void)signum;
	ioctl(STDIN_FILENO, TIOCSTI, "\n");
	rl_on_new_line();
	rl_replace_line("", 0);
	g_status = 0;
}

int	hook_signals(void)
{
	struct sigaction	term;

	term.sa_handler = &sig_term;
	term.sa_flags = SA_RESTART;
	term.sa_mask = 0;
	sigaction(SIGINT, &term, NULL);
	signal(SIGQUIT, SIG_IGN);
	return (0);
}
