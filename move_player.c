/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egun <egun@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 21:11:00 by egun              #+#    #+#             */
/*   Updated: 2022/06/29 22:03:08 by egun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	new_map(t_win *win, char **map, int x, int y)
{
	if (map[y][x] == 'C')
			win->map->c_count--;
	win->chr->move_count++;
	if (map[y][x] == 'E' && win->map->c_count == 0)
		ft_key(53, win);
	map[win->chr->y][win->chr->x] = '0';
	map[y][x] = 'P';
	win->chr->x = x;
	win->chr->y = y;
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
