/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aremkrtc <aremkrtc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 15:51:31 by aremkrtc          #+#    #+#             */
/*   Updated: 2022/09/25 16:07:54 by aremkrtc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	throwmessage(void)
{
	perror("Error");
	exit(1);
}

int	getheightofmap(char **map)
{
	int	i;

	i = 0;
	while (map[i] != NULL)
		i++;
	return (i);
}

void	helper(int cond)
{
	if (cond)
		throwmessage();
}

char	**getmap(char *path)
{
	char	*line;
	char	*all_lines;
	int		fd;
	char	*temp;
	char	**temp2;

	line = "";
	all_lines = ft_strdup("");
	fd = open(path, O_RDONLY);
	helper(fd < 0);
	while (line)
	{
		line = get_next_line(fd);
		if (line == NULL || line[0] == '\n')
			break ;
		temp = all_lines;
		all_lines = ft_strjoin(all_lines, line);
		free(temp);
		free(line);
	}
	close(fd);
	helper(all_lines[0] == '\0');
	temp2 = ft_split(all_lines, '\n');
	free(all_lines);
	return (temp2);
}
