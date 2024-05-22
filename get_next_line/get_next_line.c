/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjelly <sjelly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 23:38:05 by sjelly            #+#    #+#             */
/*   Updated: 2022/01/14 23:38:07 by sjelly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	ft_end_reaminder(char **p, char **reaminder, char **line)
{
	char	*tmp;

	*p = ft_strchr_gnl(*reaminder, '\n');
	if (*p)
	{
		**p = '\0';
		(*p)++;
		tmp = *reaminder;
		*line = ft_strdup_gnl(*reaminder);
		*reaminder = ft_strdup_gnl(*p);
		free(tmp);
	}
}

static void	ft_free_reaminder(char **reaminder, char *buf)
{
	char	*tmp;

	tmp = *reaminder;
	*reaminder = ft_strjoin_gnl(*reaminder, buf);
	free (tmp);
}

int	ft_read(char **p, char **reaminder, char **line, int fd)
{
	char	*buf;
	int		bwr;

	bwr = 1;
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buf == NULL)
		return (-1);
	while (bwr && *p == NULL)
	{
		bwr = read(fd, buf, BUFFER_SIZE);
		if (bwr < 0)
			return (-1);
		buf[bwr] = '\0';
		if (*reaminder)
		{
			ft_free_reaminder(reaminder, buf);
		}
		else
			*reaminder = ft_strdup_gnl(buf);
		ft_end_reaminder(p, reaminder, line);
	}	
	free (buf);
	return (bwr);
}

int	get_next_line(int fd, char **line)
{
	int			bwr;
	static char	*reaminder;
	char		*p;

	bwr = 1;
	p = NULL;
	if (fd < 0 || fd > 256 || BUFFER_SIZE <= 0 || line == NULL)
		return (-1);
	if (reaminder)
		ft_end_reaminder(&p, &reaminder, line);
	if (p == NULL)
		bwr = ft_read(&p, &reaminder, line, fd);
	if (bwr == 0)
	{
		*line = ft_strdup_gnl(reaminder);
		if (reaminder)
		{
			free(reaminder);
			reaminder = NULL;
		}
		return (0);
	}
	else if (bwr == -1)
		return (-1);
	return (1);
}

int	get_next_line_new(int fd, char **line)
{
	int			bwr;
	static char	*reaminder;
	char		*p;

	bwr = 1;
	p = NULL;
	if (fd < 0 || fd > 256 || BUFFER_SIZE <= 0 || line == NULL)
		return (-1);
	if (reaminder)
		ft_end_reaminder(&p, &reaminder, line);
	if (p == NULL)
		bwr = ft_read(&p, &reaminder, line, fd);
	if (bwr == 0)
	{
		*line = ft_strdup_gnl(reaminder);
		if (reaminder)
		{
			free(reaminder);
			reaminder = NULL;
		}
		return (0);
	}
	else if (bwr == -1)
		return (fd);
	return (fd);
}
