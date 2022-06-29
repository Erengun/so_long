/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egun <egun@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 18:04:00 by egun              #+#    #+#             */
/*   Updated: 2022/06/29 21:17:17 by egun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define SJ 31

# include "./ft_printf/ft_printf.h"
# include "./ft_printf/libft/libft.h"
# include "./mlx/mlx.h"
# include "./gnl/get_next_line.h"
//TODO sil
# include <stdio.h>

typedef struct s_map
{
	int			wid;
	int			hei;
	char		**_map;
	int			p_count;
	int			c_count;
	int			e_count;
	void		*xpm_bg;
	void		*xpm_wall;
	void		*xpm_coin;
}	t_map;

typedef struct s_chr
{
	void	*chr_r;
	void	*chr_l;
	void	*chr_up;
	void	*chr_down;
	int		move_count;
	int		size;
	int		x;
	int		y;
}	t_chr;

typedef struct s_win
{
	t_map	*map;
	t_chr	*chr;
	void	*mlx;
	void	*win;
	void	*bg;
	void	*wall;
	void	*exit;
	void	*coin;
}	t_win;

void	map_size(char *path, t_win *map);
void	ft_error(char	*msg);
void	read_map(t_win *win, char *path);
void	map_control(t_win	*win, char	**map);
void	player_control(t_win	*win, char	**map);
void	wall_control(t_win *win, char **map);
void	collectible_control(t_win *win, char **map);
void	exit_control(t_win *win, char **map);
void	render_map(t_win *win, char	**map, int move);
int		ft_key(int keycode, t_win *win);
void	edit_map(int keycode, t_win *win, char **map);
void	find_player(t_win *win, char **map);

#endif
