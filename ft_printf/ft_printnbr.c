/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aremkrtc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 19:25:22 by aremkrtc          #+#    #+#             */
/*   Updated: 2022/04/15 19:25:27 by aremkrtc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printnbr(int c)
{
	long	b;
	int		a;

	b = c;
	a = 0;
	if (b == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (b < 0)
	{
		ft_printchar('-');
		b = b * -1;
		a++;
	}
	if (b > 9)
	{
		a += ft_printnbr(b / 10);
		a += ft_printnbr(b % 10);
	}
	else
		a += ft_printchar(b + '0');
	return (a);
}
