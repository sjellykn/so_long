/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjelly <sjelly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 23:42:40 by sjelly            #+#    #+#             */
/*   Updated: 2022/01/14 23:46:11 by sjelly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	result;
	int	a;

	result = 0;
	a = 1;
	while (*str == ' ' || *str == '\v' || *str == '\t'
		|| *str == '\f' || *str == '\r' || *str == '\n')
		str++;
	if ((*str == '-') || (*str == '+'))
	{
		if (*str == '-')
			a = -a;
		str++;
	}
	while (*str != '\0')
	{
		if (*str < '0' || *str > '9')
			return (result * a);
		if (result * a < -2147483648 / 10)
			return (0);
		if (result > 2147483647 / 10)
			return (-1);
		result = result * 10 + *str++ - '0';
	}
	return (result * a);
}
