/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjelly <sjelly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 23:21:31 by sjelly            #+#    #+#             */
/*   Updated: 2022/01/14 23:28:08 by sjelly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_is_file(char *argv, t_game game)
{
	int	i;

	i = ft_strlen_int(argv);
	while (argv[i] != '.')
	{
		if (i == 0)
			ft_exit("Error! Bad file!\n", &game, FAILURE);
		i--;
	}
	i++;
	if (ft_strcmp((argv + i), "ber") != 0)
		ft_exit("Error! Bad file extension!\n", &game, FAILURE);
	return (1);
}

int	ft_number_of_lines(char *argv)
{
	int		i;
	int		count;
	int		fd;
	int		readcount;
	char	c;

	i = 0;
	count = 1;
	fd = open(argv, O_RDONLY);
	if (!fd)
		return (-1);
	readcount = read(fd, &c, 1);
	while (readcount != 0)
	{
		readcount = read(fd, &c, 1);
		if (c == '\n')
			count++;
		i++;
	}
	return (count);
}

void	ft_play_loop(int *nbr, int r, t_game *game)
{
	int	i;

	i = 0;
	if (!r)
	{
		while (i < 3)
		{
			if (nbr[i++] < 1 || nbr[2] > 1)
				ft_exit("Error!\n", game, FAILURE);
		}
	}
}

int	ft_check_play(char *str, int r, t_game *game)
{
	int			j;
	int			i;
	const char	play[] = {'C', 'E', 'P'};
	static int	nbr[3] = {0};

	i = 0;
	while (str[i])
	{
		j = 0;
		while (j < 3)
		{
			if (str[i] == play[j])
				nbr[j]++;
			j++;
		}
		i++;
	}
	ft_play_loop(nbr, r, game);
	return (1);
}

int	ft_check_is_nbr(char *str, t_game *game)
{
	int			i;
	static int	j;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] != '0' && str[i] != '1'
			&& str[i] != 'E' && str[i] != 'P' && str[i] != 'C')
			ft_exit("Error! Bad card!\n", game, FAILURE);
		if (str[i] == 'C')
			game->collect++;
		if (str[i] == 'P')
		{
			game->player_place.y = i;
			game->player_place.x = j;
		}
		i++;
	}
	j++;
	return (1);
}
