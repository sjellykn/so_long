/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjelly <sjelly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 21:42:58 by sjelly            #+#    #+#             */
/*   Updated: 2022/01/14 21:43:12 by sjelly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_exit(char *message, t_game *game, int ret)
{
	if (message)
		ft_putstr(message);
	if (game != NULL)
		free(game);
	exit (ret);
}

int	ft_end(t_game *game)
{
	free(game->map);
	exit (0);
}

int	ft_strlen_int(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
