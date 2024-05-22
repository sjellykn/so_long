/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjelly <sjelly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 23:44:26 by sjelly            #+#    #+#             */
/*   Updated: 2022/01/14 23:47:21 by sjelly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*str1;
	int		i;
	int		a;

	i = 0;
	a = 0;
	while (str[i] != '\0')
		i++;
	str1 = (char *)malloc(sizeof(*str1) * (i + 1));
	if (!str1)
		return (NULL);
	while (a < i)
	{
		str1[a] = str[a];
		a++;
	}
	str1[a] = '\0';
	return (str1);
}
