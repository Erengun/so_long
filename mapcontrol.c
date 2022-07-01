/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapcontrol.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egun <egun@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 14:47:02 by egun              #+#    #+#             */
/*   Updated: 2022/07/01 17:00:24 by egun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	component_control(t_win	*win, char	**map)
{
	int		i;
	int		j;

	i = -1;
	while (++i < win->map->hei)
	{
		j = -1;
		while (map[i][++j])
		{
			if (!ft_strchr("01ECP", map[i][j]))
				ft_error("The map contains invalid letter(s).");
			else if (map[i][j] == 'P')
				win->map->p_count++;
			else if (map[i][j] == 'C')
				win->map->c_count++;
			else if (map[i][j] == 'E')
				win->map->e_count++;
		}
	}
	if (win->map->p_count != 1)
		ft_error("Invalid number of player(s)");
	if (win->map->e_count < 1)
		ft_error("Invalid exit door.");
	if (win->map->c_count < 1)
		ft_error("Invalid collectible.");
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
					ft_error("Invalid walls. Check the borders of the map.");
					break ;
				}
			}
		}
		if (map[i][0] != '1' || map[i][win->map->wid - 1] != '1')
		{
			ft_error("Invalid walls. Check the borders of the map.");
			break ;
		}
	}
}

void	map_control(t_win	*win, char	**map)
{
	win->map->p_count = 0;
	component_control(win, map);
	wall_control(win, map);
}
