/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapcontrol.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egun <egun@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 14:47:02 by egun              #+#    #+#             */
/*   Updated: 2022/06/30 15:23:47 by egun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_control(t_win	*win, char	**map)
{
	player_control(win, map);
	wall_control(win, map);
	collectible_control(win, map);
	exit_control(win, map);
}

void	player_control(t_win	*win, char	**map)
{
	int		i;
	int		j;

	i = -1;
	win->map->p_count = 0;
	while (++i < win->map->hei)
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'P')
				win->map->p_count++;
		}
	}
	if (win->map->p_count != 1)
		ft_error("Invalid Player Count");
}

void	wall_control(t_win *win, char **map)
{
	int	i;
	int	j;

	i = -1;
	while (++i < win->map->hei)
	{
		j = -1;
		while (map[i][++j])
		{
			if (i == 0 || i == win->map->hei - 1)
			{
				if (map[i][j] != '1')
				{
					ft_error("Invalid map wall");
					break ;
				}
			}
		}
		if (map[i][0] != '1' || map[i][win->map->wid - 1] != '1')
		{
			ft_error("Invalid map wall");
			break ;
		}
	}
}

void	collectible_control(t_win *win, char **map)
{
	int		i;
	int		j;

	i = -1;
	win->map->c_count = 0;
	while (++i < win->map->hei)
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'C')
				win->map->c_count++;
		}
	}
	if (win->map->c_count < 1)
		ft_error("Invalid Colletible Count");
}

void	exit_control(t_win *win, char **map)
{
	int		i;
	int		j;

	i = -1;
	win->map->e_count = 0;
	while (++i < win->map->hei)
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'E')
				win->map->e_count++;
		}
	}
	if (win->map->e_count < 1)
		ft_error("Invalid Exit Door Count");
}
