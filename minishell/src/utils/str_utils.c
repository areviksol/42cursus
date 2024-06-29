/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aremkrtc <aremkrtc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 16:16:58 by aremkrtc          #+#    #+#             */
/*   Updated: 2023/03/29 11:14:31 by aremkrtc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

int	ft_isalnum(int argument)
{
	if (!((argument <= 122 && argument >= 97) || (argument <= 90 && \
		argument >= 65) || (argument <= 57 && argument >= 48)))
		return (0);
	return (1);
}

int	ft_is_digit_str(char *arg)
{
	int	i;

	i = 0;
	if (arg[0] == '-' || arg[0] == '+')
		i++;
	while (arg[i] != '\0')
	{
		if (!(arg[i] <= 57 && arg[i] >= 48))
			return (0);
		i++;
	}
	return (1);
}

int	ft_is_digit(int arg)
{
	if (!(arg <= 57 && arg >= 48))
		return (0);
	return (1);
}

size_t	ft_strlcpy(char *dest, char *src, size_t size)
{
	size_t	src_s;
	size_t	i;

	i = 0;
	src_s = ft_strlen(src);
	if (size == 0)
		return (src_s);
	while (i < size - 1 && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (src_s);
}
