/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjelly <sjelly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 23:15:24 by sjelly            #+#    #+#             */
/*   Updated: 2022/01/14 23:15:43 by sjelly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_move_up(t_game *game)
{
	game->map[game->player_place.x][game->player_place.y] = '0';
	game->player_place.x = game->player_place.x - 1;
	game->map[game->player_place.x][game->player_place.y] = 'P';
}

void	ft_move_left(t_game *game)
{
	game->map[game->player_place.x][game->player_place.y] = '0';
	game->player_place.y = game->player_place.y - 1;
	game->map[game->player_place.x][game->player_place.y] = 'P';
}

void	ft_move_down(t_game *game)
{
	game->map[game->player_place.x][game->player_place.y] = '0';
	game->player_place.x = game->player_place.x + 1;
	game->map[game->player_place.x][game->player_place.y] = 'P';
}

void	ft_move_right(t_game *game)
{
	game->map[game->player_place.x][game->player_place.y] = '0';
	game->player_place.y = game->player_place.y + 1;
	game->map[game->player_place.x][game->player_place.y] = 'P';
}
