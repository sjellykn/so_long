/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjelly <sjelly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 23:44:10 by sjelly            #+#    #+#             */
/*   Updated: 2022/01/14 23:47:13 by sjelly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_separators(char *s_t, char c)
{
	int	c_cnt;
	int	i;

	c_cnt = 0;
	i = 0;
	while (s_t[i] != '\0')
	{
		if (s_t[i] == c && s_t[i] != s_t[i + 1])
			c_cnt++;
		i++;
	}
	return (c_cnt);
}

static void	ft_free_result(char **result)
{
	int		j;

	j = 0;
	while (result[j] != NULL)
	{
		free(result[j]);
		j++;
	}
	free(result);
}

static int	ft_find_substrings(char *s_t, char **result, char c)
{
	int		start;
	int		len;
	int		i;

	start = 0;
	i = 0;
	while (s_t[start] != '\0')
	{
		len = 0;
		while (s_t[start + len] != c && s_t[start + len] != '\0')
			len++;
		if (len == 0)
		{
			start++;
			continue ;
		}
		result[i] = (char *)malloc(sizeof(char) * (len + 1));
		if (result[i] == NULL)
			return (0);
		ft_strlcpy(result[i], &s_t[start], len + 1);
		i++;
		start += len;
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	*s_t;
	int		c_cnt;
	char	**result;
	char	str[2];

	str[0] = c;
	str[1] = '\0';
	s_t = ft_strtrim(s, str);
	if (s_t == NULL)
		return (NULL);
	c_cnt = ft_count_separators(s_t, c);
	result = (char **)malloc(sizeof(char *) * (c_cnt + 2));
	if (result != NULL)
	{
		result[c_cnt] = NULL;
		result[c_cnt + 1] = NULL;
		if (ft_find_substrings(s_t, result, c) == 0)
		{
			ft_free_result(result);
			result = NULL;
		}
	}
	free(s_t);
	return (result);
}
