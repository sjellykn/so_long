/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjelly <sjelly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 23:15:59 by sjelly            #+#    #+#             */
/*   Updated: 2022/01/14 23:18:53 by sjelly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_map_is_one(char *str, int len, int first_last_line, t_game *game)
{
	int	i;

	if (first_last_line == 1)
	{
		i = 0;
		while (str[i])
		{
			if (str[i] != '1')
				ft_exit("Error! Bad symbols!\n", game, FAILURE);
			i++;
		}
	}
	else
	{
		if ((str[0] != '1') || (str[len - 1] != '1'))
			ft_exit("Error! Bad symbols!\n", game, FAILURE);
	}
	return (1);
}

int	ft_check_characters(t_check *check)
{
	if (check->len2)
	{
		if (check->len2 != check->len)
			return (1);
		else
			return (0);
	}
	check->len2 = check->len;
	return (0);
}

void	ft_check_loop(t_check *check, t_game *game)
{
	while (check->read > 0)
	{
		check->read = get_next_line(check->fd, &check->line);
		check->len = ft_strlen_int(check->line);
		if (check->i == check->len)
			ft_exit("Error! This is not a rectangle!\n", game, FAILURE);
		if (ft_check_characters(check))
			ft_exit("Error! This is not a rectangle!\n", game, FAILURE);
		ft_check_play(check->line, check->read, game);
		ft_check_is_nbr(check->line, game);
		if (check->read == 0)
			ft_map_is_one(check->line, check->len, 1, game);
		else
			ft_map_is_one(check->line, check->len, 0, game);
		free(check->line);
	}
}

t_check	ft_check_is_map(char *argv, t_game *game)
{
	t_check	check;

	check.len = 0;
	check.len2 = 0;
	check.read = 1;
	check.i = ft_number_of_lines(argv);
	if (check.i <= 0)
		ft_exit("Error! The file may not exist!\n", game, FAILURE);
	check.fd = open(argv, O_RDWR);
	if (check.fd < 0)
		ft_exit("Error! Bad file!\n", game, FAILURE);
	ft_check_loop(&check, game);
	close(check.fd);
	return (check);
}

void	ft_parsing(char *argv, t_game *game)
{
	t_check	check;
	int		i;

	i = 0;
	check_is_file(argv, *game);
	check = ft_check_is_map(argv, game);
	game->map_x_len = check.len;
	game->map_y_len = check.i;
	game->map = malloc(sizeof(char *) * check.i + 1);
	if (game->map == NULL)
		ft_exit("Error! Can't malloc!\n", game, FAILURE);
	check.fd = open(argv, O_RDONLY);
	while (check.fd > 0)
		check.fd = get_next_line_new(check.fd, &game->map[i++]);
	game->map[i] = NULL;
	close(check.fd);
}
