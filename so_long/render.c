/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aremkrtc <aremkrtc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 15:55:42 by aremkrtc          #+#    #+#             */
/*   Updated: 2022/09/28 18:28:29 by aremkrtc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	putimage(t_prog ***v, int x, int y, char *img)
{
	int		img_w;
	int		img_h;

	(**v)->img = mlx_xpm_file_to_image((**v)->mlx, img, &img_w, &img_h);
	mlx_put_image_to_window((**v)->mlx, (**v)->win, (**v)->img, x, y);
}

void	putimagetomap(char p, int x1, int y1, t_prog **v)
{
	if (p == '1')
		putimage(&v, x1, y1, "./textures/wall.xpm");
	else if (p == 'C')
	{
		putimage(&v, x1, y1, "./textures/floor.xpm");
		putimage(&v, x1, y1, "./textures/coin.xpm");
		(*v)->collect++;
	}
	else if (p == 'E')
	{
		putimage(&v, x1, y1, "./textures/exit.xpm");
	}
	else if (p == 'P')
	{
		(*v)->y_p = y1;
		(*v)->x_p = x1;
		putimage(&v, x1, y1, "./textures/floor.xpm");
		putimage(&v, x1, y1, "./textures/player.xpm");
	}
	else
		putimage(&v, x1, y1, "./textures/floor.xpm");
}

void	render(t_prog *vars)
{
	int	y1;
	int	y_map;
	int	backup_w;
	int	x1;
	int	x_map;

	y1 = 0;
	y_map = 0;
	backup_w = vars->win_w;
	while (vars->win_h > 0)
	{
		x1 = 0;
		x_map = 0;
		while (vars->win_w > 0)
		{
			putimagetomap(vars->map[y_map][x_map], x1, y1, &vars);
			x_map++;
			x1 += 50;
			vars->win_w--;
		}
		vars->win_w = backup_w;
		y_map++;
		y1 += 50;
		vars->win_h--;
	}
}
