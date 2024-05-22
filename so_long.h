/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjelly <sjelly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 23:32:59 by sjelly            #+#    #+#             */
/*   Updated: 2022/01/14 23:35:58 by sjelly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdio.h>
# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft/libft.h"
# include "get_next_line/get_next_line.h"
# define SUCCESS 0
# define FAILURE 1
# define RED_CROSS 17

typedef struct s_vector
{
	int		x;
	int		y;
}			t_vector;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	char		**map;
	int			map_x_len;
	int			map_y_len;
	t_vector	player_place;
	int			collect;
	void		*img1;
	void		*img2;
	void		*img3;
	void		*img4;
	void		*img5;
	int			counter;
}	t_game;

typedef struct s_check
{
	int		read;
	char	*line;
	int		len;
	int		len2;
	int		fd;
	int		i;
}			t_check;

int		ft_exit(char *message, t_game *game, int ret);
void	ft_parsing(char *argv, t_game *game);
int		ft_update(t_game *game);
int		ft_end(t_game *game);
void	ft_init_img(t_game *game);
void	ft_init_all(t_game *game);
int		ft_key(int key, t_game *game);
void	ft_draw_map(t_game *game);
int		ft_strlen_int(const char *str);
void	ft_move_up(t_game *game);
void	ft_move_left(t_game *game);
void	ft_move_down(t_game *game);
void	ft_move_right(t_game *game);
int		ft_check_is_nbr(char *str, t_game *game);
int		ft_number_of_lines(char *argv);
int		check_is_file(char *argv, t_game game);
void	ft_check_loop(t_check *check, t_game *game);
int		ft_check_play(char *str, int r, t_game *game);
int		ft_press_w(t_game *game);
int		ft_press_a(t_game *game);
int		ft_press_s(t_game *game);
int		ft_press_d(t_game *game);

#endif