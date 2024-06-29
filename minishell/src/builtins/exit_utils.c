/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aremkrtc <aremkrtc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 18:56:56 by aremkrtc          #+#    #+#             */
/*   Updated: 2023/03/30 18:56:57 by aremkrtc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	iszero(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (s[i] && (s[i] == '-' || s[i] == '+'))
		i++;
	while (s[i])
	{
		if (s[i] != '0')
			return (0);
		i++;
	}
	return (1);
}

static char	*one_zero_str(char *s)
{
	s[0] = '0';
	s[1] = '\0';
	return (s);
}

static int	numlen(char *s)
{
	int	i;
	int	len;

	if (!s)
		return (0);
	if (iszero(s))
		return (1);
	i = 0;
	len = 0;
	if (s[i] && s[i] == '+')
		i++;
	else if (s[i] && s[i] == '-')
	{
		len++;
		i++;
	}
	while (s[i] == '0')
		i++;
	while (s[i++])
		len++;
	return (len);
}

char	*numstr(char *str)
{
	char	*s;
	int		i;
	int		j;

	s = malloc(numlen(str) + 1);
	if (!s)
		return (NULL);
	if (iszero(str))
		return (one_zero_str(s));
	i = 0;
	j = 0;
	if (str[i] && str[i] == '+')
		i++;
	else if (str[i] && str[i] == '-')
	{
		s[j++] = '-';
		i++;
	}
	while (str[i] == '0')
		i++;
	while (str[i])
		s[j++] = str[i++];
	s[j] = '\0';
	return (s);
}
