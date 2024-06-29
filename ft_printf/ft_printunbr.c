/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aremkrtc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 19:25:43 by aremkrtc          #+#    #+#             */
/*   Updated: 2022/04/15 19:28:32 by aremkrtc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printunbr(unsigned int c)
{
	int				a;

	a = 0;
	if (c > 9)
	{
		a += ft_printunbr(c / 10);
		a += ft_printunbr(c % 10);
	}
	else
		a += ft_printchar(c + '0');
	return (a);
}
