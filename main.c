/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egun <egun@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 18:09:25 by egun              #+#    #+#             */
/*   Updated: 2022/06/29 22:27:51 by egun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <fcntl.h>

int	ft_key(int keycode, t_win *win)
{
	//TODO Make xpm file control and norm saying line too long lol
	//!!  Make a func like this
// 	int	close_frame(void *param)
// {
// 	t_win	*pnc;
// 	int		i;

// 	pnc = param;
// 	i = 0;
// 	mlx_destroy_image(pnc->mlx, pnc->chr->chr_front);
// 	mlx_destroy_image(pnc->mlx, pnc->chr->chr_back);
// 	mlx_destroy_image(pnc->mlx, pnc->chr->chr_right);
// 	mlx_destroy_image(pnc->mlx, pnc->chr->chr_left);
// 	mlx_destroy_image(pnc->mlx, pnc->c_bg);
// 	mlx_destroy_image(pnc->mlx, pnc->end_bg);
// 	mlx_destroy_image(pnc->mlx, pnc->block_bg);
// 	mlx_destroy_image(pnc->mlx, pnc->img_bg);
// 	free(pnc->chr);
// 	while (pnc->map->mappin[i])
// 		free(pnc->map->mappin[i++]);
// 	free(pnc->map->mappin);
// 	free(pnc->map);
// 	mlx_destroy_window(pnc->mlx, pnc->win);
// 	exit(1);
// 	return (1);
// }
	printf("%d\n", keycode);
	if (keycode == 53)
	{
		mlx_destroy_window(win->mlx, win->win);
		free(win->map->_map);
		free(win->map);
		free(win->chr);
		free(win);
		system("leaks so_long");
		exit(0);
	}
	else if (keycode == 2 || keycode == 0 || keycode == 13 || keycode == 1)
		edit_map(keycode, win, win->map->_map);
	return (0);
}

int	main(int argc, char **argv)
{
	t_win	*win;

	win = ft_calloc(1, sizeof(t_win));
	win->map = ft_calloc(sizeof(t_map), 1);
	win->chr = ft_calloc(1, sizeof(t_chr));
	if (argc == 2)
	{
		win->mlx = mlx_init();
		map_size(argv[1], win);
		win->win = mlx_new_window(win->mlx, 64*win->map->wid, 64*win->map->hei, "SJ");
		read_map(win, argv[1]);
		map_control(win, win->map->_map);
		mlx_key_hook(win->win, ft_key, win);
		render_map(win, win->map->_map, 13);
		//! Loopu en sona koy amk sala
		mlx_loop(win->mlx);
	}
	return (SJ);
}
