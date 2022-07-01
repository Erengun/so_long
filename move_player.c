/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okarakel <omerlutfu.k34@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 16:34:24 by okarakel          #+#    #+#             */
/*   Updated: 2022/06/30 16:34:42 by okarakel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_score(t_win *win)
{
	char	*score;

	score = ft_itoa(win->chr->move_count);
	mlx_string_put(win->mlx, win->win, 62, 62, 0xFF0000, score);
	free(score);
}

void	new_map(t_win *win, char **map, int x, int y)
{
	if (map[y][x] == 'C')
			win->map->c_count--;
	if (map[y][x] == 'E' && win->map->c_count == 0)
	{
		win->chr->move_count++;
		ft_printf("%d\n", win->chr->move_count);
		ft_key(53, win);
	}
	map[win->chr->y][win->chr->x] = '0';
	map[y][x] = 'P';
	win->chr->x = x;
	win->chr->y = y;
	win->chr->move_count++;
	ft_printf("%d\n", win->chr->move_count);
}

void	edit_map(int keycode, t_win *win, char **map)
{
	int	x;
	int	y;

	find_player(win, map);
	x = win->chr->x;
	y = win->chr->y;
	if (keycode == 2)
		x++;
	else if (keycode == 13)
		y--;
	else if (keycode == 1)
		y++;
	else if (keycode == 0)
		x--;
	if (map[y][x] != '1' && (map[y][x] != 'E' || win->map->c_count == 0))
	{
		new_map(win, map, x, y);
		render_map(win, map, keycode);
	}		
}
