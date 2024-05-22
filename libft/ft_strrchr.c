/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjelly <sjelly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 23:45:00 by sjelly            #+#    #+#             */
/*   Updated: 2022/01/14 23:47:45 by sjelly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int ch)
{
	char	*result;
	char	chr;

	chr = ch;
	result = 0;
	while (*str != '\0')
	{
		if (*str == chr)
			result = (char *)str;
		str++;
	}
	if (chr == '\0')
		result = (char *)str;
	return (result);
}
