/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aremkrtc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 19:26:20 by aremkrtc          #+#    #+#             */
/*   Updated: 2022/04/15 19:26:24 by aremkrtc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printptr(void *ptr)
{
	int	len;

	len = 2;
	write (1, "0x", 2);
	len += ft_printsnbr((unsigned long)ptr, 0);
	return (len);
}
