/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printsnbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aremkrtc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 19:27:38 by aremkrtc          #+#    #+#             */
/*   Updated: 2022/04/15 19:27:41 by aremkrtc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printsnbr(unsigned long c, int t)
{
	int	len;

	len = 0;
	if (c > 15)
		len += ft_printsnbr(c / 16, t);
	c = c % 16;
	if (c > 9 && t == 0)
		len += ft_printchar(c + 87);
	else if (c > 9 && t == 1)
		len += ft_printchar(c + 55);
	else if (c < 10)
		len += ft_printchar(c + 48);
	return (len);
}
