/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aremkrtc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 21:01:46 by aremkrtc          #+#    #+#             */
/*   Updated: 2022/05/04 21:02:37 by aremkrtc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	read_by_size(int fd, char *str, char **buf)
{
	int		read_len;
	char	*str2;

	read_len = read(fd, str, BUFFER_SIZE);
	while (read_len > 0)
	{
		str[read_len] = 0;
		if (!*buf)
			*buf = ft_substr(str, 0, read_len);
		else
		{
			str2 = *buf;
			*buf = ft_strjoin(*buf, str);
			free(str2);
		}
		if (ft_strchr(str, '\n'))
			break ;
		read_len = read(fd, str, BUFFER_SIZE);
	}
}

static char	*main_process(char **buf)
{
	int		i;
	int		j;
	char	*for_substr;
	char	*temp;

	if (!ft_strchr(*buf, '\n'))
	{
		for_substr = ft_substr(*buf, 0, ft_strlen(*buf));
		if (*buf)
			free(*buf);
		*buf = NULL;
		return (for_substr);
	}
	i = ft_strlen(*buf);
	j = ft_strlen(ft_strchr(*buf, '\n'));
	for_substr = ft_substr(*buf, 0, (i - j) + 1);
	temp = *buf;
	*buf = ft_substr(ft_strchr(*buf, '\n'), 1, j - 1);
	free(temp);
	return (for_substr);
}

char	*get_next_line(int fd)
{
	char		*str;
	static char	*buf[256];
	char		*temp;

	if (fd < 0 || fd > 255 || BUFFER_SIZE < 1)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!str)
		return (NULL);
	if (!buf[fd] || !ft_strchr(buf[fd], '\n'))
		read_by_size(fd, str, &buf[fd]);
	free(str);
	if (!buf[fd])
		return (NULL);
	if (!*buf[fd])
	{
		temp = buf[fd];
		buf[fd] = NULL;
		free(temp);
		return (NULL);
	}
	return (main_process(&buf[fd]));
}
