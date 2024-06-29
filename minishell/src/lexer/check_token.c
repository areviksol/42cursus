/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aremkrtc <aremkrtc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 17:39:35 by aremkrtc          #+#    #+#             */
/*   Updated: 2023/03/22 17:40:00 by aremkrtc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_is_space(char c)
{
	return (c == '\t' || c == '\n' || c == '\r' || \
	c == '\v' || c == ' ' || c == '\f');
}

int	ft_is_redirection_in(char c)
{
	return (c == '<');
}

int	ft_is_redirection_out(char c)
{
	return (c == '>');
}

int	ft_is_word(char c)
{
	return (c != '|' && !ft_is_redirection_in(c) && \
	!ft_is_redirection_out(c) && !ft_is_space(c));
}
