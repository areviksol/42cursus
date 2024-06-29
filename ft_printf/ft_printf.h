/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aremkrtc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 19:27:09 by aremkrtc          #+#    #+#             */
/*   Updated: 2022/04/15 19:33:31 by aremkrtc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *str, ...);
int		ft_printchar(int c);
int		ft_printstring(char *str);
int		ft_printptr(void *ptr);
int		ft_printnbr(int c);
int		ft_printunbr(unsigned int c);
int		ft_printsnbr(unsigned long c, int t);
size_t	ft_strlen(const char *s);

#endif
