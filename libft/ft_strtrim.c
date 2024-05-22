/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjelly <sjelly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 23:45:04 by sjelly            #+#    #+#             */
/*   Updated: 2022/01/14 23:47:53 by sjelly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	in_set(const char *s1, const char *set)
{
	int	a;

	a = 0;
	while (s1[a] != '\0')
	{
		if (ft_strchr(set, s1[a]))
			a++;
		else
			break ;
	}
	return (a);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	int		a;
	int		b;
	int		s1_size;
	int		i;
	char	*result;

	if (s1 == NULL || set == NULL)
		return (NULL);
	a = in_set(s1, set);
	b = 0;
	s1_size = ft_strlen(s1);
	if (s1_size > a)
	{
		i = s1_size - 1;
		while (i >= 0)
		{
			if (ft_strchr(set, s1[i]) == NULL)
				break ;
			b++;
			i--;
		}
	}
	result = (char *)malloc(sizeof(char) * (s1_size - a - b + 1));
	ft_strlcpy(result, &s1[a], s1_size - a - b + 1);
	return (result);
}
