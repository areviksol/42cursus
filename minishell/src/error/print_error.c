/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aremkrtc <aremkrtc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 17:06:30 by aremkrtc          #+#    #+#             */
/*   Updated: 2023/03/30 02:46:07 by aremkrtc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_print_error(t_data *data, char *error_str)
{
	data->error_status = 1;
	write(2, error_str, ft_strlen(error_str));
	return (1);
}
