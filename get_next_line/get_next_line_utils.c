/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjelly <sjelly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 23:38:16 by sjelly            #+#    #+#             */
/*   Updated: 2022/01/14 23:38:56 by sjelly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen_gnl(const char *str)
{
	size_t	i;

	i = 0;
	while (str && str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin_gnl(char *s1, char const *s2)
{
	unsigned int	i;
	char			*str;

	i = 0;
	str = (char *)malloc((sizeof(*str))
			* (ft_strlen_gnl(s1) + 1 + ft_strlen_gnl(s2)));
	if (str == NULL)
		return (NULL);
	while (s1 && *s1 != '\0')
	{
		str[i] = *s1;
		i++;
		s1++;
	}
	while (*s2 != '\0')
	{
		str[i] = *s2;
		i++;
		s2++;
	}	
	str[i] = '\0';
	return (str);
}

char	*ft_strchr_gnl(const char *str, int ch)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ch)
			return ((char *)str + i);
		i++;
	}
	if (ch == '\0')
		return ((char *)str + i);
	else
		return (NULL);
}

char	*ft_strdup_gnl(const char *str)
{
	char	*str1;
	int		i;
	int		a;

	i = 0;
	a = 0;
	while (str && str[i] != '\0')
		i++;
	str1 = (char *)malloc(sizeof(*str1) * (i + 1));
	if (!str1)
		return (NULL);
	while (a < i && str)
	{
		str1[a] = str[a];
		a++;
	}
	str1[a] = '\0';
	return (str1);
}
