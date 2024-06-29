/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aremkrtc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 20:30:12 by aremkrtc          #+#    #+#             */
/*   Updated: 2022/03/26 11:04:54 by aremkrtc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		u;
	unsigned char		*dc;
	const unsigned char	*sc;
	size_t				i;

	u = (unsigned char)c;
	dc = (unsigned char *)dst;
	sc = (const unsigned char *)src;
	i = 0;
	while (i < n)
	{
		dc[i] = sc[i];
		if (sc[i] == u)
			return (dst + i + 1);
		i++;
	}
	return (0);
}
