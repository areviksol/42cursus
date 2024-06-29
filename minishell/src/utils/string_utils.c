/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aremkrtc <aremkrtc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 16:19:35 by aremkrtc          #+#    #+#             */
/*   Updated: 2023/03/29 22:24:14 by aremkrtc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_word_len(char *word, int i)
{
	int	len;

	len = 0;
	while (word[i] && ft_is_word(word[i]))
	{
		len++;
		i++;
	}
	return (len);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	write(fd, s, ft_strlen(s));
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*res;

	i = 0;
	j = 0;
	res = malloc(sizeof (*res) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!res)
		return (NULL);
	while (s1 && s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	while (s2 && s2[j])
	{
		res[i] = s2[j];
		i++;
		j++;
	}
	res[i] = '\0';
	return (res);
}

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	unsigned char		*dest2;
	unsigned const char	*src2;
	size_t				i;

	dest2 = dest;
	src2 = src;
	if (!dest && !src)
		return (0);
	if (dest2 >= src2)
	{
		while (len--)
			dest2[len] = src2[len];
	}
	else if (dest2 < src2)
	{
		i = 0;
		while (i < len)
		{
			dest2[i] = src2[i];
			i++;
		}
	}
	return (dest);
}

size_t	ft_strlcat(char *dest, const char *src, size_t len)
{
	int		total;
	size_t	i;
	size_t	j;
	size_t	ldest;
	size_t	lsrc;

	i = 0;
	j = 0;
	ldest = ft_strlen(dest);
	lsrc = ft_strlen((char *)src);
	if (len > ldest)
		total = ldest + lsrc;
	else
		total = lsrc + len;
	j = ldest;
	while (src[i] && j + 1 < len)
	{
		dest[j] = src[i];
		i++;
		j++;
	}
	dest[j] = 0;
	return (total);
}
