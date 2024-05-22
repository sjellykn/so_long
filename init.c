/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjelly <sjelly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 22:43:14 by sjelly            #+#    #+#             */
/*   Updated: 2022/01/14 23:13:53 by sjelly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_key(int key, t_game *game)
{
	if (key == 53)
		ft_end(game);
	if (key == 13)
		ft_press_w(game);
	if (key == 0)
		ft_press_a(game);
	if (key == 1)
		ft_press_s(game);
	if (key == 2)
		ft_press_d(game);
	return (0);
}

void	ft_draw_map_2(t_game *game, int x, int y)
{
	while (game->map[y][x])
	{
		if (game->map[y][x] == '1')
			mlx_put_image_to_window(game->mlx,
				game->win, game->img1, x * 63, y * 63);
		if (game->map[y][x] == '0')
			mlx_put_image_to_window(game->mlx,
				game->win, game->img2, x * 63, y * 63);
		if (game->map[y][x] == 'C')
			mlx_put_image_to_window(game->mlx,
				game->win, game->img3, x * 63, y * 63);
		if (game->map[y][x] == 'P')
			mlx_put_image_to_window(game->mlx,
				game->win, game->img4, x * 63, y * 63);
		if (game->map[y][x] == 'E')
			mlx_put_image_to_window(game->mlx,
				game->win, game->img5, x * 63, y * 63);
		x++;
	}
}

void	ft_draw_map(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (game->map[y])
	{
		x = 0;
		ft_draw_map_2 (game, x, y);
		y++;
	}
}

void	ft_init_img(t_game *game)
{
	int	h;
	int	w;

	game->img1 = mlx_xpm_file_to_image(game->mlx,
			"./textures/wall.xpm", &w, &h);
	game->img2 = mlx_xpm_file_to_image(game->mlx,
			"./textures/grass.xpm", &w, &h);
	game->img3 = mlx_xpm_file_to_image(game->mlx,
			"./textures/collect.xpm", &w, &h);
	game->img4 = mlx_xpm_file_to_image(game->mlx,
			"./textures/sanik.xpm", &w, &h);
	game->img5 = mlx_xpm_file_to_image(game->mlx,
			"./textures/exit.xpm", &w, &h);
}

int	ft_update(t_game *game)
{
	mlx_clear_window(game->mlx, game->win);
	ft_draw_map(game);
	return (0);
}
