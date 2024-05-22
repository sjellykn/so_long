/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjelly <sjelly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 23:44:14 by sjelly            #+#    #+#             */
/*   Updated: 2022/01/14 23:47:16 by sjelly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int ch)
{
	int		i;
	char	chr;

	chr = ch;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == chr)
			return ((char *)str + i);
		i++;
	}
	if (chr == '\0')
		return ((char *)str + i);
	else
		return (NULL);
}
