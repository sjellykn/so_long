/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjelly <sjelly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 22:46:42 by sjelly            #+#    #+#             */
/*   Updated: 2022/01/14 23:58:54 by sjelly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_init_all(t_game *game)
{	
	game->mlx = mlx_init();
	if (!game->mlx)
		ft_exit("Error! Can't init mlx !\n", game, FAILURE);
	game->win = mlx_new_window(game->mlx,
			63 * game->map_x_len, 63 * game->map_y_len, "So_long");
	ft_init_img(game);
	ft_draw_map(game);
	mlx_hook(game->win, 17, 0, ft_end, game);
	mlx_hook(game->win, 2, 0, ft_key, (void *)game);
	mlx_loop_hook(game->mlx, ft_update, (void *)game);
	mlx_loop(game->mlx);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	game = ft_calloc(sizeof(t_game), 1);
	if (argc != 2)
		ft_exit("Error! Bad argument!\n", NULL, FAILURE);
	if (!game)
		ft_exit("Error! Can't malloc(game)!\n", game, FAILURE);
	ft_parsing(argv[1], game);
	ft_init_all(game);
}
