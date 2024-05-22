/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjelly <sjelly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 23:44:39 by sjelly            #+#    #+#             */
/*   Updated: 2022/01/14 23:47:31 by sjelly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	unsigned int	i;
	size_t			a;

	i = 0;
	a = 0;
	if (src == NULL)
		return (0);
	while (src[i] != '\0')
		i++;
	if (dst == NULL)
		return (i);
	if (size == 0)
		return (i);
	while (src[a] != '\0' && a < (size - (size_t)1))
	{
		dst[a] = src[a];
		a++;
	}
	dst[a] = '\0';
	return (i);
}
