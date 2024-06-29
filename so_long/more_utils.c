/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aremkrtc <aremkrtc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 15:54:08 by aremkrtc          #+#    #+#             */
/*   Updated: 2022/09/28 18:27:35 by aremkrtc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_itoa(int n)
{
	int		len;
	char	*str;
	long	nb;

	len = ft_nb_len(n);
	nb = n;
	str = malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	if (nb < 0)
	{
		str[0] = '-';
		nb = -nb;
	}
	if (nb == 0)
		str[0] = '0';
	str[len--] = '\0';
	while (nb)
	{
		str[len] = nb % 10 + '0';
		len--;
		nb = nb / 10;
	}
	return (str);
}

void	put_text(t_prog ***v)
{
	int		img_w;
	int		img_h;
	char	*text;
	char	*number;

	number = ft_itoa(++(**v)->movement);
	text = ft_join_strings("Move: ", number);
	(**v)->img = mlx_xpm_file_to_image(
			(**v)->mlx, "./textures/wall.xpm", &img_w, &img_h);
	mlx_put_image_to_window(
		(**v)->mlx, (**v)->win, (**v)->img, 0, 0);
	mlx_put_image_to_window(
		(**v)->mlx, (**v)->win, (**v)->img, 50, 0);
	mlx_put_image_to_window(
		(**v)->mlx, (**v)->win, (**v)->img, 50 * 2, 0);
	mlx_string_put((**v)->mlx, (**v)->win, 0, 10, 0xfffffff, text);
	free(text);
	free(number);
}

void	exit_door(t_prog ***v)
{
	int	x;

	x = 0;
	while ((**v)->map[x])
	{
		free((**v)->map[x]);
		x++;
	}
	free((**v)->map);
	mlx_destroy_window((**v)->mlx, (**v)->win);
	exit(1);
}

int	key_hook(int keycode, t_prog *vars)
{
	int	x;

	if (keycode == 2 || keycode == 124)
		to_right(&vars);
	else if (keycode == 0 || keycode == 123)
		to_left(&vars);
	else if (keycode == 13 || keycode == 126)
		to_up(&vars);
	else if (keycode == 1 || keycode == 125)
		to_down(&vars);
	else if (keycode == 53)
	{
		x = 0;
		while (vars->map[x])
		{
			free(vars->map[x]);
			x++;
		}
		free(vars->map);
		mlx_destroy_window(vars->mlx, vars->win);
		exit(1);
	}
	return (0);
}
