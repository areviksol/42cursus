/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aremkrtc <aremkrtc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 14:22:49 by aremkrtc          #+#    #+#             */
/*   Updated: 2022/09/28 18:30:54 by aremkrtc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static	void	initialv(t_prog *vars)
{
	vars->collect = 0;
	vars->movement = 0;
	vars->win_w = ft_strlen(vars->map[0]);
	vars->win_h = getheightofmap(vars->map);
}

int	ft_exit(t_prog *v)
{
	int	x;

	x = 0;
	while (v->map[x])
	{
		free(v->map[x]);
		x++;
	}
	free(v->map);
	mlx_destroy_window(v->mlx, v->win);
	exit(1);
}

int	main(int argc, char **argv)
{
	t_prog	vars;

	if (argc <= 1)
		exit(1);
	isfilevalid(argv[1]);
	vars.map = getmap(argv[1]);
	if (vars.map != NULL)
	{
		ismapvalid(&vars);
		initialv(&vars);
		vars.mlx = mlx_init();
		vars.win = mlx_new_window(vars.mlx,
				vars.win_w * 50, vars.win_h * 50, "So-Long");
		render(&vars);
		mlx_hook(vars.win, 2, (1L << 0), key_hook, &vars);
		mlx_hook(vars.win, 17, (1L << 0), ft_exit, &vars);
		mlx_string_put(vars.mlx, vars.win, 5, 10, 0xffffff, "Move: 0");
		mlx_loop(vars.mlx);
	}
	return (0);
}
