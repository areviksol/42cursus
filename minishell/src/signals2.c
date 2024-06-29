/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aremkrtc <aremkrtc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 11:48:13 by aremkrtc          #+#    #+#             */
/*   Updated: 2023/03/29 16:36:33 by aremkrtc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_quite(int sig)
{
	(void)sig;
	write(1, "Quit: 3\n\n", 9);
	rl_on_new_line();
	rl_redisplay();
}
