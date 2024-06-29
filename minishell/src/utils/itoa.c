/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aremkrtc <aremkrtc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 16:13:41 by aremkrtc          #+#    #+#             */
/*   Updated: 2023/03/22 16:13:49 by aremkrtc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_putnum(long num, int size, char *str)
{
	if (num < 0)
	{
		*str++ = '-';
		num = -num;
	}
	while (size)
	{
		*str++ = (num / size) + '0';
		num %= size;
		size /= 10;
	}
	*str = '\0';
}

void	change_positive(long *num, int *size)
{
	if (*num < 0)
	{
		*num = -*num;
		*size += 1;
	}
}

char	*ft_itoa(int n)
{
	int		size;
	long	num;
	long	numprint;
	char	*ptr;
	int		temp;

	temp = 1;
	num = n;
	numprint = n;
	size = 1;
	change_positive(&num, &size);
	while (num >= 10)
	{
		num = num / 10;
		temp *= 10;
		size++;
	}
	ptr = (char *)malloc(size + 1);
	if (ptr == 0)
		return (0);
	ft_putnum(numprint, temp, ptr);
	return (ptr);
}
