/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjelly <sjelly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 23:37:28 by sjelly            #+#    #+#             */
/*   Updated: 2022/01/14 23:37:53 by sjelly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3
# endif

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>

int		get_next_line(int fd, char **line);
size_t	ft_strlen_gnl(const char *str);
char	*ft_strjoin_gnl(char *s1, char const *s2);
char	*ft_strchr_gnl(const char *str, int ch);
char	*ft_strdup_gnl(const char *str);
int		get_next_line_new(int fd, char **line);

#endif
