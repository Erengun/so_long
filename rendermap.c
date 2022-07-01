/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendermap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okarakel <omerlutfu.k34@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 16:32:50 by okarakel          #+#    #+#             */
/*   Updated: 2022/06/30 16:32:51 by okarakel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put(t_win *win, int move, int i, int j)
{
	char	**map;

	map = win->map->_map;
	if (map[i][j] == 'C')
		mlx_put_image_to_window(win->mlx,
			win->win, win->coin, j * 64, i * 64);
	else if (map[i][j] == '1')
		mlx_put_image_to_window(win->mlx,
			win->win, win->wall, j * 64, i * 64);
	else if (map[i][j] == 'P' && move == 2)
		mlx_put_image_to_window(win->mlx,
			win->win, win->chr->chr_r, j * 64, i * 64);
	else if (map[i][j] == 'P' && move == 13)
		mlx_put_image_to_window(win->mlx,
			win->win, win->chr->chr_up, j * 64, i * 64);
	else if (map[i][j] == 'P' && move == 0)
		mlx_put_image_to_window(win->mlx,
			win->win, win->chr->chr_l, j * 64, i * 64);
	else if (map[i][j] == 'P' && move == 1)
		mlx_put_image_to_window(win->mlx,
			win->win, win->chr->chr_down, j * 64, i * 64);
	else if (map[i][j] == 'E')
		mlx_put_image_to_window(win->mlx,
			win->win, win->exit, j * 64, i * 64);
}

void	render_others(t_win *win, char **map, int move)
{
	int	i;
	int	j;

	i = -1;
	while (++i < win->map->hei)
	{
		j = -1;
		while (map[i][++j])
			put(win, move, i, j);
	}
}

void	fti(t_win *win)
{
	win->chr->size = 64;
	win->bg = mlx_xpm_file_to_image(win->mlx,
			"./xpm/bg_2.xpm", &win->chr->size, &win->chr->size);
	win->chr->chr_down = mlx_xpm_file_to_image(win->mlx,
			"./xpm/chr_down.xpm", &win->chr->size, &win->chr->size);
	win->chr->chr_up = mlx_xpm_file_to_image(win->mlx,
			"./xpm/chr_up.xpm", &win->chr->size, &win->chr->size);
	win->chr->chr_l = mlx_xpm_file_to_image(win->mlx,
			"./xpm/chr_l.xpm", &win->chr->size, &win->chr->size);
	win->chr->chr_r = mlx_xpm_file_to_image(win->mlx,
			"./xpm/chr_r.xpm", &win->chr->size, &win->chr->size);
	win->exit = mlx_xpm_file_to_image(win->mlx,
			"./xpm/exit.xpm", &win->chr->size, &win->chr->size);
	win->wall = mlx_xpm_file_to_image(win->mlx,
			"./xpm/asteroid.xpm", &win->chr->size, &win->chr->size);
	win->coin = mlx_xpm_file_to_image(win->mlx,
			"./xpm/collect.xpm", &win->chr->size, &win->chr->size);
}

void	render_map(t_win *win, char	**map, int move)
{
	int	i;
	int	j;

	fti(win);
	i = -1;
	while (++i < win->map->hei)
	{
		j = -1;
		while (map[i][++j])
			mlx_put_image_to_window(win->mlx,
				win->win, win->bg, j * 64, i * 64);
	}
	render_others(win, map, move);
	put_score(win);
}

void	find_player(t_win *win, char **map)
{
	int	i;
	int	j;

	i = -1;
	while (++i < win->map->hei)
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'P')
			{
				win->chr->x = j;
				win->chr->y = i;
			}
		}
	}
}
