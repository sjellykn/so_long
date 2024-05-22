/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   press.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjelly <sjelly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 23:19:02 by sjelly            #+#    #+#             */
/*   Updated: 2022/01/14 23:19:49 by sjelly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_press_w(t_game *game)
{
	if (game->map[game->player_place.x - 1][game->player_place.y] == '0')
		ft_move_up(game);
	else if (game->map[game->player_place.x - 1][game->player_place.y] == '1')
		return (1);
	else if (game->map[game->player_place.x - 1][game->player_place.y] == 'C')
	{
		ft_move_up(game);
		game->collect--;
	}
	else
	{
		if (game->collect == 0)
			ft_end(game);
		else
			return (1);
	}
	return (0);
}

int	ft_press_a(t_game *game)
{
	if (game->map[game->player_place.x][game->player_place.y - 1] == '1')
		return (1);
	else if (game->map[game->player_place.x][game->player_place.y - 1] == '0')
		ft_move_left(game);
	else if (game->map[game->player_place.x][game->player_place.y - 1] == 'C')
	{
		ft_move_left(game);
		game->collect--;
	}
	else if (game->map[game->player_place.x][game->player_place.y - 1] == 'E')
	{
		if (game->collect == 0)
			ft_end(game);
		else
			return (1);
	}
	return (0);
}

int	ft_press_s(t_game *game)
{
	if (game->map[game->player_place.x + 1][game->player_place.y] == '1')
		return (1);
	else if (game->map[game->player_place.x + 1][game->player_place.y] == '0')
		ft_move_down(game);
	else if (game->map[game->player_place.x + 1][game->player_place.y] == 'C')
	{
		ft_move_down(game);
		game->collect--;
	}
	else
	{
		if (game->collect == 0)
			ft_end(game);
		else
			return (1);
	}
	return (0);
}

int	ft_press_d(t_game *game)
{
	if (game->map[game->player_place.x][game->player_place.y + 1] == '1')
		return (1);
	else if (game->map[game->player_place.x][game->player_place.y + 1] == '0')
		ft_move_right(game);
	else if (game->map[game->player_place.x][game->player_place.y + 1] == 'C')
	{
		ft_move_right(game);
		game->collect--;
	}
	else
	{
		if (game->collect == 0)
			ft_end(game);
		else
			return (1);
	}
	return (0);
}
