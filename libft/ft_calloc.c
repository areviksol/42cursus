/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aremkrtc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 21:37:58 by aremkrtc          #+#    #+#             */
/*   Updated: 2022/03/26 10:51:41 by aremkrtc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	t;
	char	*m;
	size_t	i;

	t = count * size;
	m = malloc(t);
	if (m == NULL)
		return (NULL);
	i = 0;
	while (i < t)
	{
		m[i] = 0;
		i++;
	}
	return (m);
}
