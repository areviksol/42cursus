/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aremkrtc <aremkrtc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 15:56:01 by aremkrtc          #+#    #+#             */
/*   Updated: 2022/09/28 14:23:38 by aremkrtc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include "./get_next_line/get_next_line.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_prog {
	void			*mlx;
	void			*img;
	void			*win;
	int				win_w;
	int				win_h;
	int				x_p;
	int				y_p;
	int				e_x;
	int				e_y;
	int				movement;
	char			**map;
	int				collect;
}	t_prog;

typedef struct s_vars_map {
	int	c;
	int	p;
	int	e;
	int	x;
	int	y;
}	t_map_vars;
char	*ft_itoa(int n);
char	*malloc_strings(const char *s, char c);
char	*ft_strdup(const char *s1);
char	*ft_join_strings(char const *s1, char const *s2);
char	*unknown_element(t_prog ***v);
char	**getmap(char *path);
char	**ft_split(char const *s, char c);
int		getheightofmap(char **map);
int		count_strings(char const *s, char c);
int		ft_exit(t_prog *v);
int		key_hook(int keycode, t_prog *vars);
size_t	ft_nb_len(int nb);

void	isfilevalid(char *file_line);
void	ft_error(t_prog ***v, char *err);
void	ismapvalid(t_prog *vars);
void	checkelements(t_prog **vars);
void	putimage(t_prog ***v, int x, int y, char *img);
void	putimagetomap(char p, int x1, int y1, t_prog **v);
void	render(t_prog *vars);
void	to_left(t_prog **v);
void	to_right(t_prog **v);
void	to_up(t_prog **v);
void	to_down(t_prog **v);
void	put_text(t_prog ***v);
void	exit_door(t_prog ***v);

#endif
