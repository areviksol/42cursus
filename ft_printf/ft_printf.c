/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aremkrtc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 19:26:06 by aremkrtc          #+#    #+#             */
/*   Updated: 2022/04/15 19:32:41 by aremkrtc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	checkformat(va_list args, const char format)
{
	int	p;

	p = 0;
	if (format == 'c')
		p += ft_printchar(va_arg(args, int));
	else if (format == 's')
		p += ft_printstring(va_arg(args, char *));
	else if (format == 'p')
		p += ft_printptr(va_arg(args, void *));
	else if (format == 'd' || format == 'i')
		p += ft_printnbr(va_arg(args, int));
	else if (format == 'u')
		p += ft_printunbr(va_arg(args, unsigned int));
	else if (format == 'x')
		p += ft_printsnbr(va_arg(args, unsigned int), 0);
	else if (format == 'X')
		p += ft_printsnbr(va_arg(args, unsigned int), 1);
	else if (format == '%')
		p += ft_printchar('%');
	return (p);
}	

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	args;
	int		p;

	i = 0;
	p = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			p = p + checkformat(args, str[i + 1]);
			i++;
		}
		else
			p = p + ft_printchar(str[i]);
		i++;
	}
	va_end(args);
	return (p);
}
