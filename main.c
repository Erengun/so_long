/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egun <egun@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 18:09:25 by egun              #+#    #+#             */
/*   Updated: 2022/07/01 22:01:48 by egun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_frame(t_win *win)
{
	int		i;

	i = -1;
	mlx_destroy_image(win->mlx, win->chr->chr_up);
	mlx_destroy_image(win->mlx, win->chr->chr_down);
	mlx_destroy_image(win->mlx, win->chr->chr_r);
	mlx_destroy_image(win->mlx, win->chr->chr_l);
	mlx_destroy_image(win->mlx, win->bg);
	mlx_destroy_image(win->mlx, win->coin);
	mlx_destroy_image(win->mlx, win->exit);
	mlx_destroy_image(win->mlx, win->wall);
	while (++i < win->map->hei)
		free(win->map->_map[i]);
	mlx_destroy_window(win->mlx, win->win);
	exit(1);
	return (0);
}

int	ft_key(int keycode, t_win *win)
{
	if (keycode == 53)
		close_frame(win);
	else if (keycode == 2 || keycode == 0 || keycode == 13 || keycode == 1)
		edit_map(keycode, win, win->map->_map);
	return (0);
}

int	main(int argc, char **argv)
{
	t_win	*win;

	if (argc == 2 && !ft_strncmp(&argv[1][ft_strlen(argv[1]) - 4], ".ber", 5))
	{
		win = ft_calloc(1, sizeof(t_win));
		win->map = ft_calloc(sizeof(t_map), 1);
		win->chr = ft_calloc(1, sizeof(t_chr));
		win->mlx = mlx_init();
		map_size(argv[1], win);
		win->win = mlx_new_window(win->mlx,
				64 * win->map->wid, 64 * win->map->hei, "Cowboy Bebop");
		read_map(win, argv[1]);
		map_control(win, win->map->_map);
		mlx_hook(win->win, 2, 1L << 0, ft_key, win);
		mlx_hook(win->win, 17, 0, close_frame, win);
		render_map(win, win->map->_map, 13);
		mlx_loop(win->mlx);
	}
	else
		ft_error("Invalid input.");
	return (0);
}
