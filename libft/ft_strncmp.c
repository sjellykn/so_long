/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjelly <sjelly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 23:44:51 by sjelly            #+#    #+#             */
/*   Updated: 2022/01/14 23:47:39 by sjelly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t num)
{
	unsigned char	*s3;
	unsigned char	*s4;
	size_t			c;

	s3 = (unsigned char *)str1;
	s4 = (unsigned char *)str2;
	c = 0;
	while ((s3[c] - s4[c]) == 0 && num > c && (s3[c] != '\0' && s4[c] != '\0'))
	{
		c++;
	}
	if (c == num)
		return (0);
	return (s3[c] - s4[c]);
}
